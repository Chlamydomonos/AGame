#include "Server.h"

Server::Server(QObject *parent) : QObject(parent), map(nullptr)
{
	NetworkHandler::serverInstance = new NetworkHandler(Side::SERVER);
}
