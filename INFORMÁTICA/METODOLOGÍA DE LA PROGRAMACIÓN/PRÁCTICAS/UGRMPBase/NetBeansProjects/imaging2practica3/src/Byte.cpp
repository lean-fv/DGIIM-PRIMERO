/**
 * @file Byte.cpp
 * @author MP
 */
#include <iostream>
#include <string>
#include "MPTools.h"
#include "Byte.h"

using namespace std;



void Byte:: onBit(int pos)
{
    unsigned char mask = 1;
    mask = mask<<pos;
    
    _data = _data|mask;
}


void Byte:: offBit(int pos)
{
    
    unsigned char mask = 1;
    mask = ~(mask<<pos);
    
    _data = _data&mask;
 
}


bool Byte:: getBit(int pos) const
{
    unsigned char mask = 1;
    mask = mask << pos;
    
    bool uno = false;
    if ((_data&mask) != 0) uno = true;
    
    return uno;
}


string Byte:: to_string() const
{
    string cad;
    for (int i=0; i<MAX_BIT; i++)
        if (getBit(i)) cad+='1';
        else cad+='0';
    
    return cad;
}


void Byte:: onByte()
{
    
    for (int i=0; i<MAX_BIT; i++)
        if (!getBit (i)) onBit(i);

}


void Byte:: offByte()
{
    for (int i=0; i<MAX_BIT; i++)
        if (getBit (i)) offBit(i);

}


void Byte:: encodeByte(const bool v[])
{
    
  for (int i=0; i<MAX_BIT; i++)
        if (v[i] == true) 
            onBit(MAX_BIT-1-i);

}


void Byte:: decodeByte(bool v[]) const
{
    for (int i=0; i<MAX_BIT; i++)
        v[i] = getBit (i);

}


void Byte:: decomposeByte(int posits[], int &n) const
{
    n = 0;
    for (int i=0; i<MAX_BIT; i++)
        if (getBit(i)){
            posits[n] = i;
            n++;
        }
    

}

void Byte:: shiftRByte(int n)
{
    _data = _data >> n;

}

void Byte:: shiftLByte(int n)
{
    _data = _data << n;

}

void Byte:: mergeByte(Byte merge, int percentage)
{
    _data = _data * (100-percentage) + merge.getValue()*percentage/100;
}