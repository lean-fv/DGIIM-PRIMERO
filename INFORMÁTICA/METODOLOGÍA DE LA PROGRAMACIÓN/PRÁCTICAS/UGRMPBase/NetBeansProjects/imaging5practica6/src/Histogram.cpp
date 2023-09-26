/**
 * @file Histogram.cpp
 * @author MP
 */
#include<iostream>
#include<string>
#include "MPTools.h"
#include "Byte.h"
#include "Histogram.h"

using namespace std;

const double Histogram::HISTOGRAM_TOLERANCE=0.01; ///< Value of the default tolerance

Histogram::Histogram (){clear();}


int Histogram:: size () const {return HISTOGRAM_LEVELS;}


void Histogram::clear(){
    for (int i=0; i<HISTOGRAM_LEVELS; i++)
        setLevel(Byte(i),0);
}

int Histogram::getLevel (Byte level) const{
    
    if (0 <= level.getValue() && level.getValue() < Byte::MAX_BYTE) 
      return _data[level.getValue()];
    
    else
      return -1;
}


void Histogram::setLevel (Byte level, int npixeles){
    
        if (0 <= level.getValue() && level.getValue() < Byte::MAX_BYTE) 
            _data[level.getValue()]=npixeles;
}


int Histogram::getMaxLevel() const {
    
    int maximo = _data[0];
    
    for (int i=1; i<HISTOGRAM_LEVELS; i++)
        if (_data[i]>maximo){
            maximo =_data[i];
        }
    
    return maximo;
}

int Histogram :: getAverageLevel() const{
    
    int suma=0;
    for (int i=0; i<HISTOGRAM_LEVELS; i++)
        suma +=_data[i];
   
    return suma/HISTOGRAM_LEVELS;
}

int Histogram::getBalancedLevel () const{
    
    int n=0;
    for (int i=0; i<HISTOGRAM_LEVELS; i++)
        n +=_data[i];
    
    double mediana = n/2;
    bool encontrado =false;
    int pos=-1;
    int f_acumulada =0;
    
    for (int i=0; !encontrado; i++){
        f_acumulada +=_data[i];
        if (f_acumulada>=mediana){
            pos=i;
            encontrado=true;
        }
    }
    
    return pos;
}

string Histogram::inspect() const{
    std::string result = "";
    for (int i = 0; i < HISTOGRAM_LEVELS; i++) {
        result += to_string(_data[i]);
    }
    result = std::to_string(mphash((unsigned char*)result.c_str(), result.length()));
    result = std::to_string(HISTOGRAM_LEVELS) + " " + result;
    return result;
}