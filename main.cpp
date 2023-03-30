#include "TwoPlayerTTT.h"
#include <cassert>
#include <cctype>

std::string& getCasefold(std::string& input) {
    for (int i = 0; i < input.length(); ++i) {
        input[i] = tolower(input[i]);
    }
    return input;
}

void unitTest() {
    TicTacToe t1 = TicTacToe(3);
    std::cout << "Initialized Board successfully!" << std::endl;
    assert(!t1.boardFull());
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
    assert(!t1.boardFull());
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
    t2.playMove(1, 1);
    assert(t2.board.at(1).at(1) == 'X');
    t2.newGame();
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
    t2.playMove(Coordinates(1,1)); // Shouldn't do anything
    t2.playMove(0, 3);
    t2.playMove(5, 0); // Shouldn't do anything
    assert(t2.numWins('O') == 1);
    t2.playMove(3, 3); // X
    t2.playMove(1, 3); // O
    assert(t2.numWins('X') == 2);
    assert(t2.numWins('O') == 2);
    t2.playMove(4, 0);
    assert(t2.numWins('X') == 3);
    t2.playMove(1, 0);
    assert(t2.numVerticalWins('O') == 1);
    assert(t2.numHorizontalWins('O') == 0);
    assert(t2.numAltDiagonalWins('O') == 1);
    assert(t2.numMainDiagonalWins('O') == 0);
    assert(t2.numWins('O') == 2);
    t2.playMove(4, 1);
    t2.playMove(2, 0); // O
    assert(t2.numWins('X') == 3);
    t2.playMove(4, 2);
    assert(t2.numWins('X') == 4);
    assert(t2.numHorizontalWins('X') == 1);
    assert(t2.numMainDiagonalWins('X') == 2);
    t2.playMove(3, 0);
    t2.playMove(4, 3); // X
    assert(t2.numWins('X') == 5);
    assert(t2.numWins('O') == 4);
    t2.playMove(0, 1);
    t2.playMove(3, 2);
    t2.playMove(0, 2);
    assert(t2.numWins('O') == 6);
    t2.playMove(4, 4); // X
    assert(t2.numHorizontalWins('X') == 4);
    assert(t2.numVerticalWins('X') == 1);
    assert(t2.numAltDiagonalWins('X') == 1);
    assert(t2.numMainDiagonalWins('X') == 3);
    assert(t2.numWins('X') == 9);
    t2.playMove(0, 4);
    t2.playMove(1, 4);
    t2.playMove(2, 4);
    assert(!t2.boardFull());
    t2.playMove(3, 4);
    assert(t2.boardFull());
    t2.display();
    t2.newGame();
    assert(t2.getTurnNumber() == 1);
    assert(t2.getVectorSize() == 5);
    assert(t2.numWins('X') == 0);
    assert(t2.numWins('O') == 0);
    assert(t2.empty()); 
    
    std::cout << "All tests passed successfully!" << std::endl;
}
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
if (getCasefold(gameEnd) == "yes") {
    quickEnd = 1;
}
TwoPlayerTTT game = TwoPlayerTTT(numRows, name, name2);
std::cout << "Tic-Tac-Toe game started" << std::endl;
game.display();
return game;
}

int main() {
unitTest();
TwoPlayerTTT game = initializeGame();
std::cout << "second display" << std::endl;
game.display();
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