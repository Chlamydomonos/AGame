#ifndef GRAPHIC__SPRITE_H
#define GRAPHIC__SPRITE_H

#include "SpritePrototype.h"

#include <QPoint>
#include <QQueue>
#include <QPainter>

class Sprite
{
private:
	int defaultAnimationFrameIndex;
	int time;
	BaseSpritePrototype *prototype;
protected:
	QPoint position;
	QSize size;
	QQueue<AnimationFrame> animationFrames;

	void addAnimationFrames(const QString &animationFrameGroupName);
	void clearAnimationFrames();
public:
	Sprite(BaseSpritePrototype *_prototype, QSize _size, QPoint _position = { 0, 0 }):
		prototype(_prototype), size(_size), position(_position), 
		animationFrames(), defaultAnimationFrameIndex(0), time(0){}

	Sprite(BaseSpritePrototype *_prototype, QPoint _position = { 0, 0 }) :
		prototype(_prototype), size(), position(_position),
		animationFrames(), defaultAnimationFrameIndex(0), time(0)
	{
		size = prototype->defaultSize;
	}

	virtual void render(QPainter painter);
};

#endif // !GRAPHIC__SPRITE_H
