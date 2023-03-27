#include "TwoPlayerTTT.h"
#include <cassert>
void unitTest() {
    TicTacToe t1 = TicTacToe(3);
    std::cout << "Initialized Board successfully!" << std::endl;
    assert(not t1.boardFull());
    assert(t1.board.size() == 3);
    assert(t1.getTurnNumber() == 1);
    assert(t1.numWins('O') == 0); 
    Coordinates loc = Coordinates(1,1);
    t1.playMove(loc);
    assert(t1.board.at(1).at(1) == 'X');
    assert(t1.getTurnNumber() == 2);
    assert(t1.numWins('O') == 0);
    t1.playMove(Coordinates(1,0)); // O
    assert(t1.board.at(1).at(0) == 'O');
    t1.playMove(Coordinates(0,0)); // X
    t1.playMove(Coordinates(2,0)); // O
    t1.playMove(Coordinates(2,2)); // X
    assert(t1.numWins('X') == 1);
    assert(t1.numWins('O') == 0);
    t1.newGame();
    assert(t1.empty());
    assert(t1.getTurnNumber() == 1);
    // Test vertical check for win
    t1.playMove(Coordinates(0,0));
    t1.playMove(Coordinates(1,0));
    t1.playMove(Coordinates(0,1));
    t1.playMove(Coordinates(1,1));
    t1.playMove(Coordinates(0,2));
    assert(t1.numWins('X') == 1);
    assert(t1.numWins('O') == 0);
    t1.playMove(Coordinates(1,2));
    assert(t1.numWins('O') == 1);
    assert(not t1.boardFull());
    t1.playMove(Coordinates(2,0));
    t1.playMove(Coordinates(2,1));
    t1.playMove(Coordinates(2,2));
    assert(t1.boardFull());
    assert(t1.numWins('X') == 1);
    assert(t1.numWins('O') == 1);
    t1.newGame();
    assert(t1.empty());
    // Testing for 5x5 now
    TicTacToe t2 = TicTacToe(5);
    t2.display();
    assert(t2.empty());
    assert(t2.getVectorSize() == 5);
    t2.playMove(Coordinates(2,2));
    t2.playMove(Coordinates(2,1));
    t2.playMove(Coordinates(1,1));
    t2.playMove(Coordinates(1,2));
    t2.playMove(Coordinates(0,0));
    t2.display();
    assert(t2.numWins('X') == 1);
    assert(t2.numWins('O') == 0);
    t2.playMove(Coordinates(2,3));
    t2.playMove(Coordinates(3,1));
    t2.playMove(Coordinates(1,1));
    t2.playMove(Coordinates(1,1));
    t2.display();

    std::cout << "All tests passed successfully!" << std::endl;
}
Coordinates getUserPos(Coordinates location) {
std::cout << "Enter a row number" << std::endl;
std::cin >> location.row;
std::cout << "Enter a column number" << std::endl;
std::cin >> location.col;
return location;
}

const TwoPlayerTTT initializeGame() {
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
TwoPlayerTTT game = TwoPlayerTTT(numRows, name, name2);
std::cout << "Tic-Tac-Toe game started" << std::endl;
game.display();
return game;
}

int main() {
unitTest();
// TwoPlayerTTT game = initializeGame();
// std::cout << "second display" << std::endl;
// game.display();
// Coordinates location;
// int moveSuccess{};
// while (!game.boardFull()) {
// game.display();
// std::cout << "It is " << game.playerToMove() << "\'s turn to move" << std::endl;
// location = getUserPos(location);
// moveSuccess = game.playMove(location);
// if (moveSuccess == 2) {
//     std::cout << "Tile not on board. Remember that the first row is 0, not 1. Try again." << std::endl;
// }
// else if (moveSuccess == 1) {
//     std::cout << "Tile already occupied. Try again." << std:: endl;
// }
// if (game.numWins(game.playerToMove()) > 0) {
//     std::cout << "Congratulations, " << game.playerToMove() << " has won the game" << std::endl;
//     game.display();
//     break;
// }
// }
return 0;
}