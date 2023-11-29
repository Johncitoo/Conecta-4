#pragma once;
#include "Board.h";
#include <iostream>;

using namespace std;

Board::Board() {

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = "";
        }
    }
}

void Board::addDisk(int numCol) {

    for (int i = 5; i > -1;--i) {
        if (board[i][numCol] == " ") {
            
        }
    }
}