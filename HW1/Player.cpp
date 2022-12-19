#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){
    name = "";
    jerseyNumber = 0;
    salaryAmount = 0;
}

Player::Player(const string playerName,  const int jersey, const int salary){
    name = playerName;
    jerseyNumber = jersey;
    salaryAmount = salary;
}
Player::~Player(){

}
int Player::getJersey(){
    return jerseyNumber;
}
string Player::getName(){
    return name;
}
int Player::getSalary(){
    return salaryAmount;
}
Player& Player::operator=(const Player& right){
    if(&right != this){
        name = right.name;
        salaryAmount = right.salaryAmount;
        jerseyNumber = right.jerseyNumber;
    }
    return *this;
}

#endif