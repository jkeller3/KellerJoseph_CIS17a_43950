/* 
 * File:   ch10-12hw
 * Author: Joseph Keller
 *
 * Created on March 30, 2015, 2:37 PM
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
    cout<<"Type 1 for Problem 10.1\n";
    cout<<"Type 2 for Problem 10.4\n";
    cout<<"Type 3 for Problem 10.6\n";
    cout<<"Type 4 for Problem 11.9\n";
    cout<<"Type 5 for Problem 11.11\n";
    cout<<"Type 6 for Problem 12.7\n";
    cout<<"Type 7 for Problem 12.8\n";
    cout<<"Type 8 for Problem 12.9\n";
    cout<<"Type 9 for Problem 12.10\n";
    cout<<"Type 10 for Problem 12.11\n";
    cout<<"Type 0 to exit\n";
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

//Problem 10.1
void problem1()
{
    cout<<"Write a statement that displays the address of the variable"
            " count.\n";
    cout<<"cout<<&count;\n\n";
}

//Problem 10.4
void problem2()
{
    int x=50, y=60, z=70;
    int *ptr;
    ptr=&x;
    *ptr *=10;
    ptr = &y;
    *ptr *=5;
    ptr = &z;
    *ptr *=2;
    cout<<x<<" "<<y<<" "<<z<<endl;
    cout<<"10.4) This is the output of the program in 10.4. The pointer takes "
            "in the values of xyz, and multiplies them by different amounts, "
            "changing the original values and outputting them.\n\n";
}

//Problem 10.6
void problem3()
{
    cout<<"10.6) Assume ptr is a pointer to an int and holds the address 12000."
            " On a system with 4-byte integers, what address will be in ptr "
            "after the following statement? 'ptr+=10;'\n";
    cout<<"Since each int would take up 4 bytes, it would increase by "
            "4 for everyone 1 it adds. By adding 10, it would add 40. "
            "The address in ptr after the statement would be 12040.\n\n";
}

//Problem 11.9
void problem4()
{
    cout<<"Describe two scenarios in which memberwise assignment occurs."
            "\n";
    cout<<"Memberwise assignment is used to assign one object to another, "
            "or to initialize one object with another object's data.\n\n";
}

//Problem 11.11
void problem5()
{
    cout<<"When is a copy constructor called?\n";
    cout<<"A copy constructor is called whenever a new object is created "
            "and initialized with the data of another object of the same "
            "class.\n\n";
}

//Problem 12.7
void problem6()
{
    const int LENGTH = 20;
    char iceCream[LENGTH];
    cout<<"12.7) What flavor of ice cream do you like best? ";
    cout<<"Chocolate, Vanilla, or Pralines and Pecan? ";
    cin.getline(iceCream,LENGTH);
    cout<<"Here is the number of fat grams for half ";
    cout<<"cup serving:\n";
    if(iceCream[0] == 'C' || iceCream[0] == 'c')
        cout<<"Chocolate: 9 fat grams.\n";
    else if(iceCream[0] == 'V' || iceCream[0] == 'v')
        cout<<"Vanilla: 10 fat grams.\n";
    else if(iceCream[0] == 'P' || iceCream[0] == 'p')
        cout<<"Pralines and Pecan: 14 fat grams.\n";
    else
        cout<<"That's not one of our flavors!\n";
}

//Problem 12.8
void problem7()
{
    cout<<"Write a short description for each of the following functions.\n";
    cout<<"atoi: Converts C-string to an int and returns the value.\n";
    cout<<"atol: Converts C-string to a long int and returns the value.\n";
    cout<<"atof: Converts C-string to a float or double, and returns the value."
            "\n";
    cout<<"itoa: Converts int to a C-string where the first argument is the"
            " integer, which is stored by the second argument, or the pointer,"
            " and the third argument specifies the numbering system\n\n";
}

//Problem 12.9
void problem8()
{
    cout<<"Write a statement that will convert the C-string \"10\" to an "
            "integer and store the result in variable num\n";
    cout<<"int num = atoi(\"10\");\n\n";
}

//Problem 12.10
void problem9()
{
    cout<<"Write a statement that will convert the C-string \"100000\" "
            "to a long and store the result in the variable num\n";
    cout<<"long int num = atol (\"100000\");\n\n";
}

//Problem 12.11
void problem10()
{
    cout<<"Write a statement that will convert the string \"7.2389\" to a"
            "  double and store the result in the variable num\n";
    cout<<"double num = atof(\"7.2389\");\n\n";
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 