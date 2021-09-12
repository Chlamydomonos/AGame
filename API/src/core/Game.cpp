#include "Game.h"
#include "../memory/registry/AllRegistries.h"
#include "Loader.h"

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
	Loader::load();
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
