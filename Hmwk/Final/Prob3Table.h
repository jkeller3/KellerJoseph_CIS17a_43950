/* 
 * File:   Prob3Table.h
 * Author: joey
 *
 * Created on June 7, 2015, 12:12 AM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H
#include <string>



//template<class T>
//class Prob3Table
//{
        //protected:
                //int rows;                                 //Number of rows in the table
                //int cols;                                 //Number of cols in the table
                //T *rowSum;                                //RowSum array
                //T *colSum;                                //ColSum array
                //T *table;                                 //Table array
                //T grandTotal;                             //Grand total
                //void calcTable(void);                     //Calculate all the sums
        //public:
                //Prob3Table(string,int,int);               //Constructor then Destructor
                //~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;}
                //const T *getTable(void){return table;};
                //const T *getRowSum(void){return rowSum;};
                //const T *getColSum(void){return colSum;};
                //T getGrandTotal(void){return grandTotal;};
//};

//template<class T>
//class Prob3TableInherited:public Prob3Table<T>
//{
        //protected:
                //T *augTable;                                  //Augmented Table with sums
        //public:
                //Prob3TableInherited(char *,int,int);          //Constructor
                //~Prob3TableInherited(){delete [] augTable;};  //Destructor
                //const T *getAugTable(void){return augTable;};
//};

//template<class T>
//Prob3Table<T>::Prob3Table(char* txt, int r, int c) {
    //rows = r;
    //cols = c;
    //table = new char [r*c];
    //for(int i=0; i<r*c; i++){txt>>table[i];}
    //Prob3Table<int> tab(txt, r, c);
//}
 
//template<class T>
//void Prob3Table<T>::calcTable(){
    //rowSum = new int [rows];
    //colSum = new int [cols];
    //for(int i=0; i<rows*cols; i+5){
        //rowSum[i] = table[i]+table[i+1]+table[i+2]+table[i+3]+table[i+4];
    //}
    //for(int i=0; i<rows; i++){
        //colSum[i] = table[i]+table[i+5]+table[i+10]+table[i+15]+table[i+20];
    //}
//}
 
//template<class T>
//Prob3TableInherited<T>::Prob3TableInherited(string txt,int r,int c){
    //augTable = new int [(r+1)*(c+1)];
    //for(int i=0; i<r; i++){
        //for(int j=0; j<c; j++){
            //augTable[i][j]=this->table[i+j];
        //}
        //augTable[i][c+1]=this->rowSum[i];
    //}
    //for(int i=0; i<c+1; i++){
        //augTable[c+1][i]=this->colSum[i];
    //}
//}

 
#endif  /* PROB3TABLE_H */