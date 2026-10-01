#pragma once

#include <utility>

class Room {
private:
	int xCoordinate;
	int yCoordinate;
public:
	Room(int x, int y);
	std::pair<int, int> getCoordinates() const;
};

