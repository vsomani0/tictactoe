#ifndef TWO_PLAYER_TTT_H
#define TWO_PLAYER_TTT_H
#include "TicTacToe.h"
#include <string>
class TwoPlayerTTT: public TicTacToe {
public:
TwoPlayerTTT(int sides, const std::string& playerOneName, const std::string& playerTwoName);
void newGame();
std::string playerToMove() const;
std::string getPlayerOneName() const;
std::string getPlayerTwoName() const;
int numWins(std::string) const; 
private:
std::string playerOneName;
std::string playerTwoName;
};
#endif