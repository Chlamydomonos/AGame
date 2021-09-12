#ifndef UNIT__UNIT_DEFINATION_H
#define UNIT__UNIT_DEFINATION_H

#include "../memory/registry/RegistryEntry.h"

#include "../graphic/Sprite.h"

#include "ServerUnitPrototype.h"
#include "SyncUnitPrototype.h"
#include "ClientUnitPrototype.h"
#include "ServerUnit.h"
#include "SyncUnit.h"
#include "Skill.h"

class UnitDefination : public QObject, public RegistryEntry<UnitDefination>, public ServerUnitPrototype, public SyncUnitPrototype, public ClientUnitPrototype
{
	Q_OBJECT
protected:
	double maxHP[3];
	double maxMP[3];
	double atk[3];
	double def[3];
	double res[3];
	int mov[3];
	int price;
	int exp[2];
	int deathExp[3];
	Skill *skills[3];

	virtual void onObjCreated(SyncUnit *obj) const override;
	virtual void onDataRecieved(SyncUnit *obj) const override;

	virtual void mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const override;

	virtual void hoverEnterEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const override;
	virtual void hoverLeaveEvent(Sprite *sprite, QGraphicsSceneHoverEvent *event) const override;

	void handlePressMove(SyncUnit *unit) const;

	void startMoveByPath(SyncUnit *unit) const;
public:
	UnitDefination(const QString &name) : 
		RegistryEntry(name), maxHP(), maxMP(), atk(), def(), res(), mov(),
		price(0), exp(), deathExp(), skills() {}
	ServerUnit *createServerUnit(int x, int y, int z) const;
	Sprite *createClientUnit(SyncUnit *unit) const;

	double getMaxHP(int level) const { return maxHP[level]; }
	double getMaxMP(int level) const { return maxMP[level]; }
	double getAtk(int level) const { return atk[level]; }
	double getDef(int level) const { return def[level]; }
	double getRes(int level) const { return res[level]; }
	int getMov(int level) const { return mov[level]; }
	int getPrice() const { return price; }
	int getExp(int fromLevel) const { return exp[fromLevel]; }
	int getDeathExp(int level) const { return deathExp[level]; }
	Skill *getSkill(int index) const { return skills[index]; }
};

#endif // !UNIT__UNIT_DEFINATION_H
