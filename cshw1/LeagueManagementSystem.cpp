#ifndef LEAGUEMANAGEMENTSYSTEM_CPP
#define LEAGUEMANAGEMENTSYSTEM_CPP
#include "LeagueManagementSystem.h"
#include "Team.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

LeagueManagementSystem::LeagueManagementSystem(){
    teamNumber = 0;
    teamArrayPTR = new Team[teamNumber];
    
}
LeagueManagementSystem:: ~LeagueManagementSystem(){
    for(int i=0;i<teamNumber;i++){
         delete[] teamArrayPTR[i].playerArray;
    }
    delete []teamArrayPTR;
}

void LeagueManagementSystem::addTeam(const string name, const int year){
    if(teamArrayPTR!=nullptr){
            for(int j=0;j<teamNumber;j++){ //searching the same name
            if(teamArrayPTR[j].getName().compare(name)==0){
                cout<< "Cannot add team. Team " + name + " already exist."<<endl;
                return;
            }
        }
        teamNumber++;
        Team* tempPTR = new Team [teamNumber] ;
        tempPTR[0].setName(name);
        tempPTR[0].setYear(year);
        //copying
        for(int i = 1; i<teamNumber;i++){
            tempPTR[i] = teamArrayPTR[i-1];
        }
        delete [] teamArrayPTR;
        teamArrayPTR = tempPTR;
        tempPTR=nullptr;
        cout << "Added team " << name << endl;
    }
}
void LeagueManagementSystem::removeTeam(const string name){
    if(teamArrayPTR!=nullptr){ 
        for(int j=0;j<teamNumber;j++){ //searching the same name
            if(teamArrayPTR[j].getName().compare(name)==0){
                //removing
                teamNumber--;
                Team* tempPTR = new Team [teamNumber] ;
                //copying
                for(int i = 0; i<j;i++){ //j is the index of team that we'll remove
                    tempPTR[i] = teamArrayPTR[i]; 
                }
                for(int i = j; i<teamNumber;i++){
                    tempPTR[i] = teamArrayPTR[j+1];
                }
                delete [] teamArrayPTR;
                teamArrayPTR = tempPTR;
                tempPTR=nullptr;
                cout << "Removed team " << name << endl;
                return;
            }
        }
        cout<<"Cannot remove team. Team " + name + " does not exist."<<endl;
    }
}
void LeagueManagementSystem::showAllTeams() const{
    if(teamNumber<=0){
        cout<<"None"<<endl;
    }
    else{
        for(int i=0;i<teamNumber;i++){
            cout << teamArrayPTR[i].getName() <<endl;
        }
    }
}
void LeagueManagementSystem::addPlayer( const string teamName, const string playerName, const int jersey, const int salary ){
    for(int j=0;j<teamNumber;j++){ //searching the same name
        if(teamArrayPTR[j].getName().compare(teamName)==0){
            teamArrayPTR[j].addPlayerInTeam(playerName, jersey , salary);
            return;
        }
    }
    if(printerOn){cout<<"Cannot add player.";}
    else{cout<<"Cannot transfer player.";}
    cout<<" Team "<< teamName <<" does not exist."<<endl;
}

void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
    for(int j=0;j<teamNumber;j++){ //searching the same name
        if(teamArrayPTR[j].getName().compare(teamName)==0){
            teamArrayPTR[j].removePlayer(playerName);
            return;
        }
    }
    if(printerOn){ cout<<"Cannot remove player.";}
    else{cout<<"Cannot transfer player.";}
    cout <<" Team "<< teamName <<" does not exist."<<endl; 
}
void LeagueManagementSystem::transferPlayer( const string playerName, const string departTeamName, const string arriveTeamName ){
    printerOn = 0;
    removePlayer(departTeamName,playerName);
    Player* p = (*findTheTeam(departTeamName)).findThePlayer(playerName);
    addPlayer(arriveTeamName,(*p).getName(),(*p).getJerseyNumber(),(*p).getSalaryAmount());
    printerOn = 1;
}

Team* LeagueManagementSystem::findTheTeam(const string teamName){
    for(int i = 0; i<teamNumber;i++){
        if(teamArrayPTR[i].getName().compare(teamName)){
            return &teamArrayPTR[i];
        }
    }
    return &teamArrayPTR[0];
}
#endif