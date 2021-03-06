#include "SpritePrototype.h"
#include "Sprite.h"

void SpritePrototype::loadPixmap(const QString & name, const QString & fileName)
{
	if (pixmaps.contains(name))
		return;
	QPixmap map(fileName);
	pixmaps.insert(name, map);
}

AnimationFrame SpritePrototype::createAnimationFrame(const QString &pixmapName, int time)
{
	if(!pixmaps.contains(pixmapName))
		return AnimationFrame();
	return AnimationFrame(pixmaps[pixmapName], time);
}

void SpritePrototype::createAnimation(const QString &name, const QVector<AnimationFrame> &frames, int loopCount)
{
	if (animations.contains(name))
		return;
	AnimationPrototype prototype(frames, loopCount);
	prototype.name = name;
	animations.insert(name, prototype);
}

void SpritePrototype::setDefaultAnimation(const QString &name)
{
	if (!animations.contains(name))
		return;
	defaultAnimation = &(animations[name]);
	assert(defaultAnimation->getLoopCount() == -1);
}

void SpritePrototype::hoverEnterEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const { sprite->defaultHoverEnterEvent(event); }

void SpritePrototype::hoverLeaveEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const { sprite->defaultHoverLeaveEvent(event); }

void SpritePrototype::mousePressEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const { sprite->defaultMousePressEvent(event); }

void SpritePrototype::mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const { sprite->defaultMouseReleaseEvent(event); }

Sprite *SpritePrototype::create() const
{
	assert(defaultAnimation != nullptr);
	Sprite *sprite = new Sprite(this);
	sprite->setZValue(defaultZValue);
	sprite->setOffset(offset);
	sprite->setAcceptHoverEvents(true);
	return sprite;
}
