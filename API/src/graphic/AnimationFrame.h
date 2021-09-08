#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

class AnimationFrame
{
private:
	const QPixmap pixmap;
	const int time;
public:
	AnimationFrame() : pixmap(), time() {}
	AnimationFrame(const QPixmap &_pixmap, int _time = 16) : pixmap(_pixmap), time(_time) {}
	AnimationFrame(const AnimationFrame &obj) : pixmap(obj.pixmap), time(obj.time) {}
	const QPixmap &getPixmap() const { return pixmap; }
	int getTime() const { return time; }
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
