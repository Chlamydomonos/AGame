#include "Sprite.h"

void Sprite::addAnimationFrames(const QString &animationFrameGroupName)
{
	if (!prototype->hasAnimationFrameGroup(animationFrameGroupName))
		return;
	auto animationFrameGroup = prototype->animationFrameGroups[animationFrameGroupName];
	for (int i = 0; i < animationFrameGroup.size(); i++)
		animationFrames.enqueue(animationFrameGroup[i]);
}

void Sprite::clearAnimationFrames()
{
	animationFrames.clear();
}

void Sprite::render(QPainter painter)
{
	AnimationFrame currentFrame;
	time++;
	if (animationFrames.size())
	{
		currentFrame = animationFrames.head();
		if (time == currentFrame.time)
		{
			time = 0;
			animationFrames.dequeue();
		}
	}
	else
	{
		auto &group = *(prototype->defaultAnimationFrameGroup);
		currentFrame = group[defaultAnimationFrameIndex];
		if (time == currentFrame.time)
		{
			time = 0;
			defaultAnimationFrameIndex++;
			if (defaultAnimationFrameIndex == group.size())
				defaultAnimationFrameIndex = 0;
		}
	}
	painter.drawPixmap(QRect(position, size), *(currentFrame.pixmap));
}
