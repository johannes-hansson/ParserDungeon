#include "world.h"
#include "world_types.h"
#include "room.h"

using namespace std;

// Private

static string get_position_encoding(int x, int y) {
	return to_string(x) + ":" + to_string(y);
}

static int get_and_increment_character_id(World& world) {
	int id = world.nextCharacterId;
	world.nextCharacterId++;
	return id;
}

static shared_ptr<Room> create_room(int x, int y) {
	shared_ptr<Room> room = make_shared<Room>();
	return room;
}

static shared_ptr<Character> create_character(World& world, const shared_ptr<Room>& room) {
	int characterId = get_and_increment_character_id(world);
	shared_ptr<Character> characterPtr = make_shared<Character>();
	characterPtr->characterId = characterId;
	move_character(world, characterPtr, room);
	return characterPtr;
}

// Public

void move_character(
	World& world, 
	const shared_ptr<Character>& character, 
	const shared_ptr<Room>& destination) 
{
	auto it = world.characterSpacialMap.find(character->characterId);
	if (it != world.characterSpacialMap.end()) {
		remove_character_from_room(*it->second, character->characterId);
		it->second = destination;
	} else {
		world.characterSpacialMap.emplace(character->characterId, destination);
	}
	add_character_to_room(*destination, character);
}

shared_ptr<Character> create_character(World& world) {
	return create_character(world, nullptr);
}

shared_ptr<Character> create_character(World& world, int x, int y) {
	return create_character(world, get_room(world, x, y));
}

const shared_ptr<Room>& get_room(World& world, int x, int y) {
	string positionId = get_position_encoding(x, y);
	auto it = world.rooms.find(positionId);
	if (it != world.rooms.end()) {
		return it->second;
	}

	shared_ptr<Room> roomPtr = create_room(x, y);
	auto [it2, inserted] = world.rooms.emplace(positionId, std::move(roomPtr));
	return it2->second;
}

Room* find_room_of_character(World& world, int characterId) {
	auto it = world.characterSpacialMap.find(characterId);
	if (it == world.characterSpacialMap.end()) {
		return nullptr;
	}
	return it->second.get();
}

void remove_character(World& world, int characterId) {
	Room* room = find_room_of_character(world, characterId);
	if (room != nullptr) {
		remove_character_from_room(*room, characterId);
	}
	world.characterSpacialMap.erase(characterId);
}
