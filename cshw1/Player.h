#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;
static bool printerOn = 1;

class Player{
private:

const string* name;
const int* jerseyNumber;
const int* salaryAmount; //I assume that it is an integer

public:
Player(string playerName,  int jersey,  int salary);
Player();
~Player();
const string getName();
const int getJerseyNumber();
const int getSalaryAmount();
};


#endif