#ifndef UNIT__SYNC_UNIT_H
#define UNIT__SYNC_UNIT_H

#include "../network/SyncObject.h"
#include "SyncUnitPrototype.h"

class SyncUnit : public SyncObject
{
private:
	friend class UnitDefination;
	friend class ServerUnit;
	friend class Sprite;
	bool player;
	bool chosen;
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
	bool movePressed;
	Sprite *clientUnit;
	bool moved;
	QVector<unsigned long long> path;
public:
	SyncUnit(const SyncUnitPrototype *prototype, Side side);

	void serialize(PacketBuffer *buffer);
	void deserialize(PacketBuffer *buffer);

	bool getPlayer() const{ return player; }
	bool getChosen() const { return chosen; }
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
	bool getMovePressed() const { return movePressed; }
	bool getMoved() const { return moved; }
	const QVector<unsigned long long> &getPath() const { return path; }

	void setPlayer(bool player) { this->player = player; }
	void setChosen(bool chosen) { this->chosen = chosen; }
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
	void setMovePressed(bool movePressed) { this->movePressed = movePressed; }
	void setMoved(bool moved) { this->moved = moved; }
	void setPath(const QVector<unsigned long long> &path);

	unsigned long long getIndex() const;
	void setIndex(unsigned long long index);

	Sprite *getClientUnit() const { return clientUnit; }

	QPoint getClientPosition() const;
};

#endif // !UNIT__SYNC_UNIT_H
