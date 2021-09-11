#ifndef CORE__CLIENT_H
#define CORE__CLIENT_H

#include "../graphic/Scene.h"
#include "../graphic/View.h"

class Client : public QObject
{
private:
	friend class Game;
	Scene *scene;
	View *view;
	SyncMap *map;
	Client(QObject *parent = nullptr);
public:
	Scene *getScene() { return scene; }
	View *getView() { return view; }
};

#endif // !CORE__CLIENT_H
