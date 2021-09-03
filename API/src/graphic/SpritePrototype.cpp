#include "SpritePrototype.h"

BaseSpritePrototype::~BaseSpritePrototype()
{
    for (auto i : pixmaps)
        delete i;
}

bool BaseSpritePrototype::hasPixmap(const QString &name)
{
    return pixmaps.contains(name);
}

bool BaseSpritePrototype::hasAnimationFrameGroup(const QString &name)
{
    return animationFrameGroups.contains(name);
}

void BaseSpritePrototype::loadPixmap(const QString &name, const QString &fileName)
{
    if (hasPixmap(name))
        return;

    QPixmap *temp = new QPixmap(fileName);
    if(temp->size() == defaultSize)
        pixmaps.insert(name, temp);
    else
    {
        QPixmap *temp2 = new QPixmap(temp->scaled(defaultSize));
        delete temp;
        pixmaps.insert(name, temp2);
    }
}

AnimationFrame BaseSpritePrototype::createAnimationFrame(const QString &pixmapName, int time)
{
    if (!hasPixmap(pixmapName))
        return { nullptr, time };
    return { pixmaps[pixmapName], time };
}

void BaseSpritePrototype::createAnimationFrameGroup(const QString &name, const QVector<AnimationFrame> &animationFrames)
{
    if (hasAnimationFrameGroup(name))
        return;

    animationFrameGroups.insert(name, animationFrames);
}

void BaseSpritePrototype::setDefaultAnimationFrameGroup(const QString &name)
{
    if (!hasAnimationFrameGroup(name))
        defaultAnimationFrameGroup = nullptr;
    defaultAnimationFrameGroup = &(animationFrameGroups[name]);
}
