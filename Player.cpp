#pragma once

#include "Player.h"
using namespace std;

/**
 * The Player constructor initializes the disk member variable.
 * 
 * @param disk The "disk" parameter is an integer that represents the player's disk
 * identifier.
 */
Player::Player(int disk) { this->disk = disk;}

/**
 * The function "getDisk" returns the value of the "disk" variable.
 * 
 * @return The value of the variable "disk" in the Player class.
 */
int Player::getDisk() { return disk;}

/**
 * The function "getScore" returns the score of the player.
 * 
 * @return The score of the player.
 */
int Player::getScore() { return score;}

/**
 * The destructor for the Player class is defined.
 */
Player::~Player() {};
