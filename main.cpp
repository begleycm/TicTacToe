//
// Created by cbegl on 5/10/2024.
//
#include <iostream>
using std::cout;
using std::string;

char XorO(); // define xoro

void tictactoe() {
    cout << "Let's play a game of tic-tac-toe!" << std::endl;
    cout << "Will player 1 be xs or os? " << std::endl;



    char board [3][3];
    board [0][1] = 'x';
    cout << XorO();
}

char XorO() {
    char xo;
    cout << "Type x or o: " << std::endl;
    std::cin >> xo;
    return xo;
}

int main() { // Runs tic tac toe
    tictactoe();

    return 0;
}
