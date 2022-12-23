#include "TicTacToe.h"

TicTacToe::TicTacToe(int sides) {
    std::vector<std::vector<char>> board(sides, std::vector<char>(sides, '-'));
    turnNumber = 1;
}
bool TicTacToe::boardFull() const{
    if (turnNumber <= board.size()*board.size()) {
        return false;
    }
    return true;
}
int TicTacToe::getTurnNumber() const {
return turnNumber;
}

void TicTacToe::newGame(){
    for (int y = 0; y < board.size(); y++)
{
        for (int x = 0; x < board[y].size(); x++)
    {
            board[y][x] = '-';
    }
}
turnNumber = 0;
}
bool TicTacToe::isValidInput(Coordinates location) const {
    if (location.row < 0 || location.row > board.size()) {
        return false;
    }
    if (location.col < 0 || location.col > board.size()) {
        return false;
    }
    return true;
}
bool TicTacToe::isWinnerDecided() const{
char testChar{};

for (int i = 0; i < board.size(); ++i) {
    testChar = board.at(i).at(0);
    if (testChar == '-') {
        continue;
    }
    for (int j = 0; j < board.at(0).size(); ++j) {
        if (board.at(i).at(j) != testChar) {
            break;
        }
        return true;
    }
}
for (int j = 0; j < board.at(0).size(); ++j) {
    testChar = board.at(0).at(j);
    if (testChar == '-') {
        continue;
    }
    for (int i = 0; i < board.size(); ++i) {
        if (board.at(i).at(j) != testChar) {
            break;
        }
        return true;
    }
}
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
void TicTacToe::display() const{
    unsigned int i{};
    unsigned int j{};
    for (i = 0; i < board.size(); ++i) {
        std::cout << std::endl;
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
        }
    }
    std::cout << std::endl;
}


