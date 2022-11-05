#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player{

public:
Player(string playerName,  int jersey,  int salary);
Player();
~Player();
string getName();
int getJersey();
int getSalary();
Player& operator =(const Player&);

private:
string name;
int jerseyNumber;
int salaryAmount;//I assume that it is an integer
 
};


#endif