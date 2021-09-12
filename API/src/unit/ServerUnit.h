#ifndef UNIT__SERVER_UNIT_H
#define UNIT__SERVER_UNIT_H

#include "ServerUnitPrototype.h"
#include <QObject>
#include "../util/ItemWithPrototype.h"

class ServerUnit : public QObject, public ItemWithPrototype<ServerUnit, ServerUnitPrototype>
{
private:
	friend class ServerMap;
	friend class ServerTile;
	friend class SyncUnit;
	friend class ServerUnitPrototype;
	friend class UnitDefination;
	SyncUnit *syncUnit;
	ServerMap *map;
public:
	ServerUnit(const ServerUnitPrototype *prototype) : ItemWithPrototype(prototype) {}

	void initMap(ServerMap *map);
	ServerMap *getMap() const { return map; }
	void bindSyncUnit(SyncUnit *syncUnit);
	SyncUnit *getSyncUnit() const { return syncUnit; }
};

#endif // !UNIT__SERVER_UNIT_H
