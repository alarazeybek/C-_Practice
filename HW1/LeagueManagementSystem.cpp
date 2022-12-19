
#include "LeagueManagementSystem.h"
#include <iostream>
#include <string>
using namespace std;

LeagueManagementSystem::LeagueManagementSystem(){
    teamArrayPTR = nullptr;
    teamNumber = 0;
}
LeagueManagementSystem:: ~LeagueManagementSystem(){
    if(teamArrayPTR != nullptr){
        delete[] teamArrayPTR;
        teamArrayPTR = nullptr;
    }
}

void LeagueManagementSystem::addTeam(const string name, const int year){
    Team* temp = nullptr;
    int index=0;
    Team* t;
    bool b = findTeambyName(name,t, index);
    if(!b){
        Team team(name,year);
        (teamNumber)++;
        Team tempArray[teamNumber];
        tempArray[teamNumber - 1] = team;
        for(int i = 1 ; i<teamNumber;i++){
            tempArray[i - 1] = teamArrayPTR[i-1];
        }
        delete[] teamArrayPTR;
        teamArrayPTR = new Team[teamNumber];
        for(int i = 0 ; i<teamNumber;i++){
            teamArrayPTR[i] = tempArray[i];
        }
        cout << "Added team " << name <<"."<< endl;
        return;
    }  
    cout<< "Cannot add team. Team " + name + " already exist."<<endl;
   
}
void LeagueManagementSystem::removeTeam(const string name){
    Team* temp = nullptr;
    int index = 0;
    Team* t;
    bool b = findTeambyName(name,t, index);
    if(b){
        teamNumber--;
        Team team[teamNumber];
        for(int i = 0; i<index;i++){ //copying until we reach the index of removed team
            team[i] = teamArrayPTR[i];
        }
        for(int i = index; i<teamNumber;i++){ //copying the second part
            team[i] = teamArrayPTR[i+1];
        }
        delete[] teamArrayPTR;
        teamArrayPTR = new Team[teamNumber];
        for(int i = 0;i<teamNumber;i++){
            teamArrayPTR[i] = team[i];
        }
        cout << "Removed team " << name << endl;
        return;
    }  
    cout<< "Cannot remove team. Team " + name + " does not exist."<<endl;
}

void LeagueManagementSystem::addPlayer( const string teamName, const string playerName, const int jersey, const int salary ){
    Team* t;
    int index;
    bool b = findTeambyName(teamName,t,index);
    if(b){
        (*t).addPlayerInTeam(playerName,jersey,salary,1);//if printer = 0; tranfer player's cout will be called
        return;
    }
    cout<<"Cannot add player."<<" Team "<< teamName <<" does not exist."<<endl;
}

void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
    Team* t;
    int index;
    bool b = findTeambyName(teamName,t,index);
    if(b){
        (*t).removePlayer(playerName,1);//if bool = 0; tranfer player's cout will be called
        return;
    }
    cout<<"Cannot remove player."<<" Team "<< teamName <<" does not exist."<<endl; 
}
bool LeagueManagementSystem::findTeambyName(string teamName, Team*& t, int& index){
    if(teamArrayPTR!=nullptr){
        for(int i = 0 ; i<teamNumber;i++){
            if((teamArrayPTR[i].getName())==(teamName)){
                index = i;
                t = &teamArrayPTR[i];
                return true;
            }
        }
    }
    return false;
}
void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName){
    //depart Team
    Team* departPTR;
    int indexDepart;
    bool departExist = findTeambyName(departTeamName,departPTR,indexDepart);
    if(!departExist){ 
        cout<<"Cannot tranfer player."<<" Team "<< departTeamName<<" does not exist."<<endl; 
        return;
    }
    //arriveTeam
    Team* arrivePTR;
    int indexArrived;
    bool arrivedExist = findTeambyName(arriveTeamName,arrivePTR,indexArrived);
    if(!arrivedExist){ 
        cout<<"Cannot tranfer player."<<" Team "<< arriveTeamName <<" does not exist."<<endl; 
        return;
    }
    //Player check
    Player* transferPTR;
    bool playerExist = (*departPTR).findPlayerbyName(playerName, transferPTR);
    if(!playerExist){
        cout<<"Cannot tranfer player."<<" Player "<< playerName<<" does not exist."<<endl; 
        return;
    }
    bool check1 = (*arrivePTR).addPlayerInTeam(playerName, (*transferPTR).getJersey(), (*transferPTR).getSalary(), 0);
    bool check2 = 0;
    if(check1){
    check2 = (*departPTR).removePlayer(playerName, 0);
    }
    if(check1&check2){
        cout<<"Transferred player "<<playerName <<" from team "+departTeamName + " to team " + arriveTeamName<<endl;
    }
}
void LeagueManagementSystem::showAllTeams() const{
    cout<<"Teams in the league management system:"<<endl;
    for(int i = 0;i<teamNumber;i++){
        int total_salary = 0;
        for(int j=0; j<teamArrayPTR[i].getPlayerNumber();j++){
            total_salary += teamArrayPTR[i].getPlayerArray()[j].getSalary();
        }
    cout<<teamArrayPTR[i].getName()<<", "<<teamArrayPTR[i].getYear()<<", "<<
    teamArrayPTR[i].getPlayerNumber()<<" players, "<<total_salary<<" TL total salary"<<endl;}
    return;
    if(teamNumber<1)
     cout<<"None"<<endl;
}
void LeagueManagementSystem::showTeam( const string name ) const{
    for(int i = 0;i<teamNumber;i++){
        if(teamArrayPTR[i].getName()==name){
            int total_salary = 0;
            for(int j=0; j<teamArrayPTR[i].getPlayerNumber();j++){
                total_salary += teamArrayPTR[i].getPlayerArray()[j].getSalary();
            }   
            cout<<"Team:\n"<<name+", "<<teamArrayPTR[i].getYear()<<", "<<teamArrayPTR[i].getPlayerNumber()<<
                  " players, "<< total_salary<< " TL total salary"<<endl;
            cout<<"Players:"<<endl;
            for(int j=0; j<teamArrayPTR[i].getPlayerNumber();j++){
                cout<<teamArrayPTR[i].getPlayerArray()[j].getName()<<", jersey "<<
                      teamArrayPTR[i].getPlayerArray()[j].getJersey()<<", "<<
                      teamArrayPTR[i].getPlayerArray()[j].getSalary()<<" TL salary "<< endl;
            }  
            return;
        }
    }
    cout<<"Team "<<name<<" does not exist."<<endl;
}
void LeagueManagementSystem::showPlayer( const string name ) const{
    for(int i = 0;i<teamNumber;i++){
        for(int j = teamArrayPTR[i].getPlayerNumber()-1; j>=0 ;j--){
            if(teamArrayPTR[i].getPlayerArray()[j].getName()==name){
                cout<<"Player:\n"
                <<name+", jersey "<<teamArrayPTR[i].getPlayerArray()[j].getJersey()<<", "
                <<teamArrayPTR[i].getPlayerArray()[j].getSalary()<<" TL salary\n"
                <<"Plays in team "<< teamArrayPTR[i].getName()<<"."<<endl;
                return;
            }
        }
    }
    cout<<"Player "<<name<<" does not exist."<<endl;
}