#include "board.hpp"

/**
 * @brief Enum showing whether current player is to be human or an AI opponent 
*/
typedef enum _Player {HUMAN, COMPUTER} Player;

/**
 * @brief Class managing current game
*/
class Game {
    private:
        Board board;
        size_t move;
        Player x_player;
        Player o_player;
    public:
        Game(Player, Player);
};