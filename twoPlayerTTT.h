#ifndef TWO_PLAYER_TTT_H
#define TWO_PLAYER_TTT_H
#include "TicTacToe.h"
#include <string>
class twoPlayerTTT: public TicTacToe {
public:
twoPlayerTTT(int sides, std::string playerOneName, std::string playerTwoName);
std::string playerToMove() const;
std::string getPlayerOneName() const;
std::string getPlayerTwoName() const;
private:
std::string playerOneName;
std::string playerTwoName;
};
#endif