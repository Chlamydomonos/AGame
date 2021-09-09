#ifndef NETWORK__SYNC_OBJECT_PROTOTYPE_H
#define NETWORK__SYNC_OBJECT_PROTOTYPE_H

#include <QObject>
#include "../util/Prototype.h"
#include "Side.h"
#include "NetworkHandler.h"

class SyncObject;

class BaseSyncObjectPrototype
{
private:
	friend class NetworkHandler;
protected:
	virtual SyncObject *createFromNet(Side side) = 0;
	virtual SyncObject *createFromLocal(Side side) = 0;
public:
	SyncObject *create(Side side);
};

template<class T>
class SyncObjectPrototype : public BaseSyncObjectPrototype
{

};


#endif // !NETWORK__SYNC_OBJECT_PROTOTYPE_H
