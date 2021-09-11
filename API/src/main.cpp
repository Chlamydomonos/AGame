#include "MainWidget.h"
#include "core/Game.h"
#include "network/NetworkHandler.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    Game game(&w);
    Game::instance = &game;

    game.loadItems();

    NetworkHandler::registerSyncObjects();

    game.map = AllRegistries::getInstance()->getRegistry<MapDefination>()->get("agame:test");

    game.startClient();
    game.startServer();

    NetworkHandler::getServerInstance()->addConnection(QHostAddress::LocalHost);
    NetworkHandler::getClientInstance()->addConnection(QHostAddress::LocalHost);

    game.loadMap();
 
    w.show();
    auto returnCode = a.exec();
    game.releaseMemory();
    return returnCode;
}
