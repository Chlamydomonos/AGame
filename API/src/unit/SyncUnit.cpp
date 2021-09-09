#include "SyncUnit.h"

SyncUnit::SyncUnit(const SyncUnitPrototype *prototype, Side side) : SyncObject(prototype, side)
{
}

void SyncUnit::serialize(PacketBuffer *buffer)
{
}

void SyncUnit::deserialize(PacketBuffer *buffer)
{
}
