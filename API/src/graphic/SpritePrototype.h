#ifndef GRAPHIC__SPRITE_PROTOTYPE_H
#define GRAPHIC__SPRITE_PROTOTYPE_H

#include "AnimationFrame.h"

#include <QObject>
#include <QMap>
#include <QPixmap>
#include <QString>
#include <QVector>
#include <QSize>

class BaseSpritePrototype
{
private:
	QMap<QString, QPixmap *> pixmaps;
	QMap<QString, QVector<AnimationFrame>> animationFrameGroups;
	QVector<AnimationFrame> *defaultAnimationFrameGroup;
	QSize defaultSize;
	friend class Sprite;
protected:
	BaseSpritePrototype(const QSize &_defaultSize) :
		pixmaps(), animationFrameGroups(),
		defaultAnimationFrameGroup(nullptr),
		defaultSize(_defaultSize) {}

	~BaseSpritePrototype();

	bool hasPixmap(const QString &name);
	bool hasAnimationFrameGroup(const QString &name);

	void loadPixmap(const QString &name, const QString &fileName);
	AnimationFrame createAnimationFrame(const QString &pixmapName, int time);
	void createAnimationFrameGroup(const QString &name, const QVector<AnimationFrame> &animationFrames);
	void setDefaultAnimationFrameGroup(const QString &name);

	virtual void onBaseSpriteHover(Sprite *sprite) = 0;
	virtual void onBaseSpriteClicked(Sprite *sprite) = 0;

};

template<class T>
class SpritePrototype : public BaseSpritePrototype
{
public:
	SpritePrototype(const QSize &defaultSize) : BaseSpritePrototype(defaultSize)
	{
		static_assert(std::is_convertible<T *, Sprite *>, "Cannot create sprite prototype without a sprite class");
	}

	virtual void onSpriteHover(T *sprite) {}
	virtual void onSpriteClicked(T *sprite) {}
	virtual void onBaseSpriteHover(Sprite *sprite) override final
	{
		onSpriteHover(static_cast<T *>(sprite));
	}
	virtual void onBaseSpriteClicked(Sprite *sprite) override final
	{
		onSpriteClicked(static_cast<T *>(sprite));
	}
};

#endif // !GRAPHIC__SPRITE_PROTOTYPE_H
