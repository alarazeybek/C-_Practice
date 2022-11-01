#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Team{
public:
Team(string n, int y);
Team();
~Team();
string getName();
int getYear();
void setName(string n);
void setYear(int y);
void addPlayerInTeam(const string playerName, const int jersey, const int salary);
void removePlayer(const string playerName);
Player* playerArray;
int playerNumber;
private:
string name;
int year;


};
#endif