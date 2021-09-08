#include "AnimationPrototype.h"
#include "Animation.h"

void AnimationPrototype::calculateDuration()
{
	duration = 0;
	for (int i = 0; i < length(); i++)
		duration += (*this)[i].getTime();
}

AnimationPrototype::AnimationPrototype(const QVector<AnimationFrame> &frames, int _loopCount) : QVector<AnimationFrame>(frames), loopCount(_loopCount)
{
	calculateDuration();
}

AnimationPrototype::AnimationPrototype(const AnimationPrototype &obj) : QVector<AnimationFrame>(obj), loopCount(obj.loopCount)
{
	calculateDuration();
}

Animation *AnimationPrototype::create() const
{
	auto out = new Animation(this);
	out->setLoopCount(this->loopCount);

	return out;
}
