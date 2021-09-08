#ifndef GRAPHIC__SCENE_H
#define GRAPHIC__SCENE_H

#include <QGraphicsScene>
#include "Sprite.h"

class Scene : public QGraphicsScene
{
private:
	friend class Sprite;
	Sprite *_mouseGrabber;
public:
	Scene(QObject *parent = nullptr);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override final;
};

#endif // !GRAPHIC__SCENE_H
