/* 
 * File:   Prob2Sort.cpp
 * Author: joey
 * 
 * Created on June 11, 2015, 10:21 PM
 */

#include "Prob2Sort.h"

Prob2Sort<char> rc;

template<class T>
Prob2Sort<T>::Prob2Sort() {
    index=NULL;
}

template<class T>
T* Prob2Sort<T>::sortArray(const T* ch2p,int a, bool ascending){
    
}

template<class T>
T* Prob2Sort<T>::sortArray(const T* ch2p,int a,int b,int column ,bool ascending){
    
}

template<class T>
Prob2Sort<T>::~Prob2Sort() {
    delete[] index;
}

