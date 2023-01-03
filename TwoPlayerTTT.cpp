#include "TwoPlayerTTT.h"

TwoPlayerTTT::TwoPlayerTTT(int sides, std::string playerOneName, std::string playerTwoName): TicTacToe(sides), playerOneName(playerOneName), playerTwoName(playerTwoName){}
std::string TwoPlayerTTT::playerToMove() const {
if (turnNumber % 2 == 1) {
    return playerOneName;
}
return playerTwoName;
}
std::string TwoPlayerTTT::getPlayerOneName() const {
    return playerOneName;
}
std::string TwoPlayerTTT::getPlayerTwoName() const {
    return playerTwoName;
}
void TwoPlayerTTT::newGame() {
    TicTacToe::newGame();
}
int TwoPlayerTTT::numWins(std::string playerName) const {
if (playerName == playerOneName) {
    return TicTacToe::numWins('X');
}
else if (playerName == playerTwoName) {
    return TicTacToe::numWins('O');
}
return -1;
}