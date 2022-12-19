#include <iostream>
#include <vector>

using namespace std;
struct Coordinates {
int row{-1};
int column{-1};
};
bool checkForWinner(const vector<vector<char>>& board) {
unsigned int i{};
unsigned int j{};
if ((board.at(0).at(0) == board.at(1).at(1)) && (board.at(1).at(1) == board.at(2).at(2)) && (board.at(0).at(0)!= '-')) {
        return true;
}
if ((board.at(2).at(0) == board.at(1).at(1)) && (board.at(1).at(1) == board.at(0).at(2)) && (board.at(2).at(0)!= '-')) {
        return true;
    }
for (int i = 0; i < board.size();++i) {
    if ((board.at(i).at(0) == board.at(i).at(1)) && (board.at(i).at(0) == board.at(i).at(2)) && (board.at(i).at(0)!= '-')) {
        return true;
    } 
    if ((board.at(0).at(i) == board.at(1).at(i)) && (board.at(0).at(i) == board.at(2).at(i)) && (board.at(i).at(0) != '-')) {
        return true;
    }
    }
    return false;
}
void display(const vector<vector<char>>& board) {
    unsigned int i{};
    unsigned int j{};
    for (i = 0; i < board.size(); ++i) {
        cout << endl;
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
        }
    }
    cout << endl;
}

void getUserInput(Coordinates & location, const vector<vector<char>>& board) { 
bool success{0};
while (!success && !cin.fail()) {
display(board);
cout << "Enter a row and column #, format: \"RowNumber ColNumber\")" << endl;
int rowNum{-1};
int colNum{-1};
cin >> rowNum;
cin >> colNum; 
if ((rowNum <= 3 && rowNum >= 1) && (colNum <= 3 && colNum >= 1)) {
    if (board.at(rowNum-1).at(colNum-1) == '-') {
        location.row = rowNum;
        location.column = colNum;
        success = 1;
    }
    else {
        cout << "Tile already occupied. Try again." << endl;
}
}
else {
    cout << "Invalid format, rowNumber and ColNumber must be between 1 and 3." << endl;
}
}
exit(1);
}

int main() {
    vector<vector<char>> board{{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    bool playerOneWins{0};
    bool playerTwoWins{};
    Coordinates location;
    int turnNumber{1};
    while(!playerOneWins && !playerTwoWins && turnNumber <= 9) {
        if (turnNumber % 2 == 0) {
        std::cout << "It is player 2's turn" << endl;
        getUserInput(location, board);
        board.at(location.row - 1).at(location.column - 1) = 'O';
        turnNumber++;
        playerTwoWins = checkForWinner(board);
        }
        else {
            std::cout << "It is player 1's turn" << endl;
            getUserInput(location, board);
            board.at(location.row-1).at(location.column-1) = 'X';
            turnNumber++;
            playerOneWins = checkForWinner(board);
        }

    }
    display(board);
   if (playerOneWins) {
    cout << "Congratulations player one! You win." << endl;
   }
   else if (playerTwoWins) {
    cout << "Congratulations player one! You win." << endl;
   }
   else {
    cout << "The game ended in a tie" << endl;
   }
    return 0;
   
}