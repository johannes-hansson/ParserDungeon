#include "entity.h"

#include <iostream>
#include "world.h"
#include "world_types.h"

#include "input.h"

using namespace std;

// Private

static void update_player_entity(Entity& entity, Game& game) {
	if (entity.character == nullptr) {
		cout << "Updating Player: Player does not have a character\n";
		return;
	}
	World& world = game.world;
	Character character = *entity.character;
	Room* room = find_room_of_character(world, character.characterId);
	if (room == nullptr) {
		cout << "Updating Player: Player is not in a room\n";
		return;
	}
	vector<string> command = take_command("Enter a command: ");
	for (int i = 0; i < command.size(); i++) {
		cout << command[i] << endl;
	}
}

EntityController playerController{
	.update = &update_player_entity
};

// Public

void spawn(Entity& entity, World& world, int x, int y) {
	if (entity.entityId == -1) {
		cout << "Could not spawn entity. Invalid entity id\n";
		return;
	}
	
	if (entity.character != nullptr) {
		remove_character(world, entity.character->characterId);
	}

	entity.character = create_character(world, x, y);
	entity.character->characterId = entity.entityId;
}

Entity create_player() {
	return Entity{
		.controller = playerController
	};
}

void update_entity(Entity& entity, Game& game) {
	if (entity.controller.update != nullptr) {
		entity.controller.update(entity, game);
	}
}
