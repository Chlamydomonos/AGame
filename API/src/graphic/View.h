#ifndef GRAPHIC__VIEW_H
#define GRAPHIC__VIEW_H

#include <QGraphicsView>

class View : public QGraphicsView
{
private:
	enum DirectionKey
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	bool directionKeyPressed[4];
	int updateSightTimer;
	int scrollSensitivity;
public:
	View(QWidget *parent);

	int getScrollSensitivity() const { return scrollSensitivity; }
	void setScrollSensitivity(int scrollSensitivity) { this->scrollSensitivity = scrollSensitivity; }

	virtual void keyPressEvent(QKeyEvent *event) override final;
	virtual void keyReleaseEvent(QKeyEvent *event) override final;
	virtual void timerEvent(QTimerEvent *event) override final;
};

#endif // !GRAPHIC__VIEW_H
