#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin() {
    // Check rows, columns and diagonals for a win
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void playerMove(char player) {
    int choice;
    cout << "Player " << player << ", enter a number (1-9): ";
    cin >> choice;

    switch (choice) {
        case 1: board[0][0] = player; break;
        case 2: board[0][1] = player; break;
        case 3: board[0][2] = player; break;
        case 4: board[1][0] = player; break;
        case 5: board[1][1] = player; break;
        case 6: board[1][2] = player; break;
        case 7: board[2][0] = player; break;
        case 8: board[2][1] = player; break;
        case 9: board[2][2] = player; break;
        default: cout << "Invalid move!" << endl; playerMove(player);
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon && !checkDraw()) {
        drawBoard();
        playerMove(currentPlayer);
        gameWon = checkWin();
        if (gameWon) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw()) {
            drawBoard();
            cout << "The game is a draw!" << endl;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

