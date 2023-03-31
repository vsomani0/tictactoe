#ifndef TWO_PLAYER_TTT_H
#define TWO_PLAYER_TTT_H
#include "TicTacToe.h"
#include <string>
class TwoPlayerTTT: public TicTacToe {
public:
TwoPlayerTTT(int sides, const std::string& playerOneName, const std::string& playerTwoName);
void newGame();
std::string playerToMove() const; // Returns player who can make next move
std::string playerNotToMove() const; // Returns player who is currently playing but does not move next time.
std::string getPlayerOneName() const { return playerOneName; } 
std::string getPlayerTwoName() const { return playerTwoName; }
int numWins(const std::string&) const; 
private:
std::string playerOneName;
std::string playerTwoName;
friend void unitTest();
};
#endif