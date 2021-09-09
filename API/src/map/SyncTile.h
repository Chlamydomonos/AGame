#ifndef MAP__SYNC_TILE_H
#define MAP__SYNC_TILE_H

#include "../network/SyncObject.h"
#include "../util/ItemWithPrototype.h"

#include "SyncTilePrototype.h"

class SyncTile : public SyncObject
{
private:
	friend class ServerTile;
	friend class Sprite;
	friend class SyncTilePrototype;
	friend class TileDefination;
	short x;
	short y;
	short z;
	char highlight;
	Sprite *clientTile;
private slots:
	void updateClientTile();
public:
	SyncTile(const SyncTilePrototype *prototype, Side _side);
	~SyncTile();

	virtual void serialize(PacketBuffer *buffer) override final;
	virtual void deserialize(PacketBuffer *buffer) override final;

	short getX() const { return x; }
	short getY() const { return y; }
	short getZ() const { return z; }
	char getHighlight() const { return highlight; }
	void setHighlight(char highlight) { this->highlight = highlight; }
	Sprite *getClientTile() const { return clientTile; }

	QPoint getClientPosition() const;
};

#endif // !MAP__SYNC_TILE_H
