
#include <iostream>

using namespace std;

int num1;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void DrawBoard() {
    cout << "\n\t\t-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "\t\t| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n";
        cout << "\t\t-------------\n";
    }
}

void Logic(char letter, int num) {
    if (num == 1) board[0][0] = letter;
    if (num == 2) board[0][1] = letter;
    if (num == 3) board[0][2] = letter;
    if (num == 4) board[1][0] = letter;
    if (num == 5) board[1][1] = letter;
    if (num == 6) board[1][2] = letter;
    if (num == 7) board[2][0] = letter;
    if (num == 8) board[2][1] = letter;
    if (num == 9) board[2][2] = letter;
}

bool CheckWin(char letter) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == letter && board[i][1] == letter && board[i][2] == letter) 
            return true;
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == letter && board[1][j] == letter && board[2][j] == letter) 
            return true;
    }
    if (board[0][0] == letter && board[1][1] == letter && board[2][2] == letter) 
        return true;
    if (board[0][2] == letter && board[1][1] == letter && board[2][0] == letter) 
        return true;
    return false;
}

bool MovesLeft() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return true;
        }
    }
    return false;
}

int main() {
    cout << "\tWelcome to 2 player TicTacToe!\n";
    cout << "To make a selection, enter the number of the square you want.\n";
    char turn = 'X';
    while (true) {
        DrawBoard();
        cout << "Player " << turn << ", enter your move (1-9): ";
        cin >> num1;
        Logic(turn, num1);
        if (CheckWin(turn)) {
            DrawBoard();
            cout << "Player " << turn << " wins!\n";
            break;
        }
        if (!MovesLeft()) {
            DrawBoard();
            cout << "It's a tie!\n";
            break;
        }
        turn = (turn == 'X') ? 'O' : 'X';
    }
    return 0;
}
