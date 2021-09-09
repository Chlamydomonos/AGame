#ifndef UNIT__SYNC_UNIT_H
#define UNIT__SYNC_UNIT_H

#include "SyncUnitPrototype.h"
#include "../network/SyncObject.h"
#include "SyncUnitPrototype.h"

class SyncUnit : public SyncObject
{
private:
	short x;
	short y;
	short z;
	int hp;
	int mp;
	int exp;
	int level;
public:
	SyncUnit(const SyncUnitPrototype *prototype, Side side);

	void serialize(PacketBuffer *buffer);
	void deserialize(PacketBuffer *buffer);

	short getX() { return x; }
	short getY() { return y; }
	short getZ() { return z; }
	int getHp() { return hp; }
	int getMp() { return mp; }
	int getExp() { return exp; }
	int getLevel() { return level; }

	void setX(short x) { this->x = x; }
	void setY(short y) { this->y = y; }
	void setZ(short z) { this->z = z; }
	void setHp(int hp) { this->hp = hp; }
	void setMp(int mp) { this->mp = mp; }
	void setExp(int exp) { this->exp = exp; }
	void setLevel(int level) { this->level = level; }
};

#endif // !UNIT__SYNC_UNIT_H
