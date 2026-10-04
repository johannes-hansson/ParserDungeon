#include "Room.h"

Room::Room(int x, int y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
	this->characters = std::unordered_map<int, std::unique_ptr<Character>>();
}

std::pair<int, int> Room::getCoordinates() const {
	return std::make_pair(this->xCoordinate, this->yCoordinate);
}

void Room::addCharacter(std::unique_ptr<Character> character) {
	this->characters[character->getInstanceId()] = std::move(character);
}

std::unique_ptr<Character> Room::removeCharacter(int instanceId) {
	auto it = this->characters.find(instanceId);
	if (it != this->characters.end()) {
		std::unique_ptr<Character> character = std::move(it->second);
		this->characters.erase(it);
		return character;
	}
	return nullptr;
}
