#include "logic.h"
#include "types.h"

int get_and_increment_entity_id(Game& game) {
	int entityId = game.nextEntityId;
	game.nextEntityId++;
	return entityId;
}

void init_game(Game& game) {
	game.running = true;
	game.player.characterId = get_and_increment_entity_id(game);
}

void update_game(Game& game) {
	
}

void stop_game(Game& game) {
	game.running = false;
}

int create_entity(Game& game) {
	std::unique_ptr<Entity> entityPtr = std::make_unique<Entity>();
	int entityId = get_and_increment_entity_id(game);
	entityPtr->entityId = entityId;
	game.entities[entityId] = std::move(entityPtr);
	return entityId;
}
