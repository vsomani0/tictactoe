#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream> 
#include <vector>

struct Coordinates {
    int row;
    int col;
    Coordinates(int row, int col): row(row), col(col) {}
    Coordinates(): row(0), col(0) {}
};
class TicTacToe {
public:

TicTacToe(int sides);
void newGame();
int getVectorSize() const { return board.size(); }
int getTurnNumber() const;
int numWins(char) const;
bool boardFull() const;
int playMove(Coordinates location);
void display() const;

protected: 

std::vector<std::vector<char>> board;
unsigned turnNumber;
bool isValidInput(Coordinates location) const;
int numMainDiagonalWins(char) const;
int numAltDiagonalWins(char) const;
int numHorizontalWins(char) const;
int numVerticalWins(char) const;
friend void unitTest();
};


#endif