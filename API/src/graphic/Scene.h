#ifndef GRAPHIC__SCENE_H
#define GRAPHIC__SCENE_H

#include <QGraphicsScene>
#include <QSet>
#include "Sprite.h"

class Scene : public QGraphicsScene
{
private:
	friend class Sprite;
	friend class Widget;
	QSet<QGraphicsItem *> _mouseGrabber;
	bool inputEnabled;
public:
	Scene(QObject *parent = nullptr) :
		QGraphicsScene(parent), _mouseGrabber(), inputEnabled(true) {}
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override final;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override final;

	bool isInputEnabled() { return inputEnabled; }
	void setInputEnabled(bool inputEnabled) { this->inputEnabled = inputEnabled; }
	void enableInput() { inputEnabled = true; }
	void disableInput() { inputEnabled = false; }
};

#endif // !GRAPHIC__SCENE_H
