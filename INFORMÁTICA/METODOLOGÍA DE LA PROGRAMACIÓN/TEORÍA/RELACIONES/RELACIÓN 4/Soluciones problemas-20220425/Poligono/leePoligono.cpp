/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leePoligono.cpp
 * Author: Andrés Cano Utrera <Universidad de Granada>
 *
 * Created on 30 de marzo de 2020, 13:07
 */

#include <fstream>

#include <iostream>

#include "Poligono.h"

using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {
    Poligono poligono;
    if(argc == 1)
        poligono.leer(cin);
    else{
        ifstream flujo;
        flujo.open(argv[1]);
        if(!flujo){
            cerr << "Error, el fichero " << argv[1] << " no pudo abrirse" << endl;
            return 1;
        }
        poligono.leer(flujo);
        flujo.close();
    }
    cout << "Polígono leído" << endl;
    poligono.mostrar(cout);
    cout << "Área=" << poligono.getArea() << endl;
    cout << "Perímetro=" << poligono.getPerimetro() << endl;
    
    poligono.liberar();
    return 0;
}

