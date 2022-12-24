#ifndef TWO_PLAYER_TTT_H
#define TWO_PLAYER_TTT_H
#include "TicTacToe.h"
#include <string>
class TwoPlayerTTT: public TicTacToe {
public:
TwoPlayerTTT(int sides, std::string playerOneName, std::string playerTwoName);
void newGame() override;
std::string playerToMove() const;
std::string getPlayerOneName() const;
std::string getPlayerTwoName() const;
private:
std::string playerOneName;
std::string playerTwoName;
};
#endif