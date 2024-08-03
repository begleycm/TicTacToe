//
// Created by cbegl on 5/10/2024.
// This is used to run the Tic Tac Toe game.
//
#include "src/ttt.h"
#include <iostream>

// Defining these so I don't have to write out std each time
using std::cout;
using std::string;

int board [3][3]; // board of ints for game

int main() { // Runs tic tac toe
    cout << "Let's play a game of tic-tac-toe!" << std::endl;
    int currentPlayer = chooseXO(); // 1 for x, 2 for o.

    bool winner = false;
    int turns = 0;
    while (turns < 9 && !winner) { // Until there is a winner, or 9 turns are played.
        showBoard(board); // Brings up x o board
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
            winner = isWinner(currentPlayer, board);
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else if (currentPlayer == 2) {
                currentPlayer = 1;
            }
            turns++;
        }
    }
    showBoard(board);
    if(winner) {
        cout << "We have a winner!" << std::endl;
    } else {
        cout << "Looks like we have a tie..." << std::endl;
    }

    char playAgain;
    cout << "Would you like to play again? y/n ";
    std::cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        for(auto & i : board) {
            for(int & j : i) {
                j = 0;
            }
        }
        main();
    } else {
        cout << "Thanks for playing!";
    }

    return 0;
}
