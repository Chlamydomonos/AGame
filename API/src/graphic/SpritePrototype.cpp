#include "SpritePrototype.h"

SpritePrototype::~SpritePrototype()
{
    delete defaultLoop;
}

void SpritePrototype::loadPixmap(const QString &name, const QString &fileName)
{
    if (pixmaps.contains(name))
        return;
    QPixmap temp(fileName);
    pixmaps.insert(name, temp);
}

void SpritePrototype::loadPixmapFromPrototype(const QString &name, SpritePrototype *prototype, const QString &pixmapName)
{
    if (pixmaps.contains(name))
        return;
    if (!prototype->pixmaps.contains(pixmapName))
        return;
    pixmaps.insert(name, prototype->pixmaps[pixmapName]);
}

bool SpritePrototype::hasPixmap(const QString &name)
{
    return pixmaps.contains(name);
}

QPixmap SpritePrototype::getPixmap(const QString &name)
{
    return pixmaps[name];
}

void SpritePrototype::createAnimationFrameGroupPrototype(const QString &name, const QVector<AnimationFrame> &frames)
{
    if (animationFrameGroupPrototypes.contains(name))
        return;
    animationFrameGroupPrototypes.insert(name, AnimationFrameGroupPrototype(frames, name));
}

bool SpritePrototype::hasAnimationFrameGroupPrototype(const QString &name)
{
    return animationFrameGroupPrototypes.contains(name);
}

void SpritePrototype::setDefaultAnimationFrameLoop(const QString &name)
{
    if (!animationFrameGroupPrototypes.contains(name))
        return;
    if (defaultLoop != nullptr)
    {
        delete defaultLoop;
        defaultLoop = nullptr;
    }
    defaultLoop = animationFrameGroupPrototypes[name].createLoop();
}
