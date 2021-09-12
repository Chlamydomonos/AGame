#include "Client.h"
#include "../widgets/ingame/UnitInfo.h"
#include "../graphic/Widget.h"

Client::Client(QObject *parent) : QObject(parent), player(false)
{
	NetworkHandler::clientInstance = new NetworkHandler(Side::CLIENT);
	scene = new Scene(this);
	view = new View(dynamic_cast<QWidget *>(parent->parent()));
	view->setGeometry({ {0, 0}, dynamic_cast<QWidget *>(view->parent())->size() });
	view->setScene(scene);
	dynamic_cast<QWidget *>(parent->parent())->update();
	unitInfo = new Widget();
	unitInfo->setWidget(new UnitInfo());
	scene->addItem(unitInfo);
	unitInfo->setZValue(2);
	unitInfo->hide();
}

void Client::updateCanInput()
{
	scene->setInputEnabled(map->getCanInput());
}
