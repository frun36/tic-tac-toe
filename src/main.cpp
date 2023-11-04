#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;
using namespace game;

int main(void) {
    Game game;
    game.set_x_player(Player::Human);
    game.set_o_player(Player::Human);
    game.start_game();
    return 0;
}