#include "UnitDefination.h"
#include "../core/Game.h"
#include "../widgets/ingame/UnitInfo.h"

void UnitDefination::onObjCreated(SyncUnit *obj) const
{
    if (obj->getSide() == Side::CLIENT)
    {
        Sprite *unit = createClientUnit(obj);
        Game::getInstance()->getClient()->getScene()->addItem(unit);
    }
}

void UnitDefination::onDataRecieved(SyncUnit *obj) const
{
    if (obj->getSide() == Side::CLIENT)
    {
        Sprite *unit = obj->getClientUnit();
        unit->setPos(obj->getClientPosition());

        if (!(obj->getPath().isEmpty()))
            startMoveByPath(obj);
    }
    else
    {
        auto ser = dynamic_cast<ServerUnit *>(obj->parent());
        if (obj->getChosen())
            ser->getMap()->setChosenUnit(ser);
        else if (ser->map->getChosenUnit() == ser)
            ser->map->setChosenUnit(nullptr);

        if (obj->movePressed)
            handlePressMove(obj);
    }
}

void UnitDefination::mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const
{
    auto unit = (SyncUnit *)(sprite->getDataMap()["sync"].toInt());

    if (!unit->chosen)
    {
        unit->setChosen(true);
        unit->notifyChange();
    }
    else
    {
        unit->setChosen(false);
        unit->notifyChange();
    }
    ClientUnitPrototype::mouseReleaseEvent(sprite, event);
}

void UnitDefination::hoverEnterEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const
{
    if (!Game::getInstance()->getClient()->getMap()->getCanChooseTile())
    {
        Game::getInstance()->getClient()->getUnitInfo()->setPos(sprite->pos() + QPointF(40.0, 0));
        Game::getInstance()->getClient()->getUnitInfo()->show();
        auto unitInfo = dynamic_cast<UnitInfo *>(Game::getInstance()->getClient()->getUnitInfo()->widget());
        unitInfo->setUnit(sprite);
    }
    ClientUnitPrototype::hoverEnterEvent(sprite, event);
}

void UnitDefination::hoverLeaveEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const
{
    auto unit = (SyncUnit *)(sprite->getDataMap()["sync"].toInt());

    if (!Game::getInstance()->getClient()->getMap()->getCanChooseTile())
    {
        if (!unit->chosen)
            Game::getInstance()->getClient()->getUnitInfo()->hide();
    }

    ClientUnitPrototype::hoverLeaveEvent(sprite, event);
}

void UnitDefination::handlePressMove(SyncUnit *unit) const
{
    Game::getInstance()->getServer()->getMap()->findUnitPath();
    unit->setMovePressed(false);
    unit->notifyChange();
}

void UnitDefination::startMoveByPath(SyncUnit *unit) const
{
    unit->setIndex(unit->getPath()[unit->getPath().length() - 1]);
    unit->getClientUnit()->setPos(unit->getClientPosition());
    unit->notifyChange();
    Game::getInstance()->getClient()->getMap()->setCanChooseTile(false);
    Game::getInstance()->getClient()->getMap()->notifyChange();
}

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
