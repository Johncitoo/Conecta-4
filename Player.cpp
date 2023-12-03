#pragma once

#include "Player.h"
using namespace std;

Player::Player(int disk) { this->disk = disk;}
int Player::getDisk() { return disk;}
int Player::getScore() { return score;}