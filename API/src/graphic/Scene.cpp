#include "Scene.h"

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (inputEnabled)
		QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (inputEnabled)
		QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (_mouseGrabber != nullptr && inputEnabled)
	{
		_mouseGrabber->mouseReleaseEvent(event);
		_mouseGrabber = nullptr;
	}
}
