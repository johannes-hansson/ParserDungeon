#include "Room.h"

Room::Room(int x, int y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
}

std::pair<int, int> Room::getCoordinates() const {
	return std::make_pair(this->xCoordinate, this->yCoordinate);
}
