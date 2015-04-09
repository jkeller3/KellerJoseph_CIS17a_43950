#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "newfile.h"

void acctNum(Account chkAcct);
void balance(Account chkAcct);
void checks(Account chkAcct);
void deposits(Account chkAcct);
void finBal(Account chkAcct);

int main(int argc, char** argv) {

    Account chkAcct;
    acctNum(chkAcct);
    balance(chkAcct);
    checks(chkAcct);
    deposits(chkAcct);
    finBal(chkAcct);
    
    return 0;
}

void acctNum(Account chkAcct)
{
    int num;
    cout<<"Enter your 5-digit account number.\n";
    do
    {
       cin>>num;
       if(num<10000||num>99999)
       {
           num=0;
           cout<<"You have entered an invalid account number.\n";
       }
    }while(num == 0);
    chkAcct.acctNum = num;
}

void balance(Account chkAcct)
{
    float balance = -1;
    cout<<"What was your balance?\n";
    while(balance < 0)
    {
        cin>>balance;
        if(balance<0)
        {
            cout<<"Invalid balance.\n";
        }
    }
    chkAcct.balance = balance;
}

void checks(Account chkAcct)
{
    float input = 0;
    int count = 0;
    vector<float>checks;
    cout<<"Enter the amount for each check you wrote. Enter -1 when done.\n";
    do{
        cin>>input;
        if(input!=-1)
        {
            checks.push_back(input);
            count++;
        }
    }while(input!=-1);
    cout<<100;
    chkAcct.chks = checks.data();
    chkAcct.chkSize = count;
}

void deposits(Account chkAcct)
{
    float input = 0;
    int count = 0;
    vector<float>deposits;
    cout<<"Enter the amount for each deposit you made. Enter -1 when done.\n";
    do{
        cin>>input;
        if(input!=-1)
        {
            deposits.push_back(input);
            count++;
        }
    }while(input!=-1);
    cout<<100;
    chkAcct.dpst = deposits.data();
    chkAcct.dpstSize = count;
}

void finBal(Account chkAcct)
{
    for(int i=0; i<chkAcct.chkSize; i++)
    {
        chkAcct.balance-=chkAcct.chks[i];
    }
    //for(int i=0; i<chkAcct.dpstSize; i++)
    //{
        //chkAcct.balance+=chkAcct.dpst[i];
    //}
    if(chkAcct.balance<0)
    {
        cout<<"You have gone past your balance limit, this incurs a $12 fee.\n";
        chkAcct.balance-=12;
    }
    cout<<"Your final balance is: "<<chkAcct.balance<<".\n";
}