#include "ServerUnit.h"
#include "SyncUnit.h"

void ServerUnit::bindSyncUnit(SyncUnit *syncUnit)
{
	this->syncUnit = syncUnit;
	this->syncUnit->setParent(this);
}
