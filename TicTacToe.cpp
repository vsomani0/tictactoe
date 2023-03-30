#include "TicTacToe.h"

TicTacToe::TicTacToe(int sides)
{
    board = std::vector<std::vector<char>>(sides, std::vector<char>(sides));
    for (unsigned y = 0; y < board.size(); y++)
    {
        for (unsigned x = 0; x < board[y].size(); x++)
        {
            board[y][x] = '-';
        }
    }
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
    for (unsigned y = 0; y < board.size(); y++)
    {
        for (unsigned x = 0; x < board[y].size(); x++)
        {
            board[y][x] = '-';
        }
    }
    turnNumber = 1;
}
bool TicTacToe::isValidInput(const Coordinates &location) const
{
    if (location.row < 0 || location.row >= board.size())
    {
        return false;
    }
    if (location.col < 0 || location.col >= board.size())
    {
        return false;
    }
    return true;
}
int TicTacToe::numWins(char side) const
{
    return numVerticalWins(side) + numHorizontalWins(side) + numMainDiagonalWins(side) + numAltDiagonalWins(side);
}

bool TicTacToe::tilesMatch(unsigned X1, unsigned Y1, unsigned X2, unsigned Y2, unsigned X3, unsigned Y3, char side) const
{
    // Tiles compared in pairs
    return ((board.at(X1).at(Y1) == side) && (board.at(X2).at(Y2) == side) && (board.at(X3).at(Y3) == side));
}
int TicTacToe::numAltDiagonalWins(char side) const
{
    int sumWins{};
    for (unsigned i = 2; i < board.size(); ++i)
    // I gets subtracted with alt diagonal. Start at 2 to stay in range.
    {
        // Stop at 2 extra to stay in range.
        for (unsigned j = 0; j + 2 < board.at(0).size(); ++j)
        {
            if (tilesMatch(i, j, i - 1, j + 1, i - 2, j + 2, side))
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}

int TicTacToe::numMainDiagonalWins(char side) const
{
    ;
    int sumWins{};
    for (unsigned i = 0; i + 2 < board.size(); ++i)
    {
        for (unsigned j = 0; j + 2 < board.at(0).size(); ++j)
        {
            if (tilesMatch(i, j, i + 1, j + 1, i + 2, j + 2, side))
            {
                sumWins++;
            }
        }
    }
    return sumWins;
}
int TicTacToe::numVerticalWins(char side) const
{
    int sumWins{};
    for (unsigned i = 0; i + 2 < board.size(); ++i)
    {
        // All rows before last 2 have 3 consecutive elements checked
        for (unsigned j = 0; j < board.at(0).size(); ++j)
        {
            // Check in each column
            if (tilesMatch(i, j, i + 1, j, i + 2, j, side))
            {
                sumWins++;
            }
        }
        
    }
    return sumWins;
}
    int TicTacToe::numHorizontalWins(char side) const
    {
        int sumWins{};
        for (unsigned i = 0; i < board.size(); ++i)
        {
            // Verticals for all rows
            for (unsigned j = 0; j + 2 < board.at(0).size(); ++j)
            {
                // All columns before last 2 have 3 extra checked.
                if (this->tilesMatch(i, j, i, j + 1, i, j + 2, side))
                {
                    sumWins++;
                }
            }
        }
        return sumWins;
    }
void TicTacToe::display() const
{
    unsigned int i{};
    unsigned int j{};
    for (i = 0; i < board.size(); ++i)
    {
        for (unsigned j = 0; j < board[i].size(); ++j)
        {
            std::cout << board.at(i).at(j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int TicTacToe::playMove(const Coordinates &location)
{
    char input;
    if (turnNumber % 2 == 1)
    {
        input = 'X';
    }
    else
    {
        input = 'O';
    }
    if (!isValidInput(location))
    {
        return -2;
    }
    if (board.at(location.row).at(location.col) != '-')
    {
        return -1;
    }
    board.at(location.row).at(location.col) = input;
    turnNumber++;
    return 0;
}

bool TicTacToe::empty() const
{
    for (unsigned i = 0; i < board.size(); ++i)
    {
        for (unsigned j = 0; j < board.at(i).size(); ++j)
        {
            if (board.at(i).at(j) != '-')
            {
                return false;
            }
        }
    }
    // All squares are dashes
    return true;
}
