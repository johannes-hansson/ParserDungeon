#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Character.h"
#include "Room.h"

using CharacterSpacialMap = std::unordered_map<int, Room*>;
using RoomMap = std::unordered_map<std::string, Room*>;

class World {
private:
	int nextInstanceId;
	CharacterSpacialMap spacialCache;
	RoomMap rooms;

	int getAndIncrementInstanceId();
	Room& createRoom(int x, int y);
public:
	World();
	Character* createCharacter();
	void moveEntity(Entity& entity, Room& destination);
	Entity& createEntity(Room& room);
	Room& getRoom(int x, int y);
};
