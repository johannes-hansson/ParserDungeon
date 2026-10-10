#include "types.h"
#include "logic.h"

int main() {

	Game game;

	init_game(game);

	while (game.running) {
		update_game(game);
	}

	return 0;
}
