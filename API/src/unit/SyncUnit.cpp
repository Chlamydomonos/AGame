#include "SyncUnit.h"

SyncUnit::SyncUnit(const SyncUnitPrototype *prototype, Side side) : SyncObject(prototype, side)
{
	
}

void SyncUnit::serialize(PacketBuffer *buffer)
{
	buffer->write<short>(x);
	buffer->write<short>(y);
	buffer->write<short>(z);
	buffer->write<int>(hp);
	buffer->write<int>(mp);
	buffer->write<int>(exp);
	buffer->write<int>(level);
	SyncObject::serialize(buffer);
}

void SyncUnit::deserialize(PacketBuffer *buffer)
{
	SyncObject::deserialize(buffer);
	level = buffer->read<int>();
	exp = buffer->read<int>();
	mp = buffer->read<int>();
	hp = buffer->read<int>();
	z = buffer->read<short>();
	y = buffer->read<short>();
	x = buffer->read<short>();
}
