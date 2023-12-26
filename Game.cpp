//TIC-TAC-TOE GAME


#include <bits/stdc++.h>
using namespace std;


void initializeBoard(vector<vector<char>> &board);
void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char currentPlayer);
bool checkWin(const vector<vector<char>> &board, char currentPlayer);
bool checkDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        initializeBoard(board);
        displayBoard(board);

        while (!checkWin(board, currentPlayer) && !checkDraw(board)) {
            if (makeMove(board, currentPlayer)) {
                displayBoard(board);
                if (checkWin(board, currentPlayer)) {
                    cout << "\nPlayer " << currentPlayer << " wins!\n";
                } else if (checkDraw(board)) {
                    cout << "\nIt's a draw!\n";
                } else {
                    switchPlayer(currentPlayer);
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    } while (playAgain());

    cout << "Thanks for playing!\n";

    return 0;
}

void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "\n   1   2   3\n";
    cout << "  +---+---+---+\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n  +---+---+---+\n";
    }
}

bool makeMove(vector<vector<char>> &board, char currentPlayer) {
    int row, col;
    cout << "\nPlayer " << currentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;
    --row; 
    --col;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

bool checkWin(const vector<vector<char>> &board, char currentPlayer) {
    // Checking rows, columns, and diagonals of the board given by the player 
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
   
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; //if the board is full, return it true as draw...
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "\nWanna play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
