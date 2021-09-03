#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

struct AnimationFrame
{
	QPixmap *pixmap;
	int time;
	AnimationFrame() : pixmap(nullptr), time(0) {}
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
