#include "Game.h"
#include "../memory/registry/AllRegistries.h"

Game::Game(QObject *parent) : QObject(parent)
{
	AllRegistries::instance = new AllRegistries();
}

void Game::loadItems()
{
	
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
}
