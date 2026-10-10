#include <stdexcept>
#include "game.h"
#include "entity.h"
#include "world_types.h"

using namespace std;

static int get_and_increment_entity_id(Game& game) {
	int id = game.nextEntityId;
	game.nextEntityId++;
	return id;
}

void init_game(Game& game) {
	game.running = true;
	Entity& player = add_entity(game, create_player());
	spawn(player, game.world, 0, 0);
	player.entityId = 199;
}

void update_game(Game& game) {
	for (auto it = game.entities.begin(); it != game.entities.end(); it++) {
		update_entity(it->second, game);
	}
}

void stop_game(Game& game) {
	game.running = false;
}

bool is_running(Game& game) {
	return game.running;
}

Entity& add_entity(Game& game, Entity entity) {
	int entityId = get_and_increment_entity_id(game);
	entity.entityId = entityId;
	auto [it, inserted] = game.entities.emplace(entityId, std::move(entity));
	if (inserted == false) {
		throw(exception("ID collision when adding entity to game."));
	}
	return it->second;
}

Entity* get_entity(Game& game, int entityId) {
	auto it = game.entities.find(entityId);
	if (it == game.entities.end()) {
		return nullptr;
	}
	return &it->second;
}

void remove_entity(Game& game, int entityId) {
	game.entities.erase(entityId);
}
