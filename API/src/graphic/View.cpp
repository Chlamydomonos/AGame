#include "View.h"
#include <QKeyEvent>
#include <Qdebug>

View::View(QWidget *parent = nullptr) : QGraphicsView(parent), directionKeyPressed(), scrollSensitivity(5)
{
	setSceneRect({ {0, 0}, size() });
	for (int i = 0; i < 4; i++)
	{
		directionKeyPressed[i] = false;
	}
	updateSightTimer = startTimer(16);
}

void View::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
		directionKeyPressed[DirectionKey::UP] = true;
	if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
		directionKeyPressed[DirectionKey::DOWN] = true;
	if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
		directionKeyPressed[DirectionKey::LEFT] = true;
	if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
		directionKeyPressed[DirectionKey::RIGHT] = true;
	QGraphicsView::keyPressEvent(event);
}

void View::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
		directionKeyPressed[DirectionKey::UP] = false;
	if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
		directionKeyPressed[DirectionKey::DOWN] = false;
	if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
		directionKeyPressed[DirectionKey::LEFT] = false;
	if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
		directionKeyPressed[DirectionKey::RIGHT] = false;
	QGraphicsView::keyReleaseEvent(event);
}

void View::timerEvent(QTimerEvent *event)
{
	
	if (event->timerId() == updateSightTimer)
	{
		QPoint pos = sceneRect().topLeft().toPoint();

		if (directionKeyPressed[DirectionKey::UP])
			pos += {0, -scrollSensitivity};
		if (directionKeyPressed[DirectionKey::DOWN])
			pos += {0, scrollSensitivity};
		if (directionKeyPressed[DirectionKey::LEFT])
			pos += {-scrollSensitivity, 0};
		if (directionKeyPressed[DirectionKey::RIGHT])
			pos += {scrollSensitivity, 0};

		setSceneRect({ pos, sceneRect().size() });
	}
}
