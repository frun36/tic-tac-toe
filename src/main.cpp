#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;
using namespace game;

int main(void) {
    Game game;
    game.set_x_player_mode(PlayerMode::Human);
    game.set_o_player_mode(PlayerMode::Human);
    game.play();
    return 0;
}