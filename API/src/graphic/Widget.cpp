#include "Widget.h"
#include "Scene.h"

void Widget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsProxyWidget::mouseMoveEvent(event);
}

void Widget::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	dynamic_cast<Scene *>(scene())->_mouseGrabber.insert(this);
	QGraphicsProxyWidget::hoverEnterEvent(event);
}

void Widget::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	dynamic_cast<Scene *>(scene())->_mouseGrabber.remove(this);
	QGraphicsProxyWidget::hoverLeaveEvent(event);
}

void Widget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsProxyWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsProxyWidget::mouseReleaseEvent(event);
}

