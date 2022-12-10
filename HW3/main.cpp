/*
*Alara Zeybek
*22102544
*Section-002
*CS201 HW3
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
#include "Movie.h"
#include "Subscriber.h"
#include "Transaction.h"
using namespace std;
//typedef Movie ItemType;

int main() {
    Movie* m = new Movie(133,5);
    Node<Movie>* tm = new Node(m);
    LinkedList<Movie> dene;
/*    dene.insert(new Node(new Movie(9,1)));
    dene.insert(new Node(new Movie(8,1)));
    dene.insert(new Node(new Movie(7,1)));
    dene.insert(new Node(new Movie(6,1)));
    dene.insert(new Node(new Movie(5,1)));
    int length = dene.getLength();
    while(length > 0){
        cout<<dene.getItem(length)->getId()<<endl;
        length--;
    }
*/
    dene.insert(tm);
    dene.insert(new Node(new Movie(88,1)));
    dene.insert(new Node(new Movie(8232,1)));
    dene.insert(new Node(new Movie(44,1)));
    dene.insert(new Node(new Movie(1,1)));
    dene.insert(new Node(new Movie(0,5551)));
    dene.insert(tm);
    int length = dene.getLength();
    cout<<"Length: "<<length<<endl;
    cout<<"Is exist? False:"<<false<<" and result: "<<dene.isExist(tm)<<endl;
    while(length > 0){
        cout<<dene.getItem(length)->getId()<<endl;
        length--;
    }
    
}
