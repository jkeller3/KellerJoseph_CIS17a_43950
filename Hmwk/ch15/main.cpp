/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on May 28, 2015, 6:14 PM
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
            default:
                def(inN);
        }    
    }while(inN>0);
    return 0;
}

void menu()
{
    cout<<"Type 1 for Problem 15.1\n";
    cout<<"Type 2 for Problem 15.2\n";
    cout<<"Type 3 for Problem 15.3\n";
    cout<<"Type 4 for Problem 15.7\n";
    cout<<"Type 5 for Problem 15.8\n";
    cout<<"Type 0 to exit\n";
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

//Problem 15.1
void problem1(){
    cout<<"Explain the difference between static binding and "
            "dynamic binding.\n";
    cout<<"In short, static binding uses information available during compile "
            "time, and dynamic binding occurs during run time.\n\n";
}

//Problem 15.2
void problem2(){
    cout<<"Are virtual functions statically bound or dynamically bound?\n";
    cout<<"They are abstract classes and cannot be instantiated. They are only "
            "used to derive other classes, so they are dynamically bound.\n\n";
}

//Problem 15.3
void problem3(){
    cout<<"What will the following program display?\n";
    cout<<"It will display: \n"
            "1\n"
            "5\n\n";
}

//Problem 15.7
void problem4(){
    cout<<"How can you tell from looking at a class declaration that a virtual"
            " member function is pure?\n";
    cout<<"You can tell if it is pure if it is set equal to 0:\n"
            "void draw() = 0;\n\n";
}

//Problem 15.8
void problem5(){
    cout<<"What makes an abstract class different from other classes?\n";
    cout<<"A class with at least one pure virtual function is called "
            "an abstract class.\n\n";
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 