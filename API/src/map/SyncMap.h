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
public:
	SyncMap(const SyncMapPrototype *prototype, Side side);

	void serialize(PacketBuffer *buffer);
	void deserialize(PacketBuffer *buffer);

	int getCurrentRound() const { return currentRound; }
	int getCurrentPlayer() const { return currentPlayer; }
	int getPlayer0Cash() const { return player0Cash; }
	int getPlayer1Cash() const { return player1Cash; }
};

#endif // !MAP__SYNC_MAP_H
