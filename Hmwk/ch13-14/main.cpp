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
    cout<<"Type 1 for Problem 13.1\n";
    cout<<"Type 2 for Problem 13.2\n";
    cout<<"Type 3 for Problem 13.4\n";
    cout<<"Type 4 for Problem 13.6\n";
    cout<<"Type 5 for Problem 13.14\n";
    cout<<"Type 6 for Problem 14.1\n";
    cout<<"Type 7 for Problem 14.2\n";
    cout<<"Type 8 for Problem 14.3\n";
    cout<<"Type 9 for Problem 14.4\n";
    cout<<"Type 10 for Chpt 14 Problem 4 Review\n";
    cout<<"Type 0 to exit\n";
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

//Problem 13.1
void problem1(){
    cout<<"Name three different C++ classes that can be used to create "
            "input streams.\n";
    cout<<"fstream, ifstream, and istringstream. The first two are for"
            " file IO, and the last one is for reading and writing"
            " strings.\n\n";
}

//Problem 13.2
void problem2(){
    cout<<"Name three different C++ classes that can be used to create "
            "output streams.\n";
    cout<<"ftream and ofstream for file IO, and ostringstream for "
            "reading and writing strings.\n\n";
}

//Problem 13.4
void problem3(){
    cout<<"Why is it important for a program to close an open file as soon "
            "as it is done using the file? Give two reasons.\n";
    cout<<"Information isn't written until the file is closed, prior to that"
            " it is held in a buffer waiting.\n\n";
}

//Problem 13.6
void problem4(){
    cout<<"Which file open flag causes the contents of an existing file "
            "to be discarded and the file size reduced to zero?\n";
    cout<<"ios::trunc\n If the file being opened exists, its contents "
            "are discarded and its size is truncated to zero.\n\n";
}

//Problem 13.14
void problem5(){
    cout<<"Describe the purpose of the eof member function.\n";
    cout<<"This member function returns true (nonzero) if the eofbit flag is"
            " set; otherwise returns false. This is used to tell when "
            "the file it is reading becomes empty.\n\n";
}

//Problem 14.1
void problem6(){
    cout<<"What is a recursive function's base case.\n";
    cout<<"It is a subproblem that is simple enough to be solved directly. "
            "This occurs when the breaking down process stops.\n\n";
}

//Problem 14.2
void problem7(){
    cout<<"What happens if a recursive function does not handle base cases"
            " correctly?\n";
    cout<<"It will end up creating the subproblems wrong, and coming up "
            "with something that is not what was intended.\n\n";
}

//Problem 14.3
void problem8(){
    cout<<"What will the following program display?\n";
    cout<<"10\n\n";
}

//Problem 14.4
void problem9(){
    cout<<"What is the difference between direct and indirect recursion.\n";
    cout<<"Direct incursion is when a function directly calls itself. "
            "Indirect incursion is when one function repeatedly "
            "calls different function to continuously perform a task.\n\n";
}

//Chapter 14 Problem 4 Review
void problem10(){
    cout<<"The ______ of recursion is the number of times a function calls "
            "itself\n";
    cout<<"depth.\n\n";
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 