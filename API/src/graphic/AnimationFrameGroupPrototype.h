#ifndef GRAPHIC__ANIMATION_FRAME_GROUP_PROTOTYPE_H
#define GRAPHIC__ANIMATION_FRAME_GROUP_PROTOTYPE_H

#include "AnimationFrameGroup.h"

#include <QVector>

class AnimationFrameGroupPrototype : public QVector<AnimationFrame>
{
private:
	const QString name;
public:
	AnimationFrameGroupPrototype() : QVector<AnimationFrame>(), name()
	{
		assert(false);
	}
	AnimationFrameGroupPrototype(const QVector<AnimationFrame> &frames, const QString &_name) : QVector<AnimationFrame>(frames), name(_name)
	{
		assert(!frames.isEmpty());
	}
	AnimationFrameGroupPrototype(const AnimationFrameGroupPrototype &obj) : QVector<AnimationFrame>(obj), name(obj.name)
	{
		assert(!obj.isEmpty());
	}

	AnimationFrameGroupPrototype operator=(const AnimationFrameGroupPrototype &obj) { return AnimationFrameGroupPrototype(obj); }

	AnimationFrameSequence *createSequence() { return new AnimationFrameSequence(this); }
	AnimationFrameLoop *createLoop() { return new AnimationFrameLoop(this); }

	const QString &getName() const { return name; }
};

#endif // !GRAPHIC__ANIMATION_FRAME_GROUP_PROTOTYPE_H
