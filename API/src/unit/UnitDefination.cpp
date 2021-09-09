#include "UnitDefination.h"

ServerUnit *UnitDefination::createServerUnit(int x, int y, int z) const
{
    ServerUnit *unit = ServerUnitPrototype::create();
    SyncUnit *sync = SyncUnitPrototype::create(Side::SERVER);
    sync->setX(x);
    sync->setY(y);
    sync->setZ(z);
    sync->setHp(maxHP[0]);
    sync->setMp(maxMP[0]);
    sync->setExp(0);
    sync->setLevel(0);
    unit->bindSyncUnit(sync);
    return unit;
}

Sprite *UnitDefination::createClientUnit(SyncUnit *unit) const
{
    Sprite *sprite = ClientUnitPrototype::create();
    unit->clientUnit = sprite;
    sprite->getDataMap().insert("sync", (size_t)unit);
    return sprite;
}
