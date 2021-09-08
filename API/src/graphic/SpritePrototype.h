#ifndef GRAPHIC__SPRITE_PROTOTYPE_H
#define GRAPHIC__SPRITE_PROTOTYPE_H

#include <QMap>
#include <QString>
#include <QPixmap>
#include "AnimationPrototype.h"
#include "Animation.h"

class Sprite;

class SpritePrototype : public Prototype<Sprite>
{
private:
	friend class Sprite;
	QMap<QString, QPixmap> pixmaps;
	QMap<QString, AnimationPrototype> animations;
	AnimationPrototype *defaultAnimation;
	QSize spriteSize;
	double defaultZValue;
	QPointF offset;
protected:
	SpritePrototype(const QSize &size, double _defaultZValue, const QPointF &_offset):
		spriteSize(size), defaultZValue(_defaultZValue), offset(_offset),
		pixmaps(), animations(), defaultAnimation(nullptr) {}
	void loadPixmap(const QString & name, const QString & fileName);
	AnimationFrame createAnimationFrame(const QString &pixmapName, int time = 16);
	void createAnimation(const QString &name, const QVector<AnimationFrame> &frames, int loopCount);
	void setDefaultAnimation(const QString &name);

	virtual void hoverEnterEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const { sprite->QGraphicsPixmapItem::hoverEnterEvent(event); }
	virtual void hoverLeaveEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const { sprite->QGraphicsPixmapItem::hoverLeaveEvent(event); }
	virtual void mousePressEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const { sprite->QGraphicsPixmapItem::mousePressEvent(event); }
	virtual void mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const { sprite->QGraphicsPixmapItem::mouseReleaseEvent(event); }

public:
	virtual Sprite *create() const override final;
};

#endif // !GRAPHIC__SPRITE_PROTOTYPE_H
