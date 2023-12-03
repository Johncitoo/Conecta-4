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

    Player(int disk);
    int getDisk();
    int getScore();
};