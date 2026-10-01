#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "GameObject.h"
#include "Room.h"

class World {
private:
	int nextInstanceId;
	std::unordered_map<int, Room*> spacialCache;
	std::unordered_map<std::string, Room*> rooms;

	int getAndIncrementInstanceId();
	Room& createRoom(int x, int y);
public:
	World();
	int addObject(GameObject object, Room& room);
	Room& getRoom(int x, int y);
};
