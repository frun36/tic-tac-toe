#include "game.hpp"

#include <iostream>
#include <string>

using namespace board;
using namespace game;
using namespace std;

ostream& game::operator<<(ostream& os, PlayerMode player) {
    switch (player) {
        case PlayerMode::Human:
            os << "Human";
            break;
        case PlayerMode::Computer:
            os << "Computer";
            break;
        default:
            os << "?";
    }
    return os;
}

Coordinates Game::player_move() {
    cout << "Enter field number (1-9): ";
    size_t field_nr, i, j;
    cin >> field_nr;
    i = (field_nr - 1) / 3;
    j = (field_nr - 1) % 3;
    return Coordinates (i, j);
}

Coordinates Game::computer_move() {
    return Coordinates (0, 0);
}

bool Game::verify_move(Coordinates coordinates) {
    if (this->board.get_field(coordinates) != Symbol::None) {
        return false;
    } else {
        return true;
    }
}

Symbol Game::check_board() {
    Symbol cols = this->board.check_cols();
    Symbol rows = this->board.check_rows();
    Symbol diags = this->board.check_diags();
    if (cols != Symbol::None) {
        return cols;
    }
    if (rows != Symbol::None) {
        return rows;
    }
    if (diags != Symbol::None) {
        return diags;
    }
    return Symbol::None;
}

Symbol Game::play() {
    cout << "Game between:\nX: " << this->x_player_mode << "\nO: " << this->o_player_mode << endl;
    for (; this->move_count < 9; this->move_count++) {
        Symbol curr_player_symbol = this->move_count % 2 == 0 ? Symbol::X : Symbol::O;
        PlayerMode curr_player_mode = curr_player_symbol == Symbol::X ? this->x_player_mode : this->o_player_mode;
        Coordinates curr_move (0, 0);

        cout << curr_player_symbol << "'s move" << endl;
        this->board.print_board();

        do {
            if (curr_player_mode == PlayerMode::Human) {
                curr_move = this->player_move();
            } else {
                curr_move = this->computer_move();
            }
        } while (!this->verify_move(curr_move));

        this->board.set_field(curr_move, curr_player_symbol);

        Symbol winner = this->check_board();
        if (winner != Symbol::None) {
            this->board.print_board();
            cout << winner << " wins!" << endl;
            return winner;
        }
    }

    cout << "It's a draw!" << endl;
    return Symbol::None;
}

void game::Game::set_x_player_mode(PlayerMode player) {
    this->x_player_mode = player;
}

void game::Game::set_o_player_mode(PlayerMode player) {
    this->o_player_mode = player;
}