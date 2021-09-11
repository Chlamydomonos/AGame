#include "SyncMap.h"

SyncMap::SyncMap(const SyncMapPrototype *prototype, Side side) : 
	SyncObject(prototype, side), currentRound(0), currentPlayer(0), player0Cash(0), player1Cash(0), canInput(false), canChooseTile(false)
{
}

void SyncMap::serialize(PacketBuffer *buffer)
{
	buffer->write<int>(currentRound);
	buffer->write<int>(currentPlayer);
	buffer->write<int>(player0Cash);
	buffer->write<int>(player1Cash);
	buffer->write<bool>(canInput);
	buffer->write<bool>(canChooseTile);
	SyncObject::serialize(buffer);
}

void SyncMap::deserialize(PacketBuffer *buffer)
{
	SyncObject::deserialize(buffer);
	canChooseTile = buffer->read<bool>();
	canInput = buffer->read<bool>();
	player1Cash = buffer->read<int>();
	player0Cash = buffer->read<int>();
	currentPlayer = buffer->read<int>();
	currentRound = buffer->read<int>();
}
