#include "AnimationPrototype.h"
#include "Animation.h"
#include "Sprite.h"


void Animation::removeSelf()
{
    sprite->currentAnimation = sprite->defaultAnimation;
}

Animation::Animation(const AnimationPrototype *prototype) :
    ItemWithPrototype<Animation, AnimationPrototype>(prototype),
    currentIndex(0), prevIndexesTime(0), sprite(nullptr)
{
    connect(this, SIGNAL(finished()), this, SLOT(removeSelf()));
}

int Animation::duration() const
{
    return prototype->duration;
}

void Animation::updateCurrentTime(int currentTime)
{
    currentTime %= duration();

    if (currentTime >= prevIndexesTime)
    {
        for (int i = currentIndex;; i++)
        {
            int temp = prevIndexesTime + prototype->at(i).getTime();
            if (temp > currentTime)
            {
                currentIndex = i;
                sprite->setPixmap(getPixmap());
                return;
            }
            else
                prevIndexesTime = temp;
        }
    }
    else
    {
        currentIndex = 0;
        prevIndexesTime = 0;
        updateCurrentTime(currentTime);
    }
}

const QPixmap &Animation::getPixmap()
{
    return prototype->at(currentIndex).getPixmap();
}

