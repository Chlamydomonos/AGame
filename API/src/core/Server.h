#ifndef CORE__SERVER_H
#define CORE__SERVER_H

#include "../map/MapDefination.h"

class Server : public QObject
{
private:
	friend class Game;
	ServerMap *map;
	Server(QObject *parent = nullptr);
public:
	ServerMap *getMap() { return map; }
	static NetworkHandler *getNetworkHandler() { return NetworkHandler::serverInstance; }
};

#endif // !CORE__SERVER_H
