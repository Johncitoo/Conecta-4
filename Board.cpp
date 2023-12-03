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
                cout << "  | ";
            } else if (board[i][j] == 1) {
                cout << "X | ";
            } else if (board[i][j] == 2) {
                cout << "O | ";
            } else {
                cout << "   ";
            }
        }
        cout << "\n-----------------------------\n";
    }
    cout << "    1   2   3   4   5   6   7\n";

}

bool Board::checkWinner(Player* player1, Player* player2) {

    int player1ID = player1->getDisk();
    int player2ID = player2->getDisk();

    // (Código de verificación de ganadores)

    // Verificar horizontalmente, verticalmente y en diagonales
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
   
    return board[rows - 1][numCol] == 0;

}

Board::~Board() {}