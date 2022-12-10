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

    bool addPlayerInTeam(const string playerName, const int jersey, const int salary,const bool printer);
    bool removePlayer(const string playerName,const bool printer);
    bool findPlayerbyName(string playerName, Player*& p);
    bool findPlayerbyJerseyNumber(int jersey, bool printer);
    string getName();
    int getYear();
    int getPlayerNumber();
    Team& operator=(const Team&);
    Player* getPlayerArray();

private:
    string name;
    int year;
    int playerNumber;
    Player* playerArray;
};
#endif