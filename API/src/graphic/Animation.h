#ifndef GRAPHIC__ANIMATION_H
#define GRAPHIC__ANIMATION_H

#include <QAbstractAnimation>
#include "../util/ItemWithPrototype.h"

#include "AnimationFrame.h"
#include "AnimationPrototype.h"

class Sprite;

class AnimationPrototype;

class Animation : public QAbstractAnimation, public ItemWithPrototype<Animation, AnimationPrototype>
{
	Q_OBJECT
private:
	friend class AnimationPrototype;

	int currentIndex;
	int prevIndexesTime;

	Sprite *sprite;

	Animation(const AnimationPrototype *prototype);
private slots:
	void removeSelf();
public:
	virtual int duration() const override final;
	virtual void updateCurrentTime(int currentTime) override final;
	const QPixmap &getPixmap();
	void bindSprite(Sprite *sprite) { this->sprite = sprite; }
	const QString &getName() { return prototype->name; }
};

#endif // !GRAPHIC__ANIMATION_H
