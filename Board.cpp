#pragma once
#include "Board.h"
#include "Player.cpp"
#include <iostream>

using namespace std;

Board::Board() {}

void Board::addDisk(int numCol, int numPlayer) {

    for (int i = rows - 1; i >= 0; --i) {
        if (board[i][numCol] == 0) {
            board[i][numCol] = numPlayer;
            break;
        }
    }
}

void Board::printBoard() {

/*    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 0) {
                cout << "/";
            } else if (board[i][j] == 1) {
                cout << "X";
            } else if (board[i][j] == 2) {
                cout << "O";
            } else {
                cout << "/";
            }
        }
        cout << "\n-----------------------------\n";
    }
    cout << "    1   2   3   4   5   6   7\n";
*/
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<< board[i][j]<< "  ";
        }

        cout << "\n" << endl;;
        
    }
    
}


bool Board::checkWinner() {

    int player1ID = 1;
    int player2ID = 2;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 3; j++) {
            if (board[i][j] == player1ID &&
                board[i][j + 1] == player1ID &&
                board[i][j + 2] == player1ID &&
                board[i][j + 3] == player1ID) {
                return true; // Ganador encontrado horizontalmente para player1
            }
            if (board[i][j] == player2ID &&
                board[i][j + 1] == player2ID &&
                board[i][j + 2] == player2ID &&
                board[i][j + 3] == player2ID) {
                return true; // Ganador encontrado horizontalmente para player2
            }
        }
    }

    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j] == player1ID &&
                board[i + 2][j] == player1ID &&
                board[i + 3][j] == player1ID) {
                return true; // Ganador encontrado verticalmente para player1
            }
            if (board[i][j] == player2ID &&
                board[i + 1][j] == player2ID &&
                board[i + 2][j] == player2ID &&
                board[i + 3][j] == player2ID) {
                return true; // Ganador encontrado verticalmente para player2
            }
        }
    }

    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols - 3; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j + 1] == player1ID &&
                board[i + 2][j + 2] == player1ID &&
                board[i + 3][j + 3] == player1ID) {
                return true; // Ganador encontrado en diagonal hacia la derecha para player1
            }
            if (board[i][j] == player2ID &&
                board[i + 1][j + 1] == player2ID &&
                board[i + 2][j + 2] == player2ID &&
                board[i + 3][j + 3] == player2ID) {
                return true; // Ganador encontrado en diagonal hacia la derecha para player2
            }
        }
    }

    for (int i = 0; i < rows - 3; i++) {
        for (int j = 3; j < cols; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j - 1] == player1ID &&
                board[i + 2][j - 2] == player1ID &&
                board[i + 3][j - 3] == player1ID) {
                return true; // Ganador encontrado en diagonal hacia la izquierda para player1
            }
            if (board[i][j] == player2ID &&
                board[i + 1][j - 1] == player2ID &&
                board[i + 2][j - 2] == player2ID &&
                board[i + 3][j - 3] == player2ID) {
                return true; // Ganador encontrado en diagonal hacia la izquierda para player2
            }
        }
    }

    return false; // No hay ganador

}

bool Board::isColumnFull(int numCol) {
   
    for (int i = rows; i >= 0; i--)
    {
        if (board[i][numCol] == 0) {
            return true;
        }
    }
    return false;
    

}

int Board::getPosition(int x, int y) { return board[x][y]; }

int Board::getCols() { return cols;}

/*void Board::copyBoard(Board& aux) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->board[i][j] = aux.board[i][j];
        }
    }
}*/

void Board::copyBoard(Board* aux) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->board[i][j] = aux->getPosition(i,j);
        }
    }
}
Board::~Board() {}