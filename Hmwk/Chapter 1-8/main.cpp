/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on February 25, 2015, 3:35 PM
 */


#include <iostream>//input/output
#include <iomanip>//used to format the output for the chart on problem 1
#include <cmath>//used for power function
using namespace std;

void menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void timesTen(int);
void problem6();
void problem7();
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
            default:
                def(inN);
        }    
    }while(inN>=1 && inN<=7);

    return 0;
}

void menu()
{
    cout<<"Enter 1 for Problem 3.12\n";
    cout<<"Enter 2 for Problem 3.13\n";
    cout<<"Enter 3 for Problem 4.10\n";
    cout<<"Enter 4 for Problem 5.11\n";
    cout<<"Enter 5 for Problem 6.7\n";
    cout<<"Enter 6 for Problem 7.6\n";
    cout<<"Enter 7 for Problem 8.7\n";
    cout<<"Enter any other number to exit\n";
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

//Problem 3.12
void problem1()
{
    cout<<"If the User Enters   ";
    cout<<"The Program Will Display What Number\n";
    cout<<setfill(' ')<<setw(50);
    cout<<"(Stored in value 3)\n";
    cout<<setfill('_')<<setw(60);
    cout<<"_\n";
    /*
     * Recreates the appearance of the chart from the book.
     */
    
    float value1[4]={2e0f,5e0f,4.3e0f,6e0f};
    //Preset the values the user enters from the chart
    for(int i=0; i<4; i++)
    {
        int value2 = 2 * pow(value1[i],2);
        float value3 = 3 + value2/2-1;
        
        cout<<setfill(' ')<<setw(9);
        cout<<value1[i];
        cout<<setfill(' ')<<setw(31);
        cout<<value3<<endl;
        /*
         * Formatting the chart output
         */
    }
}

//Problem 3.13
void problem2()
{
    const float PI=3.14159;
    float volume, radius, height;
    cout<<"This program will tell you the volume of\n";
    cout<<"a cylinder-shaped fuel tank.\n";
    cout<<"How tall is the tank? ";
    cin>>height;
    cout<<"What is the radius of the tank? ";
    cin>>radius;
    volume=PI*pow(radius, 2)*height;//Formula for finding volume in a cylinder.
    cout<<"The volume of the tank is: "<<volume<<".\n";
}

//Problem 4.10
void problem3()
{
    cout<<"In problem 4.10"<<endl;
    bool soldOut;//Used to check if performance is sold out.
    cout<<"Is the performance sold out? Type 1 for yes, and type 0 for no.\n";
    cin>>soldOut;
    if(soldOut==true) //If performance is sold out, outputs following message
    {
        cout<<"The performance is sold out!\n";
    }
}

//Problem 5.11
void problem4()
{
    for(int count=0; count<50; count++)
    {
        if(count%2==1) //Outputs only odd numbers
        {
            cout<<count<<endl;
        }
    }
}

//Problem 6.7
void problem5()
{
    cout<<"Enter a number.\n";
    int num = getN();
    timesTen(num);
}

//Function used to multiply the input number by 10.
void timesTen(int number)
{
    cout<<number<<" times ten is: "<<number*10<<endl;
}

//Problem 7.6
void problem6()
{
    cout<<"Constructor functions have the same name as the \n";
    cout<<"A) class\n";
}

//Problem 8.7
void problem7()
{
    const int NUM_MEN = 10;
    int fish[NUM_MEN];
    for(int count=0; count<10; count++)
    {
        cout<<"How many fish were caught by fisherman "<<count+1<<"?\n";
        cin>>fish[count];
    }
    for(int count=0; count<10; count++)
    {
        cout<<"Fisherman "<<count+1<<" caught "<<fish[count]<<" fish.\n";
    }
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
}