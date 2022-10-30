#ifndef LEAGUEMANAGEMENTSYSTEM_H
#define LEAGUEMANAGEMENTSYSTEM_H
#include <iostream>
#include <string>
#include "Team.h"
#include "Player.h"
using namespace std;

class LeagueManagementSystem { //LeagueManagementSystem
private:
int teamNumber;
public:
LeagueManagementSystem();
~LeagueManagementSystem();
void addTeam( const string name, const int year );
void addPlayer( const string teamName, const string playerName, const int jersey, const int salary );

void removeTeam( const string name );
void removePlayer( const string teamName, const string playerName );

void transferPlayer( const string playerName, const string departTeamName, const string arriveTeamName );

void showAllTeams() const;
void showTeam( const string name ) const;
void showPlayer( const string name ) const;

Team* findTheTeam(const string teamName);
Team* teamArrayPTR;
};
#endif
