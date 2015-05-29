/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on May 28, 2015, 7:03 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void def(int);

int main(int argc, char** argv) {
    int inN;
    do{
        menu();
        inN=getN();
        switch(inN){
            case 1:
                problem1();
                break;
            case 2:
                problem2();
                break;
            case 3:
                problem3();
                break;
            case 4:
                problem4();
                break;
            case 5:
                problem5();
                break;
            case 6:
                problem6();
                break;
            case 7:
                problem7();
                break;
            case 8:
                problem8();
                break;
            case 9:
                problem9();
                break;
            case 10:
                problem10();
                break;
            default:
                def(inN);
        }    
    }while(inN>0);
    return 0;
}

void menu()
{
    cout<<"Type 1 for Problem 13.\n";
    cout<<"Type 2 for Problem 13.\n";
    cout<<"Type 3 for Problem 13.\n";
    cout<<"Type 4 for Problem 13.\n";
    cout<<"Type 5 for Problem 13.\n";
    cout<<"Type 6 for Problem 14.\n";
    cout<<"Type 7 for Problem 14.\n";
    cout<<"Type 8 for Problem 14.\n";
    cout<<"Type 9 for Problem 14.\n";
    cout<<"Type 10 for Problem 14.\n";
    cout<<"Type 0 to exit\n";
}


//Problem 13.
void problem1(){
    
}

//Problem 13.
void problem2(){
    
}

//Problem 13.
void problem3(){
    
}

//Problem 13.
void problem4(){
    
}

//Problem 13.
void problem5(){
    
}

//Problem 14.
void problem6(){
    
}

//Problem 14.
void problem7(){
    
}

//Problem 14.
void problem8(){
    
}

//Problem 14.
void problem9(){
    
}

//Problem 14.
void problem10(){
    
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 