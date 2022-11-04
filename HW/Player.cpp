#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){
    namePTR = nullptr ;
    jerseyNumberPTR = nullptr;
    salaryAmountPTR = nullptr;
}

Player::Player(const string playerName,  const int jersey, const int salary){
    namePTR = &(Player::name) ;
    jerseyNumberPTR = &(Player::jerseyNumber);
    salaryAmountPTR = &(Player::salaryAmount);
    *namePTR = playerName;
    *jerseyNumberPTR = jersey;
    *salaryAmountPTR = salary;
}
Player::~Player(){

}

#endif