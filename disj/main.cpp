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
    Movie* mptr =  new Movie(133,5);
    Node<Movie>* tm = new Node<Movie>(mptr);
    LinkedList<Movie>* dene = new LinkedList<Movie>();

    dene->insert(tm);
  /*  Movie* nptr = &Movie(12,5);
    Node<Movie>* a = &Node<Movie>(nptr);
    dene->insert(a);
    Movie* kptr = &Movie(44,1);
    Node<Movie>* b = &Node<Movie>(kptr);
    dene->insert(b);
    dene->insert(new Node(new Movie(44,1)));
    dene->insert(new Node(new Movie(1,1)));
    dene->insert(new Node(new Movie(0,5551)));
    dene->insert(tm);
    int length = dene.getLength();
    cout<<"Length: "<<length<<endl;
    cout<<"Is exist? False:"<<false<<" and result: "<<dene.isExist(tm)<<endl;
    */
   int length = dene->getLength();
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl;
        length--;
    }
  //  dene->remove(tm);
    while(length > 0){
        cout<<dene->getItem(length)->getId()<<endl;
        length--;
    }
    delete dene;
}
