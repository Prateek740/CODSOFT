#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if the game is over
bool isGameOver(const vector<vector<char>> &board) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    bool player1Turn = true; // Player 1 starts

    while (true) {
        // Draw the current state of the board
        cout << "Tic-Tac-Toe" << endl;
        drawBoard(board);

        // Determine the current player's symbol
        char currentPlayerSymbol = (player1Turn) ? 'X' : 'O';

        // Get the player's move
        int row, col;
        cout << "Player " << currentPlayerSymbol << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayerSymbol;

        // Check if the game is over
        if (isGameOver(board)) {
            // Draw the final state of the board
            cout << "Tic-Tac-Toe" << endl;
            drawBoard(board);

            // Declare the result
            if (isGameOver(board) && !isTie(board)) {
                cout << "Player " << currentPlayerSymbol << " wins!" << endl;
            } else {
                cout << "It's a tie!" << endl;
            }

            break; // Exit the game loop
        }

        // Switch to the other player's turn
        player1Turn = !player1Turn;
    }

    return 0;
}
