#pragma once

using namespace std;

class Board {
    private:
        int board[6][7] {0};
    
    public:
        Board();
        void addDisk(int numCol,Player* player);
        void printBoard();

};