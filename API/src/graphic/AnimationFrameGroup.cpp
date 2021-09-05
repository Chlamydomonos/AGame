#include "AnimationFrameGroup.h"

#include "AnimationFrameGroupPrototype.h"

AnimationFrame AnimationFrameSequence::nextFrame()
{
    const AnimationFrame &frame = prototype->at(index);
    index++;
    return frame;
}

int AnimationFrameSequence::size()
{
    return prototype->size() - index;
}

const QString &AnimationFrameSequence::getName()
{
    return prototype->getName();
}

AnimationFrame AnimationFrameLoop::nextFrame()
{
    const AnimationFrame &frame = prototype->at(index);
    index++;
    if (index == prototype->size())
        index = 0;
    return frame;
}

int AnimationFrameLoop::size()
{
    return prototype->size();
}

const QString &AnimationFrameLoop::getName()
{
    return prototype->getName();
}
