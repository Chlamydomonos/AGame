#ifndef UNIT__SERVER_UNIT_H
#define UNIT__SERVER_UNIT_H

#include "ServerUnitPrototype.h"
#include <QObject>
#include "../util/ItemWithPrototype.h"

class ServerUnit : public QObject, public ItemWithPrototype<ServerUnit, ServerUnitPrototype>
{
private:
	friend class SyncUnit;
	friend class ServerUnitPrototype;
	friend class UnitDefination;
	SyncUnit *syncUnit;
public:
	ServerUnit(const ServerUnitPrototype *prototype) : ItemWithPrototype(prototype) {}
	void bindSyncUnit(SyncUnit *syncUnit);
	SyncUnit *getSyncUnit() { return syncUnit; }
};

#endif // !UNIT__SERVER_UNIT_H
