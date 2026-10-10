#pragma once

#include <memory>
#include "world_types.h"

Entity create_player();
void update_entity(Entity& entity, Game& game);
void spawn(Entity& entity, World& world, int x, int y);
