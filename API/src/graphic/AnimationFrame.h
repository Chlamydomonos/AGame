#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

struct AnimationFrame
{
	int time;
	QPixmap *pixmap;
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
