#include "TwoPlayerTTT.h"
twoPlayerTTT::twoPlayerTTT(int sides, std::string playerOneName, std::string playerTwoName): TicTacToe(sides), playerOneName(playerOneName), playerTwoName(playerTwoName){}
std::string twoPlayerTTT::playerToMove() const {
if (turnNumber % 2 == 1) {
    return playerOneName;
}
return playerTwoName;
}
std::string twoPlayerTTT::getPlayerOneName() const {
    return playerOneName;
}
std::string twoPlayerTTT::getPlayerTwoName() const {
    return playerTwoName;
}