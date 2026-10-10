#pragma once

#include "world_types.h"

std::shared_ptr<Character> create_character(World& world);
std::shared_ptr<Character> create_character(World& world, int x, int y);
void move_character(
	World& world, 
	const std::shared_ptr<Character>& character, 
	const std::shared_ptr<Room>& destination
);
Room* find_room_of_character(World& world, int characterId);
void remove_character(World& world, int characterId);
const std::shared_ptr<Room>& get_room(World& world, int x, int y);
