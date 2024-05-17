//
// Created by cbegl on 5/10/2024.
//
#include <iostream>

using std::cout;
using std::string;

char XorO(); // define XorO method
int chooseXO();
bool isWinner(int num); // Check for winner
void showBoard();
bool isOpen(int slot);
int board [3][3]; // board of ints for game

/**
 * Main code for game.
 */
void Tictactoe() {
    cout << "Let's play a game of tic-tac-toe!" << std::endl;
    int currentPlayer = chooseXO(); // 1 for x, 2 for o.

    bool winner = false;
    int turns = 0;
    while (turns < 9 && !winner) { // Until there is a winner, or 9 turns are played.
        showBoard(); // Brings up x o board
        cout << "\n";

        int row;
        int column;
        cout << "What row and column would you like to play in? " << std::endl;

        bool failing;
        do {
            cout << "Row:"; // check
            std::cin >> row;
            cout << "Column:"; // check
            std::cin >> column;

            failing = std::cin.fail();
            if (failing) {
                cout << "Invalid input, try again \n";
            }

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

        } while(failing);

        //Check to see if it is a valid row/column
        if((row < 1 || row > 3) || (column < 1 || column > 3)) {
            cout << "Not a valid row/column" << std::endl;
        } else if (!isOpen(board[row - 1][column - 1])) {
            cout << "Spot is not open" << std::endl;
        } else {
            board[row - 1][column - 1] = currentPlayer;
            //switch players
            winner = isWinner(currentPlayer);
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else if (currentPlayer == 2) {
                currentPlayer = 1;
            }
            turns++;
        }
    }
    showBoard();
    if(winner) {
        cout << "We have a winner!" << std::endl;
    } else {
        cout << "Looks like we have a tie..." << std::endl;
    }

    char playAgain;
    cout << "Would you like to play again? y/n";
    std::cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        for(auto & i : board) {
            for(int & j : i) {
                j = 0;
            }
        }
        Tictactoe();
    } else {
        cout << "Thanks for playing!";
    }
}

/**
 * Check to see if this spot is open.
 *
 * @param slot The slot to check.
 * @return True if open, false if not.
 */
bool isOpen(int slot) {
    if (slot == 1 || slot == 2) {
        return false;
    }
    return true;
}

/**
 * Displays the current Tic-tac-toe board.
 */
void showBoard() {
    char xo [3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                xo[i][j] = 'x';
            } else if (board[i][j] == 2) {
                xo[i][j] = 'o';
            } else {
                xo[i][j] = ' '; // blank if nothing
            }
        }
    }
    cout << xo[0][0] << '|' << xo[0][1] << '|' << xo[0][2] << std::endl;
    cout << "=====" << std::endl;
    cout << xo[1][0] << '|' << xo[1][1] << '|' << xo[1][2] << std::endl;
    cout << "=====" << std::endl;
    cout << xo[2][0] << '|' << xo[2][1] << '|' << xo[2][2] << std::endl;
}



/**
 * Promts the user to choose x or o.
 *
 * @return 1 for x, 2 for o.
 */
int chooseXO() {
    char choice = XorO();
    bool correctChoice = false;
    while (!correctChoice) {
        if (choice == 'x') {
            return 1;
        } else if (choice == 'o') {
            return 2;
        } else {
            cout << "Invalid choice!" << std::endl; // repeats if the user enters more than 1 thing
            choice = XorO();
        }
    }
}

/**
 * Asks the user to enter x or o.
 *
 * @return Character the user entered.
 */
char XorO() {
    char xo;
    cout << "Will player 1 be x or o?";
    std::cin >> xo;
    return xo;
}

/**
 * Checks to see if this number is a winner.
 *
 * @param num Number to look for
 * @return True if there's a winner, false if not.
 */
bool isWinner(int num) {
    bool winner = false;
    if (board[0][0] == num && board [0][1] == num && board[0][2] == num) { // horizontal
        winner = true;
    } else if (board[1][0] == num && board [1][1] == num && board[1][2] == num) {
        winner = true;
    } else if (board[2][0] == num && board [2][1] == num && board[2][2] == num) {
        winner = true;
    } else if (board[0][0] == num && board [1][1] == num && board[2][2] == num) { // diagonal
        winner = true;
    } else if (board[2][0] == num && board [1][1] == num && board[0][2] == num) {
        winner = true;
    } else if (board[0][0] == num && board [1][0] == num && board[2][0] == num) { // vertical
        winner = true;
    } else if (board[1][0] == num && board [1][1] == num && board[1][2] == num) {
        winner = true;
    } else if (board[2][0] == num && board [2][1] == num && board[2][2] == num) {
        winner = true;
    }
    return winner;
}

int main() { // Runs tic tac toe
    Tictactoe();

    return 0;
}
