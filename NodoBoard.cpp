#pragma once
#include <iostream>
#include "NodoBoard.h"

using namespace std;

NodoBoard::NodoBoard(Board* board,int shift) {
    this->board = board;
    this->shift = shift;
}
void NodoBoard::addSon(NodoBoard* nodoBoard){ hijos.push_back(nodoBoard);}
int NodoBoard::getShift() {return shift;}
void NodoBoard::setShift(int i) { this->shift = i;}
void NodoBoard::clearHijos() { hijos.clear();}