#ifndef GRAPHIC__ANIMATION_FRAME_H
#define GRAPHIC__ANIMATION_FRAME_H

#include <QPixmap>

class AnimationFrame
{
private:
	QPixmap pixmap;
	int time;
public:
	AnimationFrame(const QPixmap _pixmap = {}, int _time = 1) : pixmap(_pixmap), time(_time)
	{
		assert(time >= 1);
	}

	AnimationFrame(const AnimationFrame &obj) : pixmap(obj.pixmap), time(obj.time)
	{
		assert(time >= 1);
	}

	QPixmap getPixmap() const { return pixmap; }
	int getTime() const { return time; }

	void setPixmap(QPixmap pixmap) { this->pixmap = pixmap; }
	void setTime(int time)
	{
		assert(time >= 1);
		this->time = time;
	}
};

#endif // !GRAPHIC__ANIMATION_FRAME_H
