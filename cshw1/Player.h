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
const string getName();
const int getJerseyNumber();
const int getSalaryAmount();
//Player& operator=( const Player& right );
};


#endif