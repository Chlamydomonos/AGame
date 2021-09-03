#ifndef GRAPHIC__SPRITE_H
#define GRAPHIC__SPRITE_H

#include "SpritePrototype.h"

#include <QPoint>
#include <QSize>
#include <QQueue>

class Sprite
{
private:
	int defaultAnimationFrameIndex;
protected:
	QPoint position;
	QSize size;
	SpritePrototype *prototype;
	QQueue<AnimationFrame> animationFrames;
public:
	Sprite(SpritePrototype *_prototype, QSize _size = {0, 0}, QPoint _position = { 0, 0 }):
		prototype(_prototype), size(_size), position(_position), 
		animationFrames(), defaultAnimationFrameIndex(0){}
};

#endif // !GRAPHIC__SPRITE_H
