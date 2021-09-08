#include "Sprite.h"
#include "SpritePrototype.h"

#include <math.h>

Sprite::Sprite(const SpritePrototype *prototype) : ItemWithPrototype<Sprite, SpritePrototype>(prototype), moveAnimation(nullptr)
{
	defaultAnimation = prototype->defaultAnimation->create();
	defaultAnimation->bindSprite(this);
	currentAnimation = defaultAnimation;
	currentAnimation->start();
}

Sprite::~Sprite()
{
	delete defaultAnimation;
}

bool Sprite::inAnimation()
{
	return currentAnimation != defaultAnimation;
}

const QString &Sprite::currentAnimationName()
{
	return currentAnimation->getName();
}

bool Sprite::moving()
{
	return moveAnimation;
}

void Sprite::moveTo(const QPoint &position, int duration)
{
	moveAnimation = new MoveAnimation(pos(), position, duration, this);
	moveAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Sprite::moveTo(const QPoint &position, double speed)
{
	double xDistance = pos().x() - position.x();
	double yDistance = pos().y() - position.y();
	double distance = sqrt(xDistance * xDistance + yDistance * yDistance);
	int time = distance / speed;
	if (time <= 0)
		time = 1;
	moveTo(position, time);
}

void Sprite::stopMove()
{
	moveAnimation->stop();
	delete moveAnimation;
	moveAnimation = nullptr;
}

void Sprite::startAnimation(const QString &animationName)
{
	if (!prototype->animations.contains(animationName))
		return;

	stopAnimation();
	defaultAnimation->stop();

	currentAnimation = prototype->animations[animationName].create();
	currentAnimation->bindSprite(this);
	currentAnimation->start();
}

void Sprite::stopAnimation()
{
	if (currentAnimation == defaultAnimation)
		return;
	delete currentAnimation;
	currentAnimation = defaultAnimation;
	defaultAnimation->start();
}
