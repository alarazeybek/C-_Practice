/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3 */

#include <iostream>
#include "LinkedList.h"
#include "string"
using namespace std;

//-----------------------------------------COMPARE IDS-------------------------------------------

template <>
int LinkedList<Movie>::compareIDs(Node<Movie>* n1, Node<Movie>* n2){
    if(n1->itemptr->getId() ==  n2->itemptr->getId()){
        return 0;
    }
    else if(n1->itemptr->getId() >  n2->itemptr->getId()){
        return 1;
    }
    else if(n1->itemptr->getId() <  n2->itemptr->getId()){
        return -1;
    }
//    May  need to delete here as well
    return -666;
}
template <>
int LinkedList<Subscriber>::compareIDs(Node<Subscriber>* n1, Node<Subscriber>* n2){
    if(n1->itemptr->getId() ==  n2->itemptr->getId()){
        return 0;
    }
    else if(n1->itemptr->getId() >  n2->itemptr->getId()){
        return 1;
    }
    else if(n1->itemptr->getId() <  n2->itemptr->getId()){
        return -1;
    }
//    May  need to delete here as well
    return -666;
}
template <>
int LinkedList<Transaction>::compareIDs(Node<Transaction>* n1, Node<Transaction>* n2){
    if(n1->itemptr->getMovie() ==  n2->itemptr->getMovie()){
        if(n1->itemptr->getSubscriber() ==  n2->itemptr->getSubscriber()){
            if(n1->itemptr->getRent() ==  n2->itemptr->getRent()){
                if(n1->itemptr->getIsBack() ==  n2->itemptr->getIsBack()){
                    return 0;
                }
                else if(n1->itemptr->getIsBack() == true && n2->itemptr->getIsBack() == false){
                    return -1;
                }
                else if(n1->itemptr->getIsBack() == false && n2->itemptr->getIsBack() == true){
                    return 1;
                }
            }
            else if(n1->itemptr->getRent() == true &&  n2->itemptr->getRent() == false){
                return 1;
            }
            else if(n1->itemptr->getRent() == false &&  n2->itemptr->getRent() == true){
                return -1;
            }
        }
        else if(n1->itemptr->getSubscriber() >  n2->itemptr->getSubscriber()){
            return 1;
        }
        else if(n1->itemptr->getSubscriber() <  n2->itemptr->getSubscriber()){
            return -1;
        }
    }
    else if(n1->itemptr->getMovie() >  n2->itemptr->getMovie()){
        return 1;
    }
    else if(n1->itemptr->getMovie() <  n2->itemptr->getMovie()){
        return -1;
    }
//    May  need to delete here as well
    return -666;
}

//------------------------------------------------HELPER METHODS-----------------------------------------------------------

template <>
Node<Transaction>* LinkedList<Transaction>::getNodeFromId(int id){
    return nullptr;
}
template <>
Node<Movie>* LinkedList<Movie>::getNodeFromId(int id){
    Node<Movie> *temp = head;
    while(temp!=nullptr){
        if(temp->itemptr->getId() == id){
            return temp;
        }
        temp = temp->next;
    }
    //cout<<"Id cannot be found in the list!\n";
    return nullptr;
}
template <>
Node<Subscriber>* LinkedList<Subscriber>::getNodeFromId(int id){
    Node <Subscriber> *temp = head;
    while(temp!=nullptr){
        if(temp->itemptr->getId() == id){
            return temp;
        }
        temp = temp->next;
    }
    //cout<<"Id cannot be found in the list!\n";
    return nullptr;
}
template<>
bool LinkedList<Transaction>::insert(Node<Transaction>* n){

    if(head == nullptr){ //empty list
        head = n;
        nodeNumber++;
        return true;
    }
    else if(compareIDs(n,head)<0){ //n is the smallest ID
        n->next = head;
        head = n;
        nodeNumber++;
        return true;
    }
    else{
        Node<Transaction>* left = head;
        Node<Transaction>* right = head->next;
        while(right != nullptr && compareIDs(n,right)>0){
            left = right;
            right = right->next;
        }
        left->next = n;
        n->next = right;
        nodeNumber++;
        return true;
    }
}
