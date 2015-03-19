#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
vector<int> obtainValues();
void outputArray(int[],int); 
void sort(int[], int); 
float mean(int[], int);
float median(int[], int);
int* mode(int[], int);
int findMaxRepeat(int[], int);
int findModeCount(int[], int, int);
void displayMode(int*);
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
            default:
                def(inN);
        }    
    }while(inN<7);

    return 0;
}

void menu()
{
    cout<<"Type 1 for Problem 9.2\n";
    cout<<"Type 2 for Problem 9.5\n";
    cout<<"Type 3 for Problem 9.6\n";
    cout<<"Type 4 for Problem 9.7\n";
    cout<<"Type 5 for Problem 9.8\n";
    cout<<"Type 6 for Mean Median Mode problem\n";
    cout<<"Type 7 to exit\n";
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

//Problem 9.2
void problem1()
{
    cout<<"On average, with an array of 20,000 elements, how many comparisons"
            " will the linear search perform? (Assume the items being search "
            "for are consistently found in the array.)\n";
    cout<<"It'll take on average N/2 attempts, so in this case it would take "
            "10,000 attempts on average.\n\n";
}

//Problem 9.5
void problem2()
{
    cout<<"True or false: Any sort can be modified to sort in either ascending" 
           " or descending order.\n";
    cout<<"True.\n\n";
}

//Problem 9.6
void problem3()
{
    cout<<"What one line of code would need to be modified in the bubble sort"
            " to make it sort in descending, rather than ascending order? "
            "How would the revised line be written?\n";
    cout<<"The line that needs to be modified is line 46 which should be "
            "changed to 'if(array[index]>minValue'.\n\n";
}

//Problem 9.7
void problem4()
{
    cout<<"After one pass of bubble sort, which value is in order?\n";
    cout<<"The unsorted values are: 7 2 3 8 9 1\n";
    cout<<"After 1 pass: 1 7 3 8 9 2\n";
    cout<<"The 1 and 3 will be in the correct spot.\n\n";
}

//Problem 9.8
void problem5()
{
    cout<<"After one pass of selection sort, which value is in order?\n";
    cout<<"The unsorted values are: 5 7 2 8 9 1\n";
    cout<<"After 1 pass: 1 7 2 8 9 5\n";
    cout<<"The 1 will be in the correct spot.\n\n";
}

//Mean median and mode problem
void problem6()
{
    vector<int>numbers = obtainValues();
    int size = numbers.size();
    int *array = numbers.data();
    outputArray(array,size);
    sort(array,size);
    outputArray(array,size);
    float avg = mean(array,size);
    cout<<"The mean is: "<<avg<<".\n";
    float med = median(array,size);
    cout<<"The median is: "<<med<<".\n";
    int *mod; 
    mod = mode(array,size);
    displayMode(mod);
    array = new int;
    delete array;
    array = NULL;
}

//Obtain values via vector since it is unknown how many numbers will be input.
vector<int> obtainValues()
{
    vector<int>numbers;
    int input = 0;
    cout<<"Enter as many numbers as you would like.\n";
    cout<<"Enter -1 when you would like to stop.\n";
    do{
        cin>>input;
        if(input!=-1)
        {
            numbers.push_back(input);
        }    
    }while(input!=-1);
    return numbers;
}

//Outputs the values in the array.
void outputArray(int num[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n\n";
}

//Bubble sort. Lowest to highest number.
void sort(int num[], int size)
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

//Finds the mean, or average of the array.
float mean(int num[], int size)
{
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum+=num[i];
    }
    float mean = sum/static_cast<float>(size);
    return mean;
}

//Finds the median, or middle number(s) of the array
float median(int num[], int size)
{
    float median=0;
    if(size%2==1)
    {
        median=num[size/2];
        return median;
    }
    if(size%2==0)
    {
        median=(num[size/2]+num[(size/2)-1])/static_cast<float>(2);
        return median;
    }
}

//Searches for the most repeating number(s) of the array
int *mode(int num[], int size)
{
    int maxRepeat = findMaxRepeat(num, size); 
    //Finds highest frequency of repeating numbers
    if(maxRepeat==1)//If highest frequency is 1, quits searching here.
    {
        int *mode = new int [1];
        mode[0] = 0;
        mode[1] = 1;
        return mode;
    }
    int modeCount = findModeCount(num, size, maxRepeat);
    //Finds the amount of numbers that reach the highest frequency of repeats.
    int *mode = new int [modeCount+1];
    //Inserts the amount of modes there are. In addition to 2 extra as
    //appointed by instructions
    mode[0] = modeCount;
    mode[1] = maxRepeat;
    modeCount=0;
    int repeat=1;
    int number=num[0];
    for(int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat == maxRepeat)
            //Places the modes inside the mode array.
            {
                mode[modeCount+2]=number;
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return mode;
}

//Searches for the highest frequency of repeating numbers
int findMaxRepeat(int num[], int size)
{
    int number = num[0];
    int repeat = 1;
    int maxRepeat = 1;
    for (int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat>maxRepeat)
            {
                maxRepeat=repeat;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return maxRepeat;
}

//Finds the amount of numbers that reach the highest frequency.
int findModeCount(int num[], int size, int maxRepeat)
{
    int modeCount = 0;
    int repeat = 1;
    int number = num[0];
    for (int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat == maxRepeat)
            {
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return modeCount;
}

//Displays the output for the mode.
void displayMode(int *array)
{
    if(array[0] == 0)
    {
        cout<<"There are no modes as there is a max frequency of ";
        cout<<array[1]<<".\n\n";
    }
    else if(array[0] == 1)
    {
        cout<<"There is "<<array[0]<<" mode with a max frequency of ";
        cout<<array[1]<<".\n";
        cout<<"The mode is: "<<array[2]<<".\n\n";
    }
    else
    {
        cout<<"There are "<<array[0]<<" modes with a max frequency of ";
        cout<<array[1]<<"\n.";
        cout<<"The modes are: ";
        for(int i=2; i<array[0]+2; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<".\n\n";
    }
}

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 