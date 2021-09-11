#ifndef CORE__GAME_H
#define CORE__GAME_H

#include <QObject>
#include "Client.h"
#include "Server.h"

class Game : public QObject
{
private:
	friend class MainWidget;
	static Game *instance;
	Client *client;
	Server *server;
public:
	Game(QObject *parent = nullptr);
	void loadItems();
	void startServer();
	void startClient();
	void releaseMemory();
};

#endif // !CORE__GAME_H
