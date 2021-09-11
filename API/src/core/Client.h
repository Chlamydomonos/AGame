#ifndef CORE__CLIENT_H
#define CORE__CLIENT_H

#include "../graphic/Scene.h"
#include "../graphic/View.h"
#include "../map/SyncMap.h"

class Client : public QObject
{
private:
	friend class Game;
	friend class MapDefination;
	Scene *scene;
	View *view;
	SyncMap *map;
	Client(QObject *parent = nullptr);
public:
	Scene *getScene() const { return scene; }
	View *getView() const { return view; }
	SyncMap *getMap() const { return map; }
};

#endif // !CORE__CLIENT_H
