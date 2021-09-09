#ifndef MAP__SERVER_TILE_H
#define MAP__SERVER_TILE_H

#include "../util/ItemWithPrototype.h"

#include <QMap>
#include <QPoint>
#include <QObject>
#include "ServerTilePrototype.h"

class Direction
{
public:
	const static Direction UP;
	const static Direction DOWN;
	const static Direction FRONT;
	const static Direction BACK;
	const static Direction RIGHT;
	const static Direction LEFT;
	unsigned long long value;
	Direction(unsigned long long _value) : value(_value) {}
	Direction(const Direction &obj) : value(obj.value) {}

	short x() const { return (value & (0xffff << 4)) >> 4; }
	short y() const { return (value & (0xffff << 2)) >> 2; }
	short z() const { return value & 0xffff; }

	bool operator==(const Direction &other) const { return value == other.value; }
	bool operator!=(const Direction &other) const { return value != other.value; }
	operator long long() const { return value; }
};

class ServerTile : public QObject, public ItemWithPrototype<ServerTile, ServerTilePrototype>
{
	Q_OBJECT
private:
	friend class SyncTile;
	friend class ServerMap;
	friend class ServerTilePrototype;
	friend class TileDefination;
	short x;
	short y;
	short z;
	QMap<Direction, ServerTile *>neighbours;
	SyncTile *syncTile;
	ServerMap *map;
	ServerTile(const ServerTilePrototype *prototpye) :
		ItemWithPrototype(prototpye), x(0), y(0), z(0), syncTile(nullptr), map(nullptr) {}
public:
	void setPosition(short x, short y, short z) { this->x = x; this->y = y; this->z = z; }

	const ServerTilePrototype *getPrototype() const { return prototype; }

	unsigned long long index() const { return (((unsigned long long) x) << 4) | (((unsigned long long) y) << 2) | ((unsigned long long) z); }

	void initMap(ServerMap *map);
	void bindSyncTile(SyncTile *syncTile);
};

#endif // !MAP__SERVER_TILE_H
