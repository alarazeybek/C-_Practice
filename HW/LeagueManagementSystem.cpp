
#include "LeagueManagementSystem.h"
#include <iostream>
#include <string>
using namespace std;

LeagueManagementSystem::LeagueManagementSystem(){
    teamNumber = &number;
    *teamNumber = 0;
    teamArrayPTR = new Team[*teamNumber];
}
LeagueManagementSystem:: ~LeagueManagementSystem(){
    delete[] teamArrayPTR;
    teamArrayPTR = nullptr;
}

void LeagueManagementSystem::addTeam(const string name, const int year){
    Team* temp;
    int index=0;
    bool b = findTeambyName(name,temp,index);
    if(!b){
        Team team(name,year);
        (*teamNumber)++;
        Team tempArray[*teamNumber];
        tempArray[0] = team;
        for(int i = 1 ; i<*teamNumber;i++){
            tempArray[i] = teamArrayPTR[i-1];
        }
        delete[] teamArrayPTR;
        teamArrayPTR = new Team[*teamNumber];
        for(int i = 0 ; i<*teamNumber;i++){
            teamArrayPTR[i] = tempArray[i];
        }
        cout << "Added team " << name << endl;
        return;
    }  
    cout<< "Cannot add team. Team " + name + " already exist."<<endl;
   
}
void LeagueManagementSystem::removeTeam(const string name){
    Team* temp;
    int index;
    bool b = findTeambyName(name,temp,index);
    if(b){
        *teamNumber--;
        Team team[*teamNumber];
        for(int i = 0; i<index;i++){ //copying until we reach the index of removed team
            team[i] = teamArrayPTR[i];
        }
        for(int i = index; i<*teamNumber;i++){ //copying the second part
            team[i] = teamArrayPTR[i+1];
        }
        delete[] teamArrayPTR;
        teamArrayPTR = new Team[*teamNumber];
        for(int i = 0;i<*teamNumber;i++){
            teamArrayPTR[i] = team[i];
        }
        cout << "Removed team " << name << endl;
        return;
    }  
    cout<< "Cannot remove team. Team " + name + " does not exist."<<endl;
}
void LeagueManagementSystem::showAllTeams() const{
    
}
void LeagueManagementSystem::addPlayer( const string teamName, const string playerName, const int jersey, const int salary ){
    }

void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
    }
bool LeagueManagementSystem::findTeambyName(string teamName, Team* teamPTR, int index){
    if(teamArrayPTR!=nullptr){
        for(int i = 0 ; i<*teamNumber;i++){
            if((*(teamArrayPTR[i].teamNamePTR))==(teamName)){
                index = i;
                teamPTR = &teamArrayPTR[i];
                return true;
            }
        }
    }
    return false;
}
