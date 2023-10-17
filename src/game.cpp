#include "game.hpp"

Game::Game(Player x_player, Player o_player) : x_player(x_player), o_player(o_player) {
    std::cout << "New game started" << std::endl;
}