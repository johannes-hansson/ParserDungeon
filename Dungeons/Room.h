#pragma once

#include "world_types.h"

void add_character_to_room(Room& room, std::shared_ptr<Character> character);
void remove_character_from_room(Room& room, int characterId);
const std::unordered_map<int, std::shared_ptr<Character>>& get_characters(Room& room);
