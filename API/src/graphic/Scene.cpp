#include "Scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent), _mouseGrabber(nullptr)
{
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (_mouseGrabber != nullptr)
	{
		_mouseGrabber->mouseReleaseEvent(event);
		_mouseGrabber = nullptr;
	}
}
