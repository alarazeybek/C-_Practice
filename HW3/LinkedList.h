/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include "Movie.h"
#include "string"
using namespace std;


template <class ItemType>
class LinkedList
{
private:
   Node<ItemType> *head;
   int nodeNumber;
public:
    LinkedList<ItemType>();
    ~LinkedList<ItemType>();
    bool isEmpty();
    int getLength();
    void insert(Node<ItemType>* n);
    void remove(Node<ItemType>* n);
    ItemType* getItem(int index);
    int compareIDs(Node<ItemType>* n1, Node<ItemType>* n2);
};

//-----------------------------------------------------CONSTRUCTOR & DESTRUCTOR----------------------------------------
template <class ItemType>
LinkedList<ItemType>::LinkedList(){
    head = nullptr;
    nodeNumber = 0;
}
template <class ItemType>
LinkedList<ItemType>::~LinkedList(){
    //clear();
    delete head;
    nodeNumber=0;
}
//-------------------------------------------------ADD NODE----------------------------------------------------------------
template <class ItemType>
void LinkedList<ItemType>::insert(Node<ItemType>* n){ //TODO movie objesiyse ekleme node->data->setCount((node->data->getCount())+1); yap
    if(head == nullptr){
        head = n;
    }
   // else if()
}
//------------------------------------------------REMOVE NODE---------------------------------------------------------------
template <class ItemType>
void LinkedList<ItemType>::remove(Node<ItemType>* n){return;}

//------------------------------------------------HELPER METHODS-----------------------------------------------------------
template <class ItemType>
ItemType* LinkedList<ItemType>::getItem(int index){
    bool valid = (index<=nodeNumber) && (index>0);
    if(valid){
        Node<ItemType>* temp = head;
        while(temp!=nullptr && temp->next != nullptr && index > 0){
                temp = temp->next;
                index--;
        }
        return temp->itemptr;
    }
}
template <class ItemType>
bool LinkedList<ItemType>::isEmpty(){
    return head == nullptr;
}
template <class ItemType>
int LinkedList<ItemType>::getLength(){
    return nodeNumber;
}
//-----------------------------------------COMPARE IDS-------------------------------------------
template <class ItemType>
int LinkedList<ItemType>::compareIDs(Node<ItemType>* n1, Node<ItemType>* n2){
    return -666;
}
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
    return -666;
}
#endif