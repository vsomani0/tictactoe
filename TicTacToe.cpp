#include "TicTacToe.h"

TicTacToe::TicTacToe(int sides)
{
    std::vector<std::vector<char>> board(sides, std::vector<char>(sides, '-'));
    turnNumber = 1;
}
bool TicTacToe::boardFull() const
{
    if (turnNumber <= board.size() * board.size())
    {
        return false;
    }
    return true;
}
int TicTacToe::getTurnNumber() const
{
    return turnNumber;
}

void TicTacToe::newGame()
{
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            board[y][x] = '-';
        }
    }
    turnNumber = 0;
}
bool TicTacToe::isValidInput(Coordinates location) const
{
    if (location.row < 0 || location.row > board.size())
    {
        return false;
    }
    if (location.col < 0 || location.col > board.size())
    {
        return false;
    }
    return true;
}
int TicTacToe::numAltDiagonalWins(char side) const {
int sumWins{};
    for (int i = 2; i < board.size(); ++i)
    { 
        for (int j = 0; j < board.at(0).size(); ++j)
        {
            if (board.at(i).at(j) && board.at(i-1).at(j+1) == side && board.at(i-2).at(j+2) == side)
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}
int TicTacToe::numMainDiagonalWins(char side) const {;
int sumWins{};
    for (int i = 0; i < board.size() - 2; ++i)
    { 
        for (int j = 0; j < board.at(0).size() - 2; ++j)
        {
            if (board.at(i).at(j) && board.at(i+1).at(j+1) == side && board.at(i+2).at(j+2) == side)
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}
int TicTacToe::numHorizontalWins(char side) const {
int sumWins{};
    for (int i = 0; i < board.size() - 2; ++i)
    { 
        for (int j = 0; j < board.at(0).size(); ++j)
        {
            if (board.at(i).at(j) && board.at(i+1).at(j) == side && board.at(i+2).at(j) == side)
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}
int TicTacToe::numVerticalWins(char side) const {
int sumWins{};
    for (int i = 0; i < board.size(); ++i)
    { 
        for (int j = 0; j < board.at(0).size() - 2; ++j)
        {  
            if (board.at(i).at(j) && board.at(i).at(j+1) == side && board.at(i).at(j+2) == side)
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}
int TicTacToe::numWins(char side) const
{
    return numVerticalWins(side) + numHorizontalWins(side) + numAltDiagonalWins(side) + numMainDiagonalWins(side);
    // if ((board.at(0).at(0) == board.at(1).at(1)) && (board.at(1).at(1) == board.at(2).at(2)) && (board.at(0).at(0)!= '-')) {
    //         return true;
    // }
    // if ((board.at(2).at(0) == board.at(1).at(1)) && (board.at(1).at(1) == board.at(0).at(2)) && (board.at(2).at(0)!= '-')) {
    //         return true;
    //     }
    // for (int i = 0; i < board.size();++i) {
    //     if ((board.at(i).at(0) == board.at(i).at(1)) && (board.at(i).at(0) == board.at(i).at(2)) && (board.at(i).at(0)!= '-')) {
    //         return true;
    //     }
    //     if ((board.at(0).at(i) == board.at(1).at(i)) && (board.at(0).at(i) == board.at(2).at(i)) && (board.at(i).at(0) != '-')) {
    //         return true;
    //     }
    //     }
    //     return false;
}
void TicTacToe::display() const
{
    unsigned int i{};
    unsigned int j{};
    for (i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            std::cout << board[i][j] << std::endl;;
        }
    }
    std::cout << std::endl;
}
int TicTacToe::playMove(Coordinates location) {
char input;
if (turnNumber % 2 == 1) {
    input = 'X';
}
else {
    input = 'O';
}
if (!isValidInput(location)) {
    return 2;
}
if (board.at(location.row).at(location.col) != '-') {
    return 1;
}
board.at(location.row).at(location.col) = input;
turnNumber++;
return 0;
}