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
	const QString typeName;
	friend class NetworkHandler;
	template<class T>
	friend class SyncObjectPrototype;
	SyncObject *create(Side side, const QString &typeName) const;
protected:
	virtual SyncObject *createObjFromNet(Side side) const = 0;
	virtual SyncObject *createObjFromLocal(Side side) const = 0;
	BaseSyncObjectPrototype(const QString &_typeName);
public:
	~BaseSyncObjectPrototype();
};

template<class T>
class SyncObjectPrototype : public BaseSyncObjectPrototype
{
private:
	virtual SyncObject *createObjFromNet(Side side) const override final
	{
		auto out = static_cast<SyncObject *>(createFromNet(side));
		out->side = (Side)(1 - (int)side);
		return out;
	}

	virtual SyncObject *createObjFromLocal(Side side) const override final
	{
		auto out = static_cast<SyncObject *>(createFromLocal(side));
		out->side = side;
		return out;
	}
protected:
	virtual T *createFromNet(Side side) const = 0;
	virtual T *createFromLocal(Side side) const = 0;
public:
	SyncObjectPrototype() : BaseSyncObjectPrototype(typeid(T).name())
	{
		static_assert(std::is_convertible<T *, SyncObject *>::value, "Cannot create sync object prototype without a sync object");
	}
	T *create(Side side) const { return static_cast<T *>(BaseSyncObjectPrototype::create(side, typeid(T).name())); }
};


#endif // !NETWORK__SYNC_OBJECT_PROTOTYPE_H
