#ifndef GRAPHIC__SPRITE_PROTOTYPE_H
#define GRAPHIC__SPRITE_PROTOTYPE_H

#include "Sprite.h"
#include "AnimationFrameGroupPrototype.h"

#include <QMap>
#include <QString>

class SpritePrototype
{
private:
	QMap<QString, QPixmap> pixmaps;
	QMap<QString, AnimationFrameGroupPrototype> animationFrameGroupPrototypes;
	QSize defaultSize;
	int defaultZOrder;
	AnimationFrameLoop *defaultLoop;
	friend class Sprite;
public:
	SpritePrototype(QSize _defaultSize, int _defaultZOrder = 0):
		defaultSize(_defaultSize), defaultZOrder(_defaultZOrder), defaultLoop(nullptr) {}

	virtual ~SpritePrototype();

	void loadPixmap(const QString &name, const QString &fileName);
	void loadPixmapFromPrototype(const QString &name, SpritePrototype *prototype, const QString &pixmapName);

	bool hasPixmap(const QString &name);
	QPixmap getPixmap(const QString &name);

	void createAnimationFrameGroupPrototype(const QString &name, const QVector<AnimationFrame> &frames);
	bool hasAnimationFrameGroupPrototype(const QString &name);

	void setDefaultAnimationFrameLoop(const QString &name);

	Sprite *createSprite(QSize size, int zOrder, QPoint position = { 0, 0 }, Sprite *parent = nullptr)
	{
		return new Sprite(this, size, zOrder, position, parent);
	}

	Sprite *createSprite(QSize size, QPoint position = { 0, 0 }, Sprite *parent = nullptr)
	{
		return new Sprite(this, size, defaultZOrder, position, parent);
	}

	Sprite *createSprite(QPoint position = { 0, 0 }, Sprite *parent = nullptr)
	{
		return new Sprite(this, defaultSize, defaultZOrder, position, parent);
	}

	virtual bool onMouseHoverStart(Sprite *sprite, bool leftButtonPressed, bool rightButtonPressed) { return false; }
	virtual bool onMouseHoverEnd(Sprite *sprite, bool leftButtonPressed, bool rightButtonPressed) { return false; }
	virtual bool onMouseButtonPressed(Sprite *sprite, bool isLeft) { return false; }
	virtual bool onMouseButtonReleased(Sprite *sprite, bool isLeft) { return false; }
};

#endif // !GRAPHIC__SPRITE_PROTOTYPE_H
