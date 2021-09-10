#ifndef MAP__MAP_DEFINATION_H
#define MAP__MAP_DEFINATION_H

#include "ServerMap.h"
#include "ServerMapPrototype.h"
#include "SyncMap.h"
#include "SyncMapPrototype.h"
#include "../memory/registry/RegistryEntry.h"

class MapDefination : public QObject, public ServerMapPrototype, public SyncMapPrototype, public RegistryEntry<MapDefination>
{
protected:
	QString fileName;
public:
	MapDefination(const QString &name) : RegistryEntry(name) {}
	ServerMap *createMap();
};

#endif // !MAP__MAP_DEFINATION_H
