#include "ServerUnit.h"
#include "SyncUnit.h"
#include "../map/ServerMap.h"

void ServerUnit::initMap(ServerMap *map)
{
	this->map = map;
}

void ServerUnit::bindSyncUnit(SyncUnit *syncUnit)
{
	this->syncUnit = syncUnit;
	this->syncUnit->setParent(this);
}
