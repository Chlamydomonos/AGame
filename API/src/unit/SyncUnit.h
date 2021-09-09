#ifndef UNIT__SYNC_UNIT_H
#define UNIT__SYNC_UNIT_H

#include "SyncUnitPrototype.h"
#include "../network/SyncObject.h"

class SyncUnit : public SyncObject
{
private:
	friend class UnitDefination;
	friend class ServerUnit;
	friend class Sprite;
	short x;
	short y;
	short z;
	int cd1;
	int cd2;
	int cd3;
	double hp;
	double mp;
	int exp;
	int level;
	Sprite *clientUnit;
public:
	SyncUnit(const SyncUnitPrototype *prototype, Side side);

	void serialize(PacketBuffer *buffer);
	void deserialize(PacketBuffer *buffer);

	short getX() const { return x; }
	short getY() const { return y; }
	short getZ() const { return z; }
	int getCd1() const { return cd1; }
	int getCd2() const { return cd2; }
	int getCd3() const { return cd3; }
	double getHp() const { return hp; }
	double getMp() const { return mp; }
	int getExp() const { return exp; }
	int getLevel() const { return level; }

	void setX(short x) { this->x = x; }
	void setY(short y) { this->y = y; }
	void setZ(short z) { this->z = z; }
	void setCd1(int cd1) { this->cd1 = cd1; }
	void setCd2(int cd2) { this->cd2 = cd2; }
	void setCd3(int cd3) { this->cd3 = cd3; }
	void setHp(double hp) { this->hp = hp; }
	void setMp(double mp) { this->mp = mp; }
	void setExp(int exp) { this->exp = exp; }
	void setLevel(int level) { this->level = level; }

	Sprite *getClientUnit() const { return clientUnit; }

	QPoint getClientPosition() const;
};

#endif // !UNIT__SYNC_UNIT_H
