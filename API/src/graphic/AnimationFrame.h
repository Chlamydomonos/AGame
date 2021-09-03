#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

struct AnimationFrame
{
	QPixmap *pixmap;
	int time;
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
