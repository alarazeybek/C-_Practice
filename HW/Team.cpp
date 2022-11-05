
#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

Team::Team(const string aName, const int aYear){
    name = aName;
    year = aYear;
    playerNumber = 0;
    playerArray = nullptr;
}
Team::Team(){
    name = -1;
    year = -1;
    playerNumber = 0;
    playerArray = nullptr;
}
Team::~Team(){
    if(playerArray!=nullptr){
        delete []playerArray;
    } 
}
bool Team::addPlayerInTeam( const string playerName, const int jersey, const int salary, const bool printer){

    bool b = findPlayerbyJerseyNumber(jersey,printer);
    if(!b){
        Player* p = new Player(playerName,jersey,salary);
        playerNumber++;
        Player tempArray[playerNumber]; 
        tempArray[0] = *p;
        for(int i = 1; i< playerNumber;i++){
            tempArray[i] = playerArray[i-1];
        }
        delete[] playerArray;
        playerArray = new Player[playerNumber];
        for(int i = 0; i< playerNumber;i++){
            playerArray[i] = tempArray[i];
        }
        if(printer){
            cout<<"Added player " + playerName + " to team "+ name + "."<<endl;
        }
        delete p;
        return true;
    }
    return false;
}
bool Team::removePlayer(const string playerName,const bool printer){
    Player* p = nullptr;
    int index = 0;
    if(findPlayerbyName(playerName,p)){ //checking the existance of the player
        playerNumber--;
        Player tempArray[playerNumber];
        for(int i = 0; i<index;i++){ //copying until we reach the index of removed player
            tempArray[i] = playerArray[i];
        }
        for(int i = index; i<playerNumber;i++){ //copying the second part
            tempArray[i] = playerArray[i+1];
        }
        delete[] playerArray;
        playerArray = new Player[playerNumber];
        for(int i = 0;i<playerNumber;i++){
            playerArray[i] = tempArray[i];
        }
        if(printer){
            cout << "Remove player " << playerName <<" from team "<< name +"."<< endl;
        }
        return true;
    }
    if(printer){
        cout<< "Cannot removed player."<<" Player " + playerName + " doesn't exist."<<endl;
    }
    else{
        cout<< "Cannot transfered player."<<" Player " + playerName + " doesn't exist."<<endl;
    }
    return false;
}
//HELPER METHODS
bool Team::findPlayerbyName(string playerName,Player*& p){
    if(playerArray!=nullptr){
        for(int i = 0; i < playerNumber;i++){
            if(playerArray[i].getName()==playerName){
                p = &(playerArray[i]);
                //index = i;
                return true;
            }
        }
    }
    return false;
}
bool Team::findPlayerbyJerseyNumber(int jersey,bool printer){
    if(playerArray!=nullptr){
        for(int i = 0; i< playerNumber;i++){
            if(playerArray[i].getJersey()==jersey){
                if(printer){
                    cout<< "Cannot add player.";
                }
                else if(!printer){
                    cout<< "Cannot transfer player.";
                }
                cout<< " Jersey number " << jersey << " already exists in team " + name +"."<<endl;
                return true;
            }
        }
    }
    return false;
}
string Team::getName(){
    return name;
}
int Team::getPlayerNumber(){
    return playerNumber;
}
int Team::getYear(){
    return year;
}
Player* Team::getPlayerArray(){
    return playerArray;
}
Team& Team::operator=(const Team& right){
    if(&right != this){
        name = right.name;
        year = right.year;
        playerNumber = right.playerNumber;
        if(playerArray){
            delete []playerArray;
        }
        playerArray = new Player[playerNumber];
        for(int a = 0; a < playerNumber; a++){
            playerArray[a]  =  right.playerArray[a];
        }
    }
    return *this;
}