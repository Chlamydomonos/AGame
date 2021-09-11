#include "Client.h"

Client::Client(QObject *parent) : QObject(parent)
{
	NetworkHandler::clientInstance = new NetworkHandler(Side::CLIENT);
	scene = new Scene(this);
	view = new View(dynamic_cast<QWidget *>(parent->parent()));
	view->setGeometry({ {0, 0}, dynamic_cast<QWidget *>(view->parent())->size() });
	view->setScene(scene);
	dynamic_cast<QWidget *>(parent->parent())->update();
}
