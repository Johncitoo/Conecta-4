#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Player {

    private:
    int disk;
    string name;
    int score;

    public:

    Player(int dik);
    int getDisk();
    int getScore();
};