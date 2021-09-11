#ifndef MAP__SYNC_MAP_H
#define MAP__SYNC_MAP_H

#include "../network/SyncObject.h"
#include "SyncMapPrototype.h"

class SyncMap : public SyncObject
{
private:
	friend class ServerMap;
	friend class SyncMapPrototype;
	friend class MapDefination;
	int currentRound;
	int currentPlayer;
	int player0Cash;
	int player1Cash;
	bool canInput;
	bool canChooseTile;
public:
	SyncMap(const SyncMapPrototype *prototype, Side side);

	void serialize(PacketBuffer *buffer);
	void deserialize(PacketBuffer *buffer);

	int getCurrentRound() const { return currentRound; }
	int getCurrentPlayer() const { return currentPlayer; }
	int getPlayer0Cash() const { return player0Cash; }
	int getPlayer1Cash() const { return player1Cash; }
	bool getCanInput() const { return canInput; }
	bool getCanChooseTile() const { return canChooseTile; }

	void setCurrentRound(int currentRound) { this->currentRound = currentRound; }
	void setCurrentPlayer(int currentPlayer) { this->currentPlayer = currentPlayer; }
	void setPlayer0Cash(bool player0Cash) { this->player0Cash = player0Cash; }
	void setPlayer1Case(bool player1Cash) { this->player1Cash = player1Cash; }
	void setCanInput(bool canInput) { this->canInput = canInput; }
	void setCanChooseTile(bool canChooseTile) { this->canChooseTile = canChooseTile; }
};

#endif // !MAP__SYNC_MAP_H
