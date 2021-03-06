#ifndef MAP__TILE_DEFINATION_H
#define MAP__TILE_DEFINATION_H

#include "../memory/registry/RegistryEntry.h"
#include "ServerTilePrototype.h"
#include "SyncTilePrototype.h"
#include "ClientTilePrototype.h"
#include "ServerTile.h"
#include "SyncTile.h"
#include "../graphic/Sprite.h"
#include <QObject>

class TileDefination : public QObject, public RegistryEntry<TileDefination>, public ServerTilePrototype, public SyncTilePrototype, public ClientTilePrototype
{
	Q_OBJECT
protected:
	bool walkable;
	virtual void onObjCreated(SyncTile *obj) const override;
	virtual void onDataRecieved(SyncTile *object) const override;

	virtual void mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const override;
public:
	TileDefination(const QString &name) : RegistryEntry(name) {}
	bool isWalkable() const { return walkable; }
	ServerTile *createServerTile(int x, int y, int z) const;
	Sprite *createClientTile(SyncTile *tile) const;
};

#endif // !MAP__TILE_DEFINATION_H
