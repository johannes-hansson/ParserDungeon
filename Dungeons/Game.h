#pragma once

#include <memory>
#include "world_types.h"

void init_game(Game& game);
void update_game(Game& game);
void stop_game(Game& game);
bool is_running(Game& game);
Entity& add_entity(Game& game, Entity entity);
Entity* get_entity(Game& game, int entityId);
void remove_entity(Game& game, int entityId);
