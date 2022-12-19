/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#include <iostream>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(int movieID, int SubsID, bool isRent){
    mID = movieID;
    sID = SubsID;
    rent = isRent;
    if(isRent){
        //lable = "Subscriber " + to_string(sID) +" rented Movie " + to_string(mID);
        lable = "Movie " + to_string(mID) + " has been rented by subscriber "+to_string(sID);
        isBack = 0;
    }
    else{
        //lable = "Subscriber " + to_string(sID) +" returned Movie " + to_string(mID);
        lable = "Movie " + to_string(mID) + " has been returned by subscriber "+to_string(sID);
        isBack = 1;
    }
}
int Transaction::getMovie(){
    return mID;
}
int Transaction::getSubscriber(){
    return sID;
}
string Transaction::getLabel(){
    return lable;
}
bool Transaction::getRent(){
    return rent;
}
void Transaction::setIsBack(bool b){
    isBack = b;
}
bool Transaction::getIsBack(){
    return isBack;
}
