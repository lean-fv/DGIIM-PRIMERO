/**
 * @file Byte.cpp
 * @author MP
 */
#include <iostream>
#include <string>
#include "MPTools.h"
#include "Byte.h"

using namespace std;



void onBit(Byte  &b, int pos)
{
    Byte mask = 1;
    mask = mask<<pos;
    
    b = b|mask;
}


void offBit(Byte  &b, int pos)
{
    
    Byte mask = 1;
    mask = ~(mask<<pos);
    
    b = b&mask;
 
}


bool getBit(Byte b, int pos)
{
    Byte mask = 1;
    mask = mask << pos;
    
    bool uno = false;
    if ((b&mask) != 0) uno = true;
    
    return uno;
}


string to_string(Byte b)
{
    string cad;
    for (int i=0; i<MAX_BIT; i++)
        if (getBit(b,i)) cad+='1';
        else cad+='0';
    
    return cad;
}


void onByte(Byte &b)
{
    
    for (int i=0; i<MAX_BIT; i++)
        if (!getBit (b,i)) onBit(b,i);

}


void offByte(Byte  &b)
{
    for (int i=0; i<MAX_BIT; i++)
        if (getBit (b,i)) offBit(b,i);

}


void encodeByte(Byte  &b,  bool v[])
{
    
  for (int i=0; i<MAX_BIT; i++)
        if (v[i] == true) 
            onBit(b,MAX_BIT-1-i);

}


void decodeByte(Byte b, bool v[])
{
    for (int i=0; i<MAX_BIT; i++)
        v[i] = getBit (b,i);

}


void decomposeByte(Byte b, int posic[], int &cuantos)
{
    cuantos = 0;
    for (int i=0; i<MAX_BIT; i++)
        if (getBit(b,i)){
            posic[cuantos] = i;
            cuantos++;
        }
    

}

void shiftRByte(Byte &b, int n)
{
    b = b >> n;

}

void shiftLByte(Byte &b, int n)
{
    b = b << n;

}

void mergeByte(Byte &carrier, Byte merge, int percentage)
{
    carrier = carrier * (100-percentage) + merge*percentage/100;
}