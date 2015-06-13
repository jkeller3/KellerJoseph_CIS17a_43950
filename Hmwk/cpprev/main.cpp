/* 
 * File:   main.cpp
 * Author: joey
 *
 * Created on March 12, 2015, 7:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int fillArray();
void prntArray(int*, int);
void sort(int*, int);
void isFifty(int*, int);

int main(int argc, char** argv) {
    int size;
    cout<<"How big is the array?\n";
    cin>>size;
    int *array = new int [size];
    srand(time(NULL));
    for(int i=0; i<size; i++){
        array[i]=fillArray();
    }
    cout<<"Unsorted: ";
    prntArray(array, size);
    sort(array, size);
    cout<<"\nSorted using Bubble sort: ";
    prntArray(array,size);
    isFifty(array,size);
    
    return 0;
}

int fillArray(){
    return rand() % 90 + 10;
}

void prntArray(int* array, int size){
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
}

void sort(int* num, int size)
{
    int i, j, flag = 1;
    int temp;
    for(i = 1; (i <= size) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (size -1); j++)
        {
            if (num[j+1] < num[j])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                flag = 1;
            }
        }
    }
    return;
}

void isFifty(int* array, int size){
    int counter = 0;
    for(int i=0; i<size; i++){
        if(array[i]==50){counter++;}
    }
    cout<<"\nThere were "<<counter<<" 50s.\n";
}