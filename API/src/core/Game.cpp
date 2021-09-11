#include "Game.h"
#include "../memory/registry/AllRegistries.h"
#include "../tiles/Ground.h"
#include "../tiles/Water.h"
#include "../maps/Test.h"

Game *Game::instance{ nullptr };

Game::Game(QObject *parent) : QObject(parent)
{
	AllRegistries::instance = new AllRegistries();
}

void Game::loadMap()
{
	server->map = map->createMap();
}

void Game::loadItems()
{
	new Ground();
	new Water();
	new Test();
}

void Game::startServer()
{
	server = new Server(this);
}

void Game::startClient()
{
	client = new Client(this);
}

void Game::releaseMemory()
{
	delete AllRegistries::instance;
}
