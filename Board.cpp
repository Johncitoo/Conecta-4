#pragma once
#include "Board.h"
#include "Player.cpp"
#include <iostream>

using namespace std;

/**
 * The Board constructor is defined.
 */
Board::Board() {}

/**
 * The function adds a disk to the specified column on the game board for the specified player.
 * 
 * @param numCol The parameter "numCol" represents the column number where the disk is to be added.
 * @param numPlayer The `numPlayer` parameter represents the player number. It is used to determine
 * which player's disk should be added to the board.
 */
void Board::addDisk(int numCol, int numPlayer) {
    for (int i = rows; i >= 0; --i) {
        if (board[i][numCol -1 ] == 0) {
                board[i][numCol-1] = numPlayer;
            
            
            
            break;
        }
    }
}

/**The function `printBoard` prints the contents of a 2D board array in C++.
 */
void Board::printBoard() {

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<< board[i][j]<< "  ";
        }

        cout << "\n" << endl;;
        
    }

    cout << "[1,2,3,4,5,6,0]" << endl;
    
}


/**
 * The function checks if there is a winner in a game board by checking for horizontal, vertical, and
 * diagonal matches.
 * 
 * @return a boolean value. It returns true if there is a winner on the game board, and false
 * otherwise.
 */
bool Board::checkWinner() {

    int player1ID = 1;
    int player2ID = 2;
    // HORIZONTAL
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 3; j++) {
            if (board[i][j] == player1ID &&
                board[i][j + 1] == player1ID &&
                board[i][j + 2] == player1ID &&
                board[i][j + 3] == player1ID) {
                return true;
            }
            if (board[i][j] == player2ID &&
                board[i][j + 1] == player2ID &&
                board[i][j + 2] == player2ID &&
                board[i][j + 3] == player2ID) {
                return true;
            }
        }
    }
    // VERTICAL
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j] == player1ID &&
                board[i + 2][j] == player1ID &&
                board[i + 3][j] == player1ID) {
                return true;
            }
            if (board[i][j] == player2ID &&
                board[i + 1][j] == player2ID &&
                board[i + 2][j] == player2ID &&
                board[i + 3][j] == player2ID) {
                return true;
            }
        }
    }
    //DIAGONAL DERECHA
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols - 3; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j + 1] == player1ID &&
                board[i + 2][j + 2] == player1ID &&
                board[i + 3][j + 3] == player1ID) {
                return true;
            }
            if (board[i][j] == player2ID &&
                board[i + 1][j + 1] == player2ID &&
                board[i + 2][j + 2] == player2ID &&
                board[i + 3][j + 3] == player2ID) {
                return true; 
            }
        }
    }
    // DIAGONAL IZQUIERDA
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 3; j < cols; j++) {
            if (board[i][j] == player1ID &&
                board[i + 1][j - 1] == player1ID &&
                board[i + 2][j - 2] == player1ID &&
                board[i + 3][j - 3] == player1ID) {
                return true; 
            }
            
            if (board[i][j] == player2ID &&
                board[i + 1][j - 1] == player2ID &&
                board[i + 2][j - 2] == player2ID &&
                board[i + 3][j - 3] == player2ID) {
                return true;
            }
        }
    }

    return false;

}

/**
 * The function checks if a specific column in a board is full or not.
 * 
 * @param numCol The parameter `numCol` represents the column number that we want to check if it is
 * full or not.
 * 
 * @return a boolean value. It returns true if the column is full (i.e., all elements in the column are
 * non-zero), and false otherwise.
 */
bool Board::isColumnFull(int numCol) {
   
    for (int i = rows - 1; i >= 0; i--)
    {
        if (board[i][numCol] == 0) {
            return true;
        }
    }
    return false;
    

}

/**
 * The function `getPosition` returns the value at a specific position on the board.
 * 
 * @param x The x parameter represents the row index of the position on the board.
 * @param y The y parameter represents the row index of the position on the board.
 * 
 * @return The value at position (x, y) on the board.
 */
int Board::getPosition(int x, int y) { return board[x][y]; }

/**
 * The function returns the number of columns in the board.
 * 
 * @return The number of columns in the board.
 */
int Board::getCols() { return cols;}

/**
 * The function `copyBoard` copies the contents of the `board` array from one `Board` object to
 * another.
 * 
 * @param aux The "aux" parameter is a pointer to another Board object that we want to copy the
 * contents of.
 */
void Board::copyBoard(Board* aux) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->board[i][j] = aux->board[i][j];
        }
    }
}

/**
 * The destructor for the Board class.
 */
Board::~Board() {}