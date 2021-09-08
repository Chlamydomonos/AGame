#ifndef GRAPHIC__MOVE_ANIMATION_H
#define GRAPHIC__MOVE_ANIMATION_H

#include <QAbstractAnimation>
#include <QPointF>

class Sprite;

class MoveAnimation : public QAbstractAnimation
{
	Q_OBJECT
private:
	const QPointF from;
	const QPointF to;
	const int _duration;
    Sprite *sprite;
private slots:
	void removeSelf();
public:
	MoveAnimation(const QPointF &_from, const QPointF &_to, int __duration, Sprite *_sprite);
	virtual int duration() const override final { return _duration; }
	virtual void updateCurrentTime(int currentTime) override final;
};

#endif // !GRAPHIC__MOVE_ANIMATION_H
