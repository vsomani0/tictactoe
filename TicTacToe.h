#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream> 
#include <vector>

struct Coordinates {
    int row{-1};
    int col{-1};
};
class TicTacToe {
public:

TicTacToe(int sides);
virtual void newGame() = 0;
int getTurnNumber() const;
bool isWinnerDecided() const;
bool boardFull() const;

protected: 

std::vector<std::vector<char>> board;
int turnNumber;
bool isValidInput(Coordinates location) const;
void display() const;
};


#endif