#pragma once;
#include "Board.h";
#include "Player.cpp"
#include <iostream>;

using namespace std;

Board::Board() {}

void Board::addDisk(int numCol, Player* player) {

    for (int i = 5; i >= 0; --i) {
            if (board[i][numCol] == 0) {
                board[i][numCol] = player->getDisk();
            }
        }

        cout << "Columna llena. Elige otra columna." << endl;
}

void Board::printBoard() {
    for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] == 0) {
                    cout << " | ";
                } else if (board[i][j] == 1) {
                    cout << "X | ";
                } else if (board[i][j] == 2) {
                    cout << "O | ";
                } else {
                    cout << "  | ";
                }
            }
            cout << "\n-----------------------------\n";
        }
        cout << "  1   2   3   4   5   6   7\n";
}