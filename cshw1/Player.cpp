#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <iostream>
#include <string>
using namespace std;
#include "Player.h"

Player::Player(){}

Player::Player(const string playerName,  const int jersey, const int salary){
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
} /*
Player& Player::operator=( const Player& right ) {
    if ( &right != this ) { // to avoid self-assignment
    if ( jerseyNumber != right.jerseyNumber ) {
    if ( size > 0 )
    Player data = new Player(*right);
    else
    data = nullptr;
    }
    return *this; // to allow cascading
}*/

#endif