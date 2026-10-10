
#include <iostream>
#include "world_types.h"
#include "game.h"

int main() {
    Game game;

    init_game(game);

    while (is_running(game)) {
        update_game(game);
    }
}
