#pragma once

#include <memory>
#include <unordered_map>
#include "Character.h"

using CharacterMap = std::unordered_map<int, std::unique_ptr<Character>>;

class Room {
private:
	int xCoordinate;
	int yCoordinate;
	CharacterMap characters;
public:
	Room(int x, int y);
	std::pair<int, int> getCoordinates() const;
	void addCharacter(std::unique_ptr<Character> character);
	std::unique_ptr<Character> removeCharacter(int instanceId);
};

