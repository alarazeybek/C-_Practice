/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "string"
using namespace std;


template <class ItemType>
struct Node{
    ItemType data;
    Node* next;
    Node(){
        data = nullptr;
        next = nullptr;
    }
    ~Node(){
        ItemType* eraser = &data;
        delete eraser;
        next = nullptr;
    }
    Node( ItemType* data){
        Node<ItemType>::data = *data;
        next = nullptr;
    }
    Node( ItemType* data, Node<ItemType>* nextItem){
        Node<ItemType>::data = data;
        next = nextItem;
    }
};
   
#endif