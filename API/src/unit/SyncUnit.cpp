#include "SyncUnit.h"

SyncUnit::SyncUnit(const SyncUnitPrototype *prototype, Side side) : SyncObject(prototype, side), clientUnit(nullptr)
{
	
}

void SyncUnit::serialize(PacketBuffer *buffer)
{
	buffer->write<short>(x);
	buffer->write<short>(y);
	buffer->write<short>(z);
	buffer->write<int>(cd1);
	buffer->write<int>(cd2);
	buffer->write<int>(cd3);
	buffer->write<double>(hp);
	buffer->write<double>(mp);
	buffer->write<int>(exp);
	buffer->write<int>(level);
	SyncObject::serialize(buffer);
}

void SyncUnit::deserialize(PacketBuffer *buffer)
{
	SyncObject::deserialize(buffer);
	level = buffer->read<int>();
	exp = buffer->read<int>();
	mp = buffer->read<double>();
	hp = buffer->read<double>();
	cd3 = buffer->read<int>();
	cd2 = buffer->read<int>();
	cd1 = buffer->read<int>();
	z = buffer->read<short>();
	y = buffer->read<short>();
	x = buffer->read<short>();
}
