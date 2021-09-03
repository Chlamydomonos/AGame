#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

class AnimationFrame
{
public:
	QPixmap *pixmap;
	int time;
	AnimationFrame() : pixmap(nullptr), time(0) {}
	AnimationFrame(QPixmap *_pixmap, int _time) : pixmap(_pixmap), time(_time) {}
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
