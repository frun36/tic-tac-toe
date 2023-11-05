#include <cstdlib>
#include <iostream>
#include <ctime>

#include "board.hpp"
#include "game.hpp"

using namespace std;
using namespace game;

int main(void) {
    std::srand(std::time(NULL));
    Game game;
    int x_player_mode, o_player_mode;
    cout << "Select X player mode: (0 - Human, 1 - Computer): ";
    cin >> x_player_mode;
    cout << "Select O player mode: (0 - Human, 1 - Computer): ";
    cin >> o_player_mode;

    game.set_x_player_mode((PlayerMode) x_player_mode);
    game.set_o_player_mode((PlayerMode) o_player_mode);
    game.play();
    return 0;
}