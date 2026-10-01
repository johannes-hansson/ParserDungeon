#include "Game.h"

Game::Game() {
	this->world = std::make_unique<World>();
}
