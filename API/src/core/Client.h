#ifndef CORE__CLIENT_H
#define CORE__CLIENT_H

#include "../graphic/Scene.h"
#include "../graphic/View.h"
#include "../map/SyncMap.h"

#include <QGraphicsProxyWidget>

class Client : public QObject
{
	Q_OBJECT
private:
	friend class Game;
	friend class MapDefination;
	Scene *scene;
	View *view;
	SyncMap *map;
	bool player;
	QGraphicsProxyWidget *unitInfo;
	Client(QObject *parent = nullptr);
public slots:
	void updateCanInput();
public:
	Scene *getScene() const { return scene; }
	View *getView() const { return view; }
	SyncMap *getMap() const { return map; }
	bool getPlayer() const { return player; }
	QGraphicsProxyWidget *getUnitInfo() const { return unitInfo; }
};

#endif // !CORE__CLIENT_H
