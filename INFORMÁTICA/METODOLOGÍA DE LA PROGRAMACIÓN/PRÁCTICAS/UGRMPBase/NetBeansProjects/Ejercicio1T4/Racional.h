#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

class Racional{
    
private:
    
    int numerador;
    int denominador;
        
public:
    
    Racional();
    Racional(int numero);
    Racional(int numerador, int denominador);
    int getNumerador();
    int getDenominador();
    double valorDouble();
    void MCD (int &num, int &den);
};

#endif