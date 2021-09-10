#ifndef MAP__SERVER_MAP_H
#define MAP__SERVER_MAP_H

#include <QObject>
#include <QMap>
#include "TileDefination.h"
#include "../unit/UnitDefination.h"
#include "ServerMapPrototype.h"

class ServerMap : public QObject, public ItemWithPrototype<ServerMap, ServerMapPrototype>
{
	Q_OBJECT
private:
	friend class ServerTile;
	friend class SyncMap;
	friend class ServerUnit;
	friend class MapDefination;
	QMap<long long, ServerTile *> tiles;
	QMap<long long, ServerUnit *> units;
	SyncMap *syncMap;
public:
	ServerMap(const ServerMapPrototype *prototype) : ItemWithPrototype(prototype), syncMap(nullptr) {}

	void bindSyncMap(SyncMap *syncMap);
	SyncMap *getSyncMap() const { return syncMap; }

	ServerTile *getTile(short x, short y, short z) { return tiles[(((long long)x) << 4) | (((long long)y) << 2) | ((long long)z)]; }

	ServerUnit *getUnit(short x, short y, short z) { return units[(((long long)x) << 4) | (((long long)y) << 2) | ((long long)z)]; }
};

#endif // !MAP__SERVER_MAP_H
