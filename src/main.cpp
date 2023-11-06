#include <cstdlib>
#include <iostream>
#include <ctime>

#include "board.hpp"
#include "game.hpp"


int main(void) {
    std::srand(std::time(NULL));
    game::Game game;
    int x_player_mode, o_player_mode;
    std::cout << "Select X player mode: (0 - Human, 1 - Computer): ";
    std::cin >> x_player_mode;
    std::cout << "Select O player mode: (0 - Human, 1 - Computer): ";
    std::cin >> o_player_mode;

    game.set_x_player_mode((game::PlayerMode) x_player_mode);
    game.set_o_player_mode((game::PlayerMode) o_player_mode);
    game.play();
    return 0;
}