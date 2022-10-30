#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){}

Player::Player(string playerName,  int jersey,  int salary){
    Player::name = playerName;
    Player::jerseyNumber = jersey;
    Player::salaryAmount = salary;
}
Player::~Player(){

}
const string Player::getName(){
    return Player::name;
}
const int Player::getJerseyNumber(){
    return Player::jerseyNumber;
}
const int Player::getSalaryAmount(){
    return Player::salaryAmount;
} 


#endif