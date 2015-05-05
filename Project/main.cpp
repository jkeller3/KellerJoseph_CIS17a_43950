/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Project 1 - CIS 17A - Connect Four
 * Created on April 24, 2015, 2:13 PM
 */

#include <cstdlib>
#include <iostream> //for cin/cout
#include <stdlib.h> //for sleep and rand functions
using namespace std;

#include "player.h"
//Stores player information: name, wins, etc.
#include "board.h"
//Stores the board itself.

void cFour(Stats, Display);
void filBoard(Display);
void dispBrd(Display);
void dltBoard(Display);
void pTurn(Display, int);
void cpuTurn();
void place(Display, int, int);
bool winChk(Display);
int getNum();

int main(int argc, char** argv) {
    Stats p;
    Display cf;
    srand (time(NULL));
    //Use of rand for CPU's "AI" until I know how to implement a true AI.
    cFour(p, cf);
    dltBoard(cf);
    //Deletes game board when finished.
    return 0;
}

//Where the actual game takes place
void cFour(Stats p, Display cf){
    cout<<"Welcome to my game of Connect Four.\n";
    cout<<"You will be facing an AI. "
            "You will be 'B', and the CPU will be 'R'.\n;"
    cout<<"Would you like to go first or second?\n";
    cout<<"Enter 1 for first, 2 for second.\n";
    int n = getNum();
    //n will be used as a turn count. 
    while(n>2||n<1){
        cout<<"Please enter 1, or 2.\n";
        n=getNum();
    };
    filBoard(cf);
    //Sets up game board.
    bool fiar = false;
    //"Four in a row". Runs game until a four in a row is found.
    while(fiar=false){
        dispBrd(cf);
        //Displays the game board.
        int colPlace;
        if(n == 1){
            pTurn(cf, n);
            n++;
        }
        else if(n == 2){
            cpuTurn(cf, n);
            n--;
        }
        fiar = winChk(cf);
    }
}

//Game board setup.
void filBoard(Display cf){
    cf.board = new char* [cf.ROWS];
    for(int i=0; i<cf.ROWS; i++){
        cf.board[i] = new char [cf.COLS];
    }
    for(int i=0; i<cf.ROWS; i++){
        for(int j=0; j<cf.COLS; j++){
            cf.board[i][j]='O';
        }
    }
}

void dispBrd(Display cf){
    for(int i=0; i<cf.ROWS; i++){
        for(int j=0; j<cf.COLS; j++){
            cout<<cf.board[i][j];
        }
        cout<<endl;
    }
}

void dltBoard(Display cf){
    for(int j=0; j<cf.COLS; j++){
        delete [] cf.board [j];
    }
    delete [] cf.board;
}

void pTurn(Display cf, int n){
    cout<<"Player's turn.\n";
    cout<<"Which column would you like to place your piece?\n";
    int colPlace = getNum();
    place(cf, n, colPlace);
    //Function used to place piece.
}

void cpuTurn(Display cf, int n){
    cout<<"CPU's turn.\n";
    sleep(5000);
    //Used to emulate the CPU "thinking".
    //Also gives user time to see the board before it's their turn again.
    int colPlace = rand()%7+1;
    place(cf, n);
    //Simple rand "AI" for CPU until I learned how to 
    //implement a proper AI.
}

void place(Display cf, int n, int colPlace){
    for(int i=0; i<cf.ROWS; i++){
        if(cf[i][colPlace-1]=='O'){
            if(n==1){
                cf[i][colPlace-1]='B';
            }
            else{
                cf[i][colPlace-1]='R';
            }
        }
    }
}

bool winChk(Display cf){
    
}

//Obtains user int inputs.
int getNum(){
    int getN;
    do{
        cin>>getN;
        if(!(getN)){
            //Error checking for failed inputs.
            cin.clear();
            cin.ignore();
            cout<<"Invalid input, please try again.\n";
        }
    }while(getN<1||getN>7);
    //Keeps user in bounds for piece placement.
    return getN;
}