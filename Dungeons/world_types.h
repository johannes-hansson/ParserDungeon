#pragma once

#include <memory>
#include <unordered_map>
#include <string>

struct Game;
struct World;
struct Room;
struct Entity;
struct EntityController;
struct Character;

struct Character {
	int characterId = -1;
	int entityId = -1;
};

struct World {
	int nextCharacterId = 1;
	std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
	std::unordered_map<int, std::shared_ptr<Room>> characterSpacialMap;
};

struct Game {
	int nextEntityId = 1;
	bool running = false;
	World world;
	std::unordered_map<int, Entity> entities;
};

struct Room {
	std::unordered_map<int, std::shared_ptr<Character>> characters;
};

struct EntityController {
	void (*update)(Entity& entity, Game& game) = nullptr;
};

struct Entity {
	int entityId = -1;
	std::shared_ptr<Character> character = nullptr;
	EntityController controller;
};
