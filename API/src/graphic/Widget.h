#ifndef GRAPHIC__WIDGET_H
#define GRAPHIC__WIDGET_H

#include <QGraphicsProxyWidget>

class Widget : public QGraphicsProxyWidget
{
public:
	Widget(QObject *parent = nullptr) : QGraphicsProxyWidget(dynamic_cast<QGraphicsItem*>(parent)) {}

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override final;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override final;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override final;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override final;
};

#endif // !GRAPHIC__WIDGET_H
