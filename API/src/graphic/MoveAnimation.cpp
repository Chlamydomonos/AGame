#include "MoveAnimation.h"
#include "Sprite.h"

void MoveAnimation::removeSelf()
{
	sprite->moveAnimation = nullptr;
}

MoveAnimation::MoveAnimation(const QPointF &_from, const QPointF &_to, int __duration, Sprite *_sprite) :
	from(_from), to(_to), _duration(__duration), sprite(_sprite)
{
	connect(this, SIGNAL(finished()), this, SLOT(removeSelf()));
}

void MoveAnimation::updateCurrentTime(int currentTime)
{
	if (state() == State::Running)
	{
		if (currentTime == 0 || currentTime % duration() != 0)
		{
			currentTime %= duration();
			double rate = (double)currentTime / (double)duration();
			double x = from.x() * (1 - rate) + to.x() * rate;
			double y = from.y() * (1 - rate) + to.y() * rate;
			sprite->setPos(x, y);
		}
		else
			sprite->setPos(to);
	}
}
