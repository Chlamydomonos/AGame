#include "MainWidget.h"
#include "core/Game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    Game game(&w);
    game.loadItems();
    w.show();
    auto returnCode = a.exec();
    game.releaseMemory();
    return returnCode;
}
