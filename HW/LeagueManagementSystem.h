#ifndef LEAGUEMANAGEMENTSYSTEM_H
#define LEAGUEMANAGEMENTSYSTEM_H
#include <iostream>
#include <string>
#include "Team.h"
#include "Player.h"
using namespace std;

class LeagueManagementSystem { 
private:
int number;
public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void addPlayer( const string teamName, const string playerName, const int jersey, const int salary );

    void removeTeam( const string name );
    void removePlayer( const string teamName, const string playerName );

    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;

Team* teamArrayPTR;
int* teamNumber;
bool findTeambyName(string teamName, Team* teamPTR, int index);
};
#endif
