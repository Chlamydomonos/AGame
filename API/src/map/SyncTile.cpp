#include "SyncTile.h"
#include "../graphic/Sprite.h"

#include <math.h>

void SyncTile::updateClientTile()
{
	if (clientTile != nullptr)
		clientTile->setPos(getClientPosition());
}

SyncTile::SyncTile(const SyncTilePrototype *prototype, Side _side) :
	SyncObject(prototype, _side), x(0), y(0), z(0), highlight(0), clientTile(nullptr)
{
	connect(this, &SyncTile::dataRecieved, this, &SyncTile::updateClientTile);
}

void SyncTile::serialize(PacketBuffer *buffer)
{
	buffer->write<short>(x);
	buffer->write<short>(y);
	buffer->write<short>(z);
	buffer->write<char>(highlight);
	SyncObject::serialize(buffer);
}

void SyncTile::deserialize(PacketBuffer *buffer)
{
	SyncObject::deserialize(buffer);
	highlight = buffer->read<char>();
	z = buffer->read<short>();
	y = buffer->read<short>();
	x = buffer->read<short>();
}

QPoint SyncTile::getClientPosition() const
{
	return QPoint((int)(sqrt(3) * 60.0 * x), 50 * x + 100 * z);
}
