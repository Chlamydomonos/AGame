#include "Client.h"

Client::Client(QObject *parent) : QObject(parent)
{
	scene = new Scene(this);
	view = new View(dynamic_cast<QWidget *>(parent->parent()));
	view->setGeometry({ {0, 0}, dynamic_cast<QWidget *>(view->parent())->size() });
}
