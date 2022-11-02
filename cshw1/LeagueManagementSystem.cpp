
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
            teamArrayPTR[j].addPlayerInTeam(playerName, jersey , salary,1);
            return;
        }
    }
    cout<<"Cannot add player."<<" Team "<< teamName <<" does not exist."<<endl;
}

void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
    for(int j=0;j<teamNumber;j++){ //searching the same name
        if(teamArrayPTR[j].getName().compare(teamName)==0){
            teamArrayPTR[j].removePlayer(playerName,1);
            return;
        }
    }
    cout<<"Cannot remove player."<<" Team "<< teamName <<" does not exist."<<endl; 
}
bool LeagueManagementSystem::addPlayer2( const string teamName, const string playerName, const int jersey, const int salary ){
    for(int j=0;j<teamNumber;j++){ //searching the same name
        if(teamArrayPTR[j].getName().compare(teamName)==0){
            teamArrayPTR[j].addPlayerInTeam(playerName, jersey , salary,0);
            return true;
        }
    }
    cout<<"Cannot transfer player."<<" Team "<< teamName <<" does not exist."<<endl;
    return false;
}
bool LeagueManagementSystem::removePlayer2( const string teamName, const string playerName ){
    for(int j=0;j<teamNumber;j++){ //searching the same name
        if(teamArrayPTR[j].getName().compare(teamName)==0){
            teamArrayPTR[j].removePlayer(playerName,0);
            return true;
        }
    }
    cout<<"Cannot transfer player."<<" Team "<< teamName <<" does not exist."<<endl; 
    return false;
}
bool LeagueManagementSystem::findThePlayer1(const string playerName, const string teamName, Player*& playerptr){
    for(int i = 0; i<teamNumber;i++){
        if(teamArrayPTR[i].getName()==(teamName)){
            for(int j = 0; j<teamArrayPTR[i].playerNumber;j++){
                if(teamArrayPTR[i].playerArray[j].getName()==(playerName)){
                    cout<< (teamArrayPTR[i].playerArray[j]).getName()<<endl;
                    playerptr = &(teamArrayPTR[i].playerArray[j]);
                    return true;
                }
            }
        }
    }
    return false;
}
void LeagueManagementSystem::transferPlayer( const string playerName, const string departTeamName, const string arriveTeamName ){
    Player* playerptr;
    bool b1 = findThePlayer1(playerName, departTeamName, playerptr);
    bool b2 = removePlayer2(departTeamName,playerName);
    
    const string pn=(*playerptr).getName();
    const int pjn =(*playerptr).getJerseyNumber();
    const int psn = (*playerptr).getSalaryAmount();
    bool b3 = addPlayer2(arriveTeamName,pn,pjn,psn);
    if(b1 &b2 & b3){cout<< "Transferred player "<<playerName <<" from team "+departTeamName + " to team " + arriveTeamName<< endl;
}}
