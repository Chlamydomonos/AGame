#ifndef GRAPHIC__SPRITE_PROTOTYPE_H
#define GRAPHIC__SPRITE_PROTOTYPE_H

#include "AnimationFrame.h"

#include <QObject>
#include <QMap>
#include <QPixmap>
#include <QString>
#include <QVector>

class SpritePrototype
{
private:
	QMap<QString, QPixmap> pixmaps;
	QVector<AnimationFrame> defaultAnimationFrames;
public:
	SpritePrototype() : pixmaps(), defaultAnimationFrames() {}
};

#endif // !GRAPHIC__SPRITE_PROTOTYPE_H
