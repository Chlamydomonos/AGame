#ifndef GRAPHIC__SPRITE_H
#define GRAPHIC__SPRITE_H

#include <QGraphicsItem>
#include "../util/ItemWithPrototype.h"

#include "SpritePrototype.h"

#include "MoveAnimation.h"

#include <QMap>

class Sprite : public QGraphicsPixmapItem, public ItemWithPrototype<Sprite, SpritePrototype>
{
private:
	friend class SpritePrototype;
	friend class MoveAnimation;
	friend class Animation;

	Animation *currentAnimation;
	Animation *defaultAnimation;
	MoveAnimation *moveAnimation;

	QVariantMap dataMap;

	Sprite(const SpritePrototype *prototype);

	void defaultHoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void defaultHoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	void defaultMousePressEvent(QGraphicsSceneMouseEvent *event) { event->ignore(); }
	void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent *event) { event->ignore(); }
public:
	~Sprite();
	bool inAnimation();
	const QString &currentAnimationName();
	bool moving();
	void moveTo(const QPointF & position, int duration);
	void moveTo(const QPointF & position, double speed);
	void stopMove();
	void startAnimation(const QString &animationName);
	void stopAnimation();
	QVariantMap &getDataMap() { return dataMap; }

	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override final { prototype->hoverEnterEvent(this, event); }
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override final { prototype->hoverLeaveEvent(this, event); }
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override final { prototype->mousePressEvent(this, event); }
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override final { prototype->mouseReleaseEvent(this, event); }
};

#endif // !GRAPHIC__SPRITE_H
