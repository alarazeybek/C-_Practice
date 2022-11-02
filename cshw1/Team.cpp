
#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

Team::Team(){
    playerNumber = 0;
    playerArray = new Player[playerNumber];
    
}
Team::~Team(){
    /*if(playerArray!=nullptr){
        cout<<"dq"<<endl;
        delete []playerArray;
        cout<<"eq"<<endl;
    } */
    
}
Team::Team(string n, int y){
    Team::name = n;
    Team::year = y;
    playerNumber = 0;
    cout<<"Bq"<<endl;
    Team::playerArray = new Player[playerNumber];
    cout<<"cq"<<endl;
    
}
string Team::getName(){
    return Team::name;
}
int Team::getYear(){
    return Team::year;
}
void Team::setName(string n){
    name = n;
}
void Team::setYear(int y){
    year = y;
} 
void Team::addPlayerInTeam( const string playerName, const int jersey, const int salary, const bool printer){
    if(playerArray!=nullptr){
        for(int j=0;j<playerNumber;j++){ //searching the same name
            if((*(playerArray+j)).getJerseyNumber()== jersey){
                if(printer){cout<< "Cannot add player."<< " Jersey number " << jersey << " already exists in team " + name <<endl;}
                else if(!printer){cout<< "Cannot transfer player."<< " Jersey number " << jersey << " already exists in team " + name <<endl;}
                return;
            }
        }
        playerNumber++;
        Player* k = new Player[playerNumber];
        Player temp(playerName, jersey, salary);
        k[0] = temp;
        for(int i = 1; i<playerNumber;i++){
            k[i] = *(playerArray+i-1);
        }
        delete[] playerArray;
        playerArray = k;
        if(printer){cout<<"Added player " + playerName + " to team "+ getName()<<endl;}
    }
}
void Team::removePlayer(const string playerName,const bool printer){
    if(playerArray!=nullptr){
        for(int j=0;j<playerNumber;j++){ //searching the same name
            if((*(playerArray+j)).getName().compare(playerName)==0){
                playerNumber--;
                Player* ptr = new Player[playerNumber];
                for(int firstPart = 0; firstPart<j;firstPart++){
                    ptr[firstPart] = playerArray[firstPart];
                }
                for(int secondPart = j; secondPart<playerNumber;secondPart++){
                    ptr[secondPart] = playerArray[secondPart+1];
                }
                delete[] playerArray;
                playerArray = ptr;
                ptr = nullptr;
                if(printer)cout << "Removed player " << playerName <<" from team "<< name << endl;
                return;
            }
        }
        cout<< "Cannot removed player."<<" Player " + playerName + " doesn't exist."<<endl;
    }
}

