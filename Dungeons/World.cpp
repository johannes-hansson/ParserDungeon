#include "World.h"

static std::string getPositionEncoding(int x, int y) {
	return std::to_string(x) + ":" + std::to_string(y);
}

World::World() {
	this->nextInstanceId = 1;
	this->rooms = std::unordered_map<std::string, Room*>();
	this->spacialCache = std::unordered_map<int, Room*>();
}

int World::getAndIncrementInstanceId() {
	int instanceId = this->nextInstanceId;
	this->nextInstanceId++;
	return instanceId;
}

Room& World::createRoom(int x, int y) {
	Room* room = new Room(x, y);
	this->rooms[getPositionEncoding(x, y)] = room;
	return *room;
}

int World::addObject(GameObject object, Room& room) {
	std::pair<int, int> coordinates = room.getCoordinates();
	int instanceId = this->getAndIncrementInstanceId();
	object.setInstanceId(instanceId);
	this->spacialCache[instanceId] = &room;
	return 1;
}

Room& World::getRoom(int x, int y) {
	std::string positionEncoding = getPositionEncoding(x, y);
	if (this->rooms.contains(positionEncoding)) {
		return *(rooms[positionEncoding]);
	}
}
