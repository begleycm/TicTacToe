//
// Created by cbegl on 8/3/2024.
//

#pragma once

/**
 * Main code for game.
 */
void Tictactoe();

void showBoard(int board[3][3]);

int chooseXO();

char XorO();

bool isWinner(int num, int board[3][3]);

bool isOpen(int slot);
