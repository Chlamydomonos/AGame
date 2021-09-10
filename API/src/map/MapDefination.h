#ifndef MAP__MAP_DEFINATION_H
#define MAP__MAP_DEFINATION_H

#include "ServerMap.h"
#include "ServerMapPrototype.h"
#include "SyncMap.h"
#include "SyncMapPrototype.h"
#include "../memory/registry/RegistryEntry.h"

class MapDefination : public QObject, public ServerMapPrototype, public SyncMapPrototype, public RegistryEntry<MapDefination>
{
public:
};

#endif // !MAP__MAP_DEFINATION_H
