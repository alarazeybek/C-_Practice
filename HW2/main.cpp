#include <stdio.h>
#include "findMedian.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
void createRandomArray(int*& array,int*& array2,int*& array3, int size);
void createIncreasingArray(int*& array, int size);
void createDecreasingArray(int*& array, int size);
void Execution1(int* array, int const size);
void Execution2(int* array, int const size);
void Execution3(int* array, int const size);

int main(){
    //****************************************************declaration*******************************************************
    
    int *array10, *array100, *array1000, *array5000, *array10_000, *array50_000, *array100_000, *array500_000;
    int *array10_2, *array100_2, *array1000_2, *array5000_2, *array10_000_2, *array50_000_2, *array100_000_2, *array500_000_2;
    int *array10_3, *array100_3, *array1000_3, *array5000_3, *array10_000_3, *array50_000_3, *array100_000_3, *array500_000_3;
    array10 = new int[10];
    array100 = new int[100];
    array1000 = new int[1000];
    array5000 = new int[5000];
    array10_000 = new int[10000];
    array50_000 = new int[50000];
    array100_000 = new int[100000];
    array500_000 = new int[500000];

    array10_2 = new int[10];
    array100_2 = new int[100];
    array1000_2 = new int[1000];
    array5000_2 = new int[5000];
    array10_000_2 = new int[10000];
    array50_000_2 = new int[50000];
    array100_000_2 = new int[100000];
    array500_000_2 = new int[500000];

    array10_3 = new int[10];
    array100_3 = new int[100];
    array1000_3 = new int[1000];
    array5000_3 = new int[5000];
    array10_000_3 = new int[10000];
    array50_000_3 = new int[50000];
    array100_000_3 = new int[100000];
    array500_000_3 = new int[500000];

    //*******************************************random ordered array**********************************************************
    createRandomArray(array10,array10_2,array10_3, 10);
    createRandomArray(array100, array100_2, array100_3, 100);
    createRandomArray(array1000,array1000_2 , array1000_3, 1000);
    createRandomArray(array5000,array5000_2,array5000_3 , 5000);
    createRandomArray(array10_000,array10_000_2,array10_000_3, 10000);
    createRandomArray(array50_000, array50_000_2, array50_000_3, 50000);
    createRandomArray(array100_000,array100_000_2,array100_000_3, 100000);
    createRandomArray(array500_000, array500_000_2, array500_000_3, 500000);
    
    cout<<"For Algorithm 1: "<<endl;
    Execution1(array10,10);
    Execution1(array100,100);
    Execution1(array1000,1000);
    Execution1(array5000,5000);
    Execution1(array10_000,10000);
    Execution1(array50_000,50000);
    Execution1(array100_000,100000);
    Execution1(array500_000,500000);

     cout<<"\nFor Algorithm 2: "<<endl;
    Execution2(array10_2,10);
    Execution2(array100_2,100);
    Execution2(array1000_2,1000);
    Execution1(array5000_2,5000);
    Execution2(array10_000_2,10000);
    Execution2(array50_000_2,50000);
    Execution2(array100_000_2,100000);
    Execution2(array500_000_2,500000);

    cout<<"\nFor Algorithm 3: "<<endl;
    Execution3(array10_3,10);
    Execution3(array100_3,100);
    Execution3(array1000_3,1000);
    Execution3(array5000_3,5000);
    Execution3(array10_000_3,10000);
    Execution3(array50_000_3,50000);
    Execution3(array100_000_3,100000);
    Execution3(array500_000_3,500000); 
  /* //*******************************************increasing ordered array *****************************************
    createIncreasingArray(array10, 10);
    createIncreasingArray(array100, 100);
    createIncreasingArray(array1000, 1000);
    createIncreasingArray(array5000, 5000);
    createIncreasingArray(array10_000, 10000);
    createIncreasingArray(array50_000, 50000);
    createIncreasingArray(array100_000, 100000);
    //createIncreasingArray(array500_000, 500000);

    cout<<"\nFor Algorithm 3 Increasing order: "<<endl;
    Execution3(array10_3,10);
    Execution3(array100_3,100);
    Execution3(array1000_3,1000);
    Execution3(array5000_3,5000);
    Execution3(array10_000_3,10000);
    Execution3(array50_000_3,50000);
    Execution3(array100_000_3,100000);
    Execution3(array500_000_3,500000); 

    //*******************************************decreasing ordered array *****************************************
    createDecreasingArray(array10, 10);
    createDecreasingArray(array100, 100);
    createDecreasingArray(array1000, 1000);
    createDecreasingArray(array5000, 5000);
    createDecreasingArray(array10_000, 10000);
    createDecreasingArray(array50_000, 50000);
    createDecreasingArray(array100_000, 100000);
    createDecreasingArray(array500_000, 500000);

    cout<<"\nFor Algorithm 3 Decreasing order: "<<endl;
    Execution3(array10_3,10);
    Execution3(array100_3,100);
    Execution3(array1000_3,1000);
    Execution3(array5000_3,5000);
    Execution3(array10_000_3,10000);
    Execution3(array50_000_3,50000);
    Execution3(array100_000_3,100000);
    Execution3(array500_000_3,500000);  */
    

    //**********************************delete********************************
    delete[] array10;
    delete[] array100;
    delete[] array1000;
    delete[] array5000;
    delete[] array10_000;
    delete[] array50_000;
    delete[] array100_000;
    delete[] array500_000;
    delete[] array10_2;
    delete[] array100_2;
    delete[] array1000_2;
    delete[] array5000_2;
    delete[] array10_000_2;
    delete[] array50_000_2;
    delete[] array100_000_2;
    delete[] array500_000_2;
    delete[] array10_3;
    delete[] array100_3;
    delete[] array1000_3;
    delete[] array5000_3;
    delete[] array10_000_3;
    delete[] array50_000_3;
    delete[] array100_000_3;
    delete[] array500_000_3;
}
void Execution3(int* array, int const size){
    cout<<"For array of "<<size <<" elements: ";
    double duration;
    clock_t startTime = clock();
    FIND_MEDIAN_3(array, size);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}
void Execution2(int* array, int const size){
    cout<<"For array of "<<size <<" elements: ";
    double duration;
    clock_t startTime = clock();
    FIND_MEDIAN_2(array, size);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}
void Execution1(int* array, int const size){
    cout<<"For array of "<<size <<" elements: ";
    double duration;
    clock_t startTime = clock();
    FIND_MEDIAN_1(array, size);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}
void createRandomArray(int*& array,int*& array2,int*& array3, int size){
    for(int a = 0; a < size; a++){
        array[a] = rand() % size*2 -size; //choses number from -size to size
        array2[a] = array[a];
        array3[a] = array[a];
    }
}
void createIncreasingArray(int*& array, int size){
    for(int a = 0; a < size; a++){
        array[a] = a ;
    }
}
void createDecreasingArray(int*& array, int size){
    for(int a = 0; a < size; a++){
        array[a] = size - a ;
    }
}