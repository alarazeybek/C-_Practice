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
using namespace std;
//typedef Movie ItemType;

int main() {
    Movie* m = new Movie(123,1);
    Node<Movie> *node = new Node(m);
    cout<<(*node).data.getId();
    delete node;
    /*LinkedList<Movie> *list = new LinkedList(new Movie(123,1));
    cout<<(*list).getItem(1)->getId();
    delete list; */
    return 0;
}
