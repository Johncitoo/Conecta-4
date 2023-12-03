#pragma once
#include "Board.h"
#include <vector>

using namespace std;

class NodoBoard {
    private:
    Board* board;
    int shift;
    vector <NodoBoard*> hijos;

    public:

    NodoBoard(Board* board, int shift);
    void addSon(NodoBoard* nodoBoard);
    int getShift();
    void setShift(int i);


};