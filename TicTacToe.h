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
int playMove(const Coordinates& location);
bool boardFull() const;
void display() const;
bool empty() const;


protected: 

std::vector<std::vector<char>> board;
unsigned turnNumber;
bool isValidInput(const Coordinates& location) const;
bool tilesMatch(unsigned X1, unsigned Y1, unsigned X2, unsigned Y2, unsigned X3, unsigned Y3, char side) const;
int numMainDiagonalWins(char) const;
int numAltDiagonalWins(char) const;
int numHorizontalWins(char) const;
int numVerticalWins(char) const;
friend void unitTest();
};


#endif