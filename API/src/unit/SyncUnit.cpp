#include "SyncUnit.h"

SyncUnit::SyncUnit(const SyncUnitPrototype *prototype, Side side) : SyncObject(prototype, side), clientUnit(nullptr),
player(false), chosen(false), x(0), y(0), z(0), cd1(0), cd2(0), cd3(0), hp(0), mp(0), exp(0), level(0), moved(false),
path()
{
	
}

void SyncUnit::serialize(PacketBuffer *buffer)
{
	buffer->write<bool>(player);
	buffer->write<bool>(chosen);
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
	buffer->write<bool>(movePressed);
	buffer->write<bool>(moved);

	for (int i = 0; i < path.length(); i++)
	{
		buffer->write<unsigned long long>(path[i]);
	}
	buffer->write<int>(path.length());

	SyncObject::serialize(buffer);
}

void SyncUnit::deserialize(PacketBuffer *buffer)
{
	SyncObject::deserialize(buffer);
	int len = buffer->read<int>();
	path.resize(len);

	for (int i = 0; i < len; i++)
	{
		path[len - i - 1] = buffer->read<unsigned long long>();
	}

	moved = buffer->read<bool>();
	movePressed = buffer->read<bool>();
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
	chosen = buffer->read<bool>();
	player = buffer->read<bool>();
}

void SyncUnit::setPath(const QVector<unsigned long long> &path)
{
	this->path.resize(path.length());
	for (int i = 0; i < path.length(); i++)
		this->path[i] = path[i];
}

unsigned long long SyncUnit::getIndex() const
{
	return (((unsigned long long) ((unsigned short)x)) << 32) | (((unsigned long long) ((unsigned short)y)) << 16) | ((unsigned long long) ((unsigned short)z));
}

void SyncUnit::setIndex(unsigned long long index)
{
	x = (index & (0xffffLL << 32)) >> 32;
	y = (index & (0xffffLL << 16)) >> 16;
	z = index & 0xffff;
}

QPoint SyncUnit::getClientPosition() const
{
	return QPoint(90 * x, 50 * x + 100 * z);
}
