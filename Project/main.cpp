/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Project 1 - CIS 17A - Connect Four
 * Created on April 24, 2015, 2:13 PM
 */

#include <cstdlib>
#include <iostream> //for cin/cout
#include <stdlib.h> //for rand function
#include <unistd.h> //for sleep
using namespace std;

#include "player.h"
//Stores player information: name, wins, etc.
#include "board.h"
//Stores the board itself.

void cFour(Stats, Display&);
void filBoard(Display&);
void dispBrd(Display&);
void dltBoard(Display&);
int pTurn(Display&, int);
int cpuTurn(Display&, int);
bool place(Display&, int, int);
bool winChk(Display&, int, int);
bool isFull(Display&);
bool outcome(Stats&, bool, int);
int getNum();

int main(int argc, char** argv) {
    Stats p;
    Display cf;
    srand (time(NULL));
    //Use of rand for CPU's "AI" until I know how to implement a true AI.
    cFour(p, cf);
    /*Everything takes place here. Would have more function calls in
    *main if it weren't for the fact that I'd be passing so many variables
    *back and forth through here.
    */
    return 0;
}

//Where the actual game takes place
void cFour(Stats p, Display&cf){
    bool plyAgn;
    //Will later be used to ask if they'd like to play again.
    cout<<"Welcome to my game of Connect Four.\n";
    cout<<"You will be facing an AI. "
            "You will be 'B', and the CPU will be 'R'.\n";
    do{
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
    bool full = false;
    //Stays false until there are no more moves. If the last move
    //doesn't result in a connect four, then a draw is declared.
    while(fiar==false&&full==false){
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
        fiar = winChk(cf, colPlace, n);
        full = isFull(cf);
    }
    dltBoard(cf);
    //Deletes game board when finished.
    plyAgn = outcome(p, fiar, n);
    //Displays outcome and checks if they would like to play again.
    }while(plyAgn==true);
}

//Game board setup.
void filBoard(Display&cf){
    cf.board = new char* [cf.ROWS];
    for(int i=0; i<cf.ROWS; i++){
        cf.board[i] = new char [cf.COLS];
    }
    for(int i=0; i<cf.ROWS; i++){
        for(int j=0; j<cf.COLS; j++){
            cf.board[i][j]='O';
            //'O' is used to signify an empty space.
        }
    }
}

void dispBrd(Display&cf){
    cout<<"Col: 1 2 3 4 5 6 7\n";
    for(int i=0; i<cf.ROWS; i++){
        cout<<"     ";
        for(int j=0; j<cf.COLS; j++){
            cout<<cf.board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dltBoard(Display&cf){
    for(int j=0; j<cf.COLS; j++){
        delete [] cf.board [j];
    }
    delete [] cf.board;
}

int pTurn(Display&cf, int n){
    int colPlace;
    bool colFull;
    //Used to loop until player successfully places a piece.
    cout<<"Player's turn.\n";
    do{
        cout<<"Which column would you like to place your piece?\n";
        colPlace = getNum();
        colFull = place(cf, n, colPlace);
        if(colFull == true){
            cout<<"That column is full. Try another column.\n";
        }
        //Function used to place piece.
    }while (colFull == true);
    return colPlace;
}

int cpuTurn(Display&cf, int n){
    bool colFull;
    int colPlace;
    cout<<"CPU's turn.\n";
    sleep(5);
    //Used to emulate the CPU "thinking".
    //Also gives user time to see the board before it's their turn again.
    do{
        colPlace = rand()%7+1;
        colFull = place(cf, n, colPlace);
    }while(colFull == true);
    //Simple rand "AI" for CPU until I learned how to 
    //implement a proper AI.
    return colPlace;
}

//Used to place piece in the column of the players' choosing.
bool place(Display&cf, int n, int colPlace){
    colPlace--;
    //Decrements as the inputs will be columns 1-7 as opposed to 0-6.
    if(cf.board[0][colPlace]!='O')
    //Immediately checks to see if the final row in the choice column
    //is full already, if it is, exit function to repeat.
    {
        return true;
    }
    for(int i=5; i>=0; i--){
        if(cf.board[i][colPlace]=='O'){
        //Signifies loop until an empty space is found.
            if(n==1){
                cf.board[i][colPlace]='B';
                return false;
            }
            else{
                cf.board[i][colPlace]='R';
                return false;
            }
        }
    }
}

bool winChk(Display&cf, int colPlace, int n){
    colPlace--;
}

bool isFull(Display&cf){
    for(int i=0; i<cf.ROWS; i++){
        if(cf.board[i][5]=='O'){
            return false;
        }
    }
    return true;
}

bool outcome(Stats&p, bool fiar, int n){
    if(fiar==true){
        /*Uses the final turn to determine winner.
        * Since n is incremented/decremented after their move, I use the 
        * inverse values here.
        */
        if(n == 2){
            cout<<"You win!\n";
            p.wins++;
        }
        if(n == 1){
            cout<<"You lose!\n";
            p.losses++;
        }
    }
    else{
        cout<<"It's a draw.\n";
        p.draws++;
    }
    cout<<"Wins: "<<p.wins<<".\n";
    cout<<"Losses: "<<p.losses<<".\n";
    cout<<"Ties: "<<p.draws<<".\n";
    //Output player stats.
    cout<<"Play again?\n";
    cout<<"Enter 1 for yes. 2 for no.\n";
    int again = getNum();
    while(again>2||again<1){
        cout<<"Please enter 1, or 2.\n";
        again=getNum();
    };
    if(again==1){
        return true;
    }
    else if(again==2){
        return false;
    }
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