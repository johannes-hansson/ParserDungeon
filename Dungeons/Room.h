#pragma once

#include <utility>
#include <unordered_map>
#include "Entity.h">

class Room {
private:
	int xCoordinate;
	int yCoordinate;
	std::unordered_map<int, Entity> entities;
public:
	Room(int x, int y);
	std::pair<int, int> getCoordinates() const;
	void addEntity(Entity& entity);
	void removeEntity(Entity& entity);
};

