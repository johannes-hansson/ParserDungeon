#include "World.h"
#include "Entity.h"

static std::string getPositionEncoding(int x, int y) {
	return std::to_string(x) + ":" + std::to_string(y);
}

World::World() {
	this->nextInstanceId = 1;
	this->rooms = std::unordered_map<std::string, Room*>();
	this->spacialCache = std::unordered_map<int, Room*>();
}

int World::getAndIncrementInstanceId() {
	int entityId = this->nextInstanceId;
	this->nextInstanceId++;
	return entityId;
}

Room& World::createRoom(int x, int y) {
	Room* room = new Room(x, y);
	this->rooms[getPositionEncoding(x, y)] = room;
	return *room;
}

void World::moveEntity(Entity& entity, Room& destination) {
	int entityId = entity.getEntityId();
	if (this->spacialCache.contains(entityId)) {
		Room* currentRoom = this->spacialCache[entityId];
		currentRoom->removeEntity(entity);
	}
	destination.addEntity(entity);
	this->spacialCache[entityId] = &destination;
}

Entity& World::createEntity(Room& room) {
	std::pair<int, int> coordinates = room.getCoordinates();
	int entityId = this->getAndIncrementInstanceId();
	
	Entity entity(entityId);
	room.addEntity(entity);
	this->spacialCache[entityId] = &room;

	return entity;
}

Room& World::getRoom(int x, int y) {
	std::string positionEncoding = getPositionEncoding(x, y);
	if (this->rooms.contains(positionEncoding)) {
		return *(rooms[positionEncoding]);
	}
}
