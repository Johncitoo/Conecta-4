#pragma once

using namespace std;

class Board {
    private:
        string board[6][7];
    
    public:
        Board();
        void addDisk(int numCol);
        void printBoard();

};