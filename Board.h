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
        void addDisk(int numCol,Player* player);
        void printBoard();
        bool checkWinner(Player* player1, Player* player2);
        bool isColumnFull(int numCol);
        ~Board();

};