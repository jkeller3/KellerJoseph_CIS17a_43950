/* 
 * File:   Prob1Random.cpp
 * Author: joey
 * 
 * Created on June 11, 2015, 5:42 PM
 */
#include <cstdlib>
#include <time.h>

#include "Prob1Random.h"

Prob1Random::Prob1Random(const char n, const char* rndseq): nset(n){
    nset = n;
    set = new char[nset];
    for(int i=0; i<nset; i++){set[i] = rndseq[i];} 
    freq = new int[nset];
    numRand = 0;
}

void Prob1Random::randFromSet() {
    int randNum = rand() % 5;
    freq[randNum]++;
    numRand++;
}

int* Prob1Random::getFreq() const{
    return freq;
}

char* Prob1Random::getSet() const{
    return set;
}

int Prob1Random::getNumRand() const{
    return numRand;
}

Prob1Random::~Prob1Random() {
    delete [] set;
    delete [] freq;
}

