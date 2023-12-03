#pragma once
#include "player.cpp"

using namespace std;

class Board {
    private:
        int board[6][7] {0};
        int rows = 6;
        int cols = 7;
    
    public:
        Board();
        void addDisk(int numCol, int numPlayer);
        void printBoard();
        bool checkWinner();
        bool isColumnFull(int numCol);
        int getCols();
        int getPosition(int f,int c);
        ~Board();

};