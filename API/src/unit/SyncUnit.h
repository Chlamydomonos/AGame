#ifndef UNIT__SYNC_UNIT_H
#define UNIT__SYNC_UNIT_H

#include "SyncUnitPrototype.h"
#include "../network/SyncObject.h"

class SyncUnit : public SyncObject, public ItemWithPrototype<SyncUnit, SyncUnitPrototype>
{

};

#endif // !UNIT__SYNC_UNIT_H
