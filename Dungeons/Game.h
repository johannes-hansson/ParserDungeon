#pragma once

#include <memory>
#include "World.h"

class Game {
private:
	std::unique_ptr<World> world;
public:
	Game();
};
