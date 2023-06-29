#include "twoPlayerTTT.h"

TwoPlayerTTT::TwoPlayerTTT(int sides, const std::string& playerOneName, const std::string& playerTwoName): TicTacToe(sides), playerOneName(playerOneName), playerTwoName(playerTwoName){}
std::string TwoPlayerTTT::playerToMove() const {
if (turnNumber % 2 == 1) {
    return playerOneName;
}
return playerTwoName;
}
std::string TwoPlayerTTT::playerNotToMove() const {
if (turnNumber % 2 == 1) {
    return playerTwoName;
}
return playerOneName;
}

void TwoPlayerTTT::newGame() {
    TicTacToe::newGame();
}
int TwoPlayerTTT::numWins(const std::string& playerName) const {
if (playerName == playerOneName) {
    return TicTacToe::numWins('X');
}
else if (playerName == playerTwoName) {
    return TicTacToe::numWins('O');
}
return -1;
}