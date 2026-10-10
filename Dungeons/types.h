#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

struct Game; struct World; struct Room; struct Entity;

struct Game {
	bool running = false;
	int nextEntityId = 1;

	World world;
	Entity player;
	std::unordered_map<int, std::unique_ptr<Entity>> entities;
};

struct World {
	std::unordered_map<std::string, std::unique_ptr<Room>> rooms;
};

struct Room {
	std::unordered_set<int> characters;
};

struct Entity {
	int entityId = -1;
	int characterId = -1;
};
