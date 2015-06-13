/* 
 * File:   main.cpp
 * Author: joey
 *
 * Created on June 6, 2015, 11:08 PM
 */

#include <cstdlib>
#include <iostream> 
#include <fstream> //file i/o
#include <time.h> //used for rand function

using namespace std;

#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"

void menu();
int getN();
void problem1();
void problem2();
void problem3(); 
void problem4();
void problem5();
void problem6();
void problem7();
void def(int inN);

int main(int argc, char** argv) {
    int inN;
    do{
        menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            default:   def(inN);}}
    while(inN<8);
    return 0;}

void menu(){
    cout<<"Which Problem would you like to view? Enter 1-7.\n";
    cout<<"Only Problem 1 was completed.\n";
    cout<<"Enter 8 to exit.\n";}

int getN(){
    int inN;
    cin>>inN;
    return inN;}

void problem1(){
    srand (time(NULL));
    char n=5;
    char rndseq[]={16,34,57,79,114};
    int ntimes=100000;
    Prob1Random a(n, rndseq);
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    //char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
	for(int j=0;j<16;j++)
	{
            //cout<<zc[i*16+j];
        }
    }
    //delete []zc;
    cout<<endl;
}

void problem3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    //Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    //const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            //cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            //cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
}
void problem4(){

}

void problem5(){
    
}

void problem6(){
    
}

void problem7(){

}

void def(int inN){cout<<"You entered "<<inN<<" to exit the program"<<endl;}