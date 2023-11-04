#include "game.hpp"
#include <iostream>
#include <string>

using namespace board;
using namespace game;
using namespace std;

ostream &game::operator << (ostream& os, Player player) {
    switch(player) {
        case Player::Human:
            os << "Human";
            break;
        case Player::Computer:
            os << "Computer";
            break;
        default:
            os << "?";
    }
    return os;
}

void Game::start_game() {
    cout << "Game between: " << endl << "X: " << this->x_player << endl << "O: " << this->o_player << endl;
    this->move_count = 0;
    this->move();
}

void game::Game::set_x_player(Player player) {
    this->x_player = player;
}

void game::Game::set_o_player(Player player) {
    this->o_player = player;
}

void Game::move() {
    this->board.print_board();
    size_t curr_player = move_count % 2;

    cout << "Move!" << endl;

    this->move_count++;
    if(move_count >= 9) {
        cout << "End of game" << endl;
        return;
    }
    this->move();
}