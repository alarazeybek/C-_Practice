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

    void addPlayerInTeam(const string playerName, const int jersey, const int salary,const bool printer);
    void removePlayer(const string playerName,const bool printer);
    bool findPlayerbyName(string playerName);
    bool findPlayerbyJerseyNumber(int jersey, bool printer);
    string getName();
    int getYear();
    int getPlayerNumber();
    //bool Team::findPlayerbyName(string playerName, Player* playerPTR, int index){
/*
string* teamNamePTR;
int* yearPTR;
int* playerNumberPTR;
*/
private:
    string name;
    int year;
    int playerNumber;
    Player* playerArray;
};
#endif