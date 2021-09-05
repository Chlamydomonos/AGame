#ifndef GRAPHIC__ANIMATION_FRAME_GROUP_H
#define GRAPHIC__ANIMATION_FRAME_GROUP_H

#include "AnimationFrame.h"

class AnimationFrameGroupPrototype;

class AnimationFrameGroup
{
public:
	virtual AnimationFrame nextFrame() = 0;
	virtual int size() = 0;
	virtual const QString &getName() = 0;
};

class AnimationFrameSequence : public AnimationFrameGroup
{
private:
	friend class AnimationFrameGroupPrototype;
	AnimationFrameGroupPrototype *prototype;
	int index;
	AnimationFrameSequence(AnimationFrameGroupPrototype *_prototype) : prototype(_prototype), index(0) {}
public:
	AnimationFrameSequence(const AnimationFrameSequence &obj) : prototype(obj.prototype), index(obj.index) {}
	virtual AnimationFrame nextFrame() override final;
	virtual int size() override final;
	virtual const QString &getName() override final;
};

class AnimationFrameLoop : public AnimationFrameGroup
{
private:
	friend class AnimationFrameGroupPrototype;
	AnimationFrameGroupPrototype *prototype;
	int index;
	AnimationFrameLoop(AnimationFrameGroupPrototype *_prototype) : prototype(_prototype), index(0) {}
public:
	AnimationFrameLoop(const AnimationFrameLoop &obj) : prototype(obj.prototype), index(obj.index) {}
	virtual AnimationFrame nextFrame() override final;
	virtual int size() override final;
	virtual const QString &getName() override final;
};

#endif // !GRAPHIC__ANIMATION_FRAME_GROUP_H
