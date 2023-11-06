#include "game.hpp"
#include "computer.hpp"

#include <iostream>
#include <string>

using namespace board;
using namespace game;
using namespace std;

ostream& game::operator<<(ostream& os, PlayerMode player_mode) {
    switch (player_mode) {
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

Coordinates Game::computer_move(std::optional<computer::Computer> computer_opt) {
    if(!computer_opt.has_value()) {
        cerr << "Error: No computer found for current player. Making random move\n";
        size_t i = rand() % 3;
        size_t j = rand() % 3;
        return board::Coordinates(i, j);
    }
    computer::Computer computer = computer_opt.value();
    return computer.make_move();
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
                curr_move = this->computer_move((curr_player_symbol == Symbol::X ? this->x_computer : this->o_computer));
            }
        } while (!this->verify_move(curr_move));

        this->board.set_field(curr_move, curr_player_symbol);

        Symbol winner = this->check_board();
        if (winner != Symbol::None) {
            cout << winner << " wins!" << endl;
            this->board.print_board();
            return winner;
        }
    }

    cout << "It's a draw!" << endl;
    this->board.print_board();
    return Symbol::None;
}

void game::Game::set_x_player_mode(PlayerMode player_mode) {
    this->x_player_mode = player_mode;
    if(player_mode == PlayerMode::Computer) {
        this->x_computer = computer::Computer();
    } else {
        this->x_computer = {};
    }
}

void game::Game::set_o_player_mode(PlayerMode player_mode) {
    this->o_player_mode = player_mode;
    if(player_mode == PlayerMode::Computer) {
        this->o_computer = computer::Computer();
    } else {
        this->o_computer = {};
    }
}