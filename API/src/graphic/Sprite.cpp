#include "Sprite.h"
#include "SpritePrototype.h"

Sprite::Sprite(SpritePrototype *_prototype, QSize _size, int _zOrder, QPoint _position, Sprite *_parent, bool _visible) :
	prototype(_prototype), size(_size), zOrder(_zOrder), position(_position),
	parent(_parent), animationFrameGroups(), actualPosition(), visible(_visible),
	time(0), currentFrame(), children()
{
	assert(parent == nullptr || parent->zOrder == this->zOrder);
	if(parent != nullptr)
		parent->children.insert(this);
}

Sprite::~Sprite()
{
	if (parent == nullptr)
	{
		for (auto i : children)
			delete i;
	}
	else
	{
		for (auto i : children)
		{
			i->setParent(parent);
		}
	}
}

void Sprite::render(QPainter *painter)
{
	time++;
	if (time == currentFrame.getTime())
	{
		time = 0;

		if (animationFrameGroups.isEmpty())
			currentFrame = prototype->defaultLoop->nextFrame();
		else
		{
			currentFrame = animationFrameGroups.head()->nextFrame();
			if (animationFrameGroups.head()->size() == 0)
				delete animationFrameGroups.dequeue();
		}
	}
	for (auto i : children)
		i->render(painter);
	if(visible)
		painter->drawPixmap(QRect(actualPosition, size), currentFrame.getPixmap());
}

bool Sprite::onMouseHoverStart(bool leftButtonPressed, bool rightButtonPressed)
{
	return prototype->onMouseHoverStart(this, leftButtonPressed, rightButtonPressed);
}

bool Sprite::onMouseHoverEnd(bool leftButtonPressed, bool rightButtonPressed)
{
	return prototype->onMouseHoverEnd(this, leftButtonPressed, rightButtonPressed);
}

bool Sprite::onMouseButtonPressed(bool isLeft)
{
	return prototype->onMouseButtonPressed(this, isLeft);
}

bool Sprite::onMouseButtonReleased(bool isLeft)
{
	return prototype->onMouseButtonReleased(this, isLeft);
}

void Sprite::setParent(Sprite *parent)
{
	assert(parent == nullptr || parent->zOrder == this->zOrder);
	if(this->parent != nullptr)
		this->parent->children.remove(this);

	this->parent = parent;

	if(parent != nullptr)
		parent->children.insert(this);
}

void Sprite::enqueueAnimationFrameGroup(const QString &name, bool isLoop)
{
	if (!prototype->hasAnimationFrameGroupPrototype(name))
		return;
	if (isLoop)
		animationFrameGroups.enqueue(prototype->animationFrameGroupPrototypes[name].createLoop());
	else
		animationFrameGroups.enqueue(prototype->animationFrameGroupPrototypes[name].createSequence());
}

void Sprite::enqueueAnimationFrameGroup(AnimationFrameGroupInfo info)
{
	enqueueAnimationFrameGroup(info.name, info.isLoop);
}

void Sprite::dequeueAnimationFrameGroup()
{
	delete animationFrameGroups.dequeue();
}

Sprite::AnimationFrameGroupInfo Sprite::lastAnimationFrameGroup()
{
	if(animationFrameGroups.isEmpty())
		return { "", false };
	return { animationFrameGroups.head()->getName(), dynamic_cast<AnimationFrameLoop *>(animationFrameGroups.head()) != nullptr };
}
