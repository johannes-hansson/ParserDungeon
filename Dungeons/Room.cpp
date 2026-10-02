#include "Room.h"

Room::Room(int x, int y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
	this->entities = std::unordered_map<int, Entity>();
}

std::pair<int, int> Room::getCoordinates() const {
	return std::make_pair(this->xCoordinate, this->yCoordinate);
}

void Room::addEntity(Entity& entity) {
	this->entities[entity.getEntityId()] = entity;
}

void Room::removeEntity(Entity& entity) {
	this->entities.erase(entity.getEntityId());
}
