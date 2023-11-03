#include "game.hpp"

using namespace board;
using namespace game;
using namespace std;

Game::Game(Player x_player, Player o_player) : x_player(x_player), o_player(o_player) {
    cout << "New game started" << endl;
}