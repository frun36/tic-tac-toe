#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;
using namespace game;

int main(void) {
    Game game (Player::Human, Player::Human);
    game.start_game();
    return 0;
}