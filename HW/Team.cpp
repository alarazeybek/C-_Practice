
#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

Team::Team(){
    playerNumberPTR = nullptr;
    teamNamePTR=nullptr;
    yearPTR=nullptr;
    playerNumberPTR=nullptr;
}
Team::~Team(){
    if(playerNumberPTR!=nullptr || playerNumberPTR!=0){
        delete []playerArray;
        playerArray = nullptr;
    } 
}
Team::Team(string n, int y){
    playerNumberPTR = &(Team::playerNumber);
    teamNamePTR=&(Team::name);
    yearPTR=&(Team::year);
    *teamNamePTR = n;
    *yearPTR = y;
    *playerNumberPTR = 0;
    playerArray = new Player[*playerNumberPTR];
}
void Team::addPlayerInTeam( const string playerName, const int jersey, const int salary, const bool printer){
    bool b = findPlayerbyJerseyNumber(jersey,printer);
    if(!b){
        Player* p = new Player(playerName,jersey,salary);
        *playerNumberPTR++;
        Player tempArray[*playerNumberPTR]; 
        tempArray[0] = *p;
        for(int i = 1; i< *playerNumberPTR;i++){
            tempArray[i] = playerArray[i-1];
        }
        delete[] playerArray;
        playerArray = new Player[*playerNumberPTR];
        for(int i = 0; i< *playerNumberPTR;i++){
            playerArray[i] = tempArray[i];
        }
        if(printer){
            cout<<"Added player " + playerName + " to team "+ *teamNamePTR + "."<<endl;
        }
    }
}
void Team::removePlayer(const string playerName,const bool printer){
    Player* findplayerPTR = nullptr;
    int index = 0;
    if(findPlayerbyName(playerName,findplayerPTR,index)){ //checking the existance of the player
        *playerNumberPTR--;
        Player tempArray[*playerNumberPTR];
        for(int i = 0; i<index;i++){ //copying until we reach the index of removed player
            tempArray[i] = playerArray[i];
        }
        for(int i = index; i<*playerNumberPTR;i++){ //copying the second part
            tempArray[i] = playerArray[i+1];
        }
        delete[] playerArray;
        playerArray = new Player[*playerNumberPTR];
        for(int i = 0;i<*playerNumberPTR;i++){
            playerArray[i] = tempArray[i];
        }
        if(printer){
            cout << "Remove player " << playerName <<" from team "<< *teamNamePTR +"."<< endl;
        }
    }
    if(printer){
        cout<< "Cannot removed player."<<" Player " + playerName + " doesn't exist."<<endl;
    }
    else{
        cout<< "Cannot transfered player."<<" Player " + playerName + " doesn't exist."<<endl;
    }
}
//HELPER METHODS
bool Team::findPlayerbyName(string playerName, Player* playerPTR, int index){
    if(playerArray!=nullptr){
        for(int i = 0; i<*playerNumberPTR;i++){
            if(*(playerArray[i].namePTR)==playerName){
                playerPTR = &(playerArray[i]);
                index = i;
                return true;
            }
        }
    }
    return false;
}
bool Team::findPlayerbyJerseyNumber(int jersey,bool printer){
    if(playerArray!=nullptr){
        for(int i = 0; i<*playerNumberPTR;i++){
            if(*(playerArray[i].jerseyNumberPTR)==jersey){
                if(printer){
                    cout<< "Cannot add player.";
                }
                else if(!printer){
                    cout<< "Cannot transfer player.";
                }
                cout<< " Jersey number " << jersey << " already exists in team " + *teamNamePTR +"."<<endl;
                return true;
            }
        }
    }
    return false;
}
