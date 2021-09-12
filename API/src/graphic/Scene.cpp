#include "Scene.h"
#include "Widget.h"

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (inputEnabled)
	{
		for (auto i : _mouseGrabber)
		{
			if (dynamic_cast<Widget *>(i))
				(dynamic_cast<Widget *>(i))->mouseMoveEvent(event);
		}

		QGraphicsScene::mouseMoveEvent(event);
	}
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (inputEnabled)
		QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (inputEnabled)
	{
		for (auto i : _mouseGrabber)
		{
			if (dynamic_cast<Sprite *>(i))
				dynamic_cast<Sprite *>(i)->mouseReleaseEvent(event);
			else if (dynamic_cast<Widget *>(i))
				(dynamic_cast<Widget *>(i))->mouseReleaseEvent(event);
		}
	}
}
