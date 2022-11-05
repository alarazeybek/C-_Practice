#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player{
 //I assume that it is an integer

public:
Player(string playerName,  int jersey,  int salary);
Player();
~Player();
string getName();
int getJersey();
int getSalary();
Player& operator =(const Player&);
//pointers to reach private data

private:
string name;
int jerseyNumber;
int salaryAmount;
};


#endif