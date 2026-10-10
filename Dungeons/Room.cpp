#include "room.h"

using namespace std;

void add_character_to_room(Room& room, shared_ptr<Character> character) {
	room.characters.emplace(character->characterId, character);
}

void remove_character_from_room(Room& room, int characterId) {
	room.characters.erase(characterId);
}

const unordered_map<int, shared_ptr<Character>>& get_characters(Room& room) {
	return room.characters;
}
