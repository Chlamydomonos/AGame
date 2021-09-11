#ifndef CORE__GAME_H
#define CORE__GAME_H

#include <QObject>
#include "Client.h"
#include "Server.h"

class Game : public QObject
{
private:
	friend class MainWidget;
	friend int main(int argc, char *argv[]);
	static Game *instance;
	Client *client;
	Server *server;
	MapDefination *map;
public:
	Game(QObject *parent = nullptr);
	static Game *getInstance() { return instance; }
	Client *getClient() const { return client; }
	Server *getServer() const { return server; }
	void loadMap();
	void loadItems();
	void startServer();
	void startClient();
	void releaseMemory();
};

#endif // !CORE__GAME_H
