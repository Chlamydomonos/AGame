#ifndef UNIT__SYNC_UNIT_PROTOTYPE_H
#define UNIT__SYNC_UNIT_PROTOTYPE_H

#include "../network/SyncObjectProrotype.h"

class SyncUnit;

class SyncUnitPrototype : public SyncObjectPrototype<SyncUnit>
{
private:
	virtual SyncUnit *createFromNet(Side side) const override final;
	virtual SyncUnit *createFromLocal(Side side) const override final;
};

#endif // !UNIT__SYNC_UNIT_PROTOTYPE_H
