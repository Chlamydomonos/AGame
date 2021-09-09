#ifndef MAP__SYNC_MAP_PROTOTYPE
#define MAP__SYNC_MAP_PROTOTYPE

#include "../network/SyncObjectProrotype.h"
class SyncMap;

class SyncMapPrototype : public SyncObjectPrototype<SyncMap>
{
private:
	virtual SyncMap *createFromNet(Side side) const override final;
	virtual SyncMap *createFromLocal(Side side) const override final;
};

#endif // !MAP__SYNC_OBJECT_PROTOTYPE
