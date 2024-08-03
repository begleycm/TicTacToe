//
// Created by cbegl on 8/3/2024.
//

#include "ttt.h"
#include <iostream>

// Defining these so I don't have to write out std each time
using std::cout;
using std::string;

/**
 * Check to see if this spot is open.
 *
 * @param slot The slot to check.
 * @return True if open, false if not.
 */
bool isOpen(int const slot) {
    // If the slot has an x or o, it's not open.
    if (slot == 1 || slot == 2) {
        return false;
    }
    return true;
}

/**
 * Displays the current Tic-tac-toe board.
 */
void showBoard(int board[3][3]) {
    // This iterates through the 2d array and finds a 0, 1, or 2. If there is a
    // 0 print a whitespace, 1 print X, 2 print O.

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
 * Checks to see if this number is a winner. The first part of the array is the row, second is
 * the column.
 *
 * @param num Number to look for
 * @return True if there's a winner, false if not.
 */
bool isWinner(int num, int board[3][3]) {
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
    } else if (board[0][1] == num && board [1][1] == num && board[2][1] == num) {
        winner = true;
    } else if (board[0][2] == num && board [1][2] == num && board[2][2] == num) {
        winner = true;
    }
    return winner;
}
