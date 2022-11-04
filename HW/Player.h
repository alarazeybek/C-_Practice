#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player{
private:
string name;
int jerseyNumber;
int salaryAmount; //I assume that it is an integer

public:
Player(string playerName,  int jersey,  int salary);
Player();
~Player();
//pointers to reach private data
string* namePTR;
int* jerseyNumberPTR;
int* salaryAmountPTR;
};


#endif