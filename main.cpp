#include "TwoPlayerTTT.h"
Coordinates getUserPos(Coordinates location) {
std::cout << "Enter a row number" << std::endl;
std::cin >> location.row;
std::cout << "Enter a column number" << std::endl;
std::cin >> location.col;
return location;
}
TwoPlayerTTT initializeGame() {
std::cout << "Enter Player 1 name" << std::endl;
std::string name{};
std::getline(std::cin, name);
std::cout << "Enter Player 2 name" << std::endl;
std::string name2{};
std::getline(std::cin, name);
int numRows{};
std::cout << "How many rows do you want to use?" << std::endl;
std::cin >> numRows;
std::cout << "Do you want the game to end as soon as one player gets a TicTacToe, and not wait until the whole board is full? Type \'yes\' to make the game end with one TicTacToe" << std::endl;
std::string gameEnd;
std::cin >> gameEnd;
bool quickEnd{0};
if (gameEnd == "yes" || gameEnd == "Yes" || gameEnd == "YEs" || gameEnd == "YES") {
    quickEnd = 1;
}
TwoPlayerTTT game(numRows, name, name2);
std::cout << "Tic-Tac-Toe game started" << std::endl;
return game;
}
int main() {
TwoPlayerTTT game = initializeGame();
Coordinates location;
int moveSuccess{};
while (!game.boardFull()) {
game.display();
std::cout << "It is " << game.playerToMove() << "\'s turn to move" << std::endl;
location = getUserPos(location);
moveSuccess = game.playMove(location);
if (moveSuccess == 2) {
    std::cout << "Tile not on board. Remember that the first row is 0, not 1. Try again." << std::endl;
}
else if (moveSuccess == 1) {
    std::cout << "Tile already occupied. Try again." << std:: endl;
}
if (game.numWins(game.playerToMove()) > 0) {
    std::cout << "Congratulations, " << game.playerToMove() << " has won the game" << std::endl;
    game.display();
    break;
}
}
return 0;
}