

#include "Racional.h"
using namespace std;

Racional:: Racional(): numerador(0), denominador(1);{}

Racional:: Racional(int numero): numerador(numero), denominador(1);{}

Racional :: Racional (int num, int den): numerador(num), denominador(den);{}

int Racional :: getNumerador(){return numerador;}

int Racional :: getDenominador(){return denominador;}

double valorDouble(){return(numerador/denominador);}

void MCD(){
    
    if (numerador!=0){
        
        
    }
}





