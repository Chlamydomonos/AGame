#ifndef GRAPHIC__ANIMATION_PROTOTYPE_H
#define GRAPHIC__ANIMATION_PROTOTYPE_H

#include "../util/Prototype.h"

#include "AnimationFrame.h"
#include <QVector>

class Animation;

class AnimationPrototype : public QVector<AnimationFrame>, public Prototype<Animation>
{
private:
	friend class Animation;
	friend class SpritePrototype;
	const int loopCount;
	int duration;
	QString name;
	void calculateDuration();
public:
	AnimationPrototype() : loopCount(0), duration(0) {}
	AnimationPrototype(const QVector<AnimationFrame> &frames, int _loopCount);
	AnimationPrototype(const AnimationPrototype &obj);

	virtual Animation *create() const override final;

	int getLoopCount() const { return loopCount; }

	AnimationPrototype operator=(const AnimationPrototype &other) { return other; }
};

#endif // !GRAPHIC__ANIMATION_PROTOTYPE_H
