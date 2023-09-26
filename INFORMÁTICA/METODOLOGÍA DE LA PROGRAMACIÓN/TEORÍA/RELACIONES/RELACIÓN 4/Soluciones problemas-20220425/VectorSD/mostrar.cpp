/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mostrar.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 14 de abril de 2020, 12:32
 */


#include <iostream>
#include <fstream> // ifstream
#include "VectorSD.h"

using namespace std;

int main(int argc, char *argv[]) {
    VectorSD v;
    if (argc == 1)
        v.leer(cin);
    else {
        ifstream flujo(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        v.leer(flujo);
    }
    v.mostrar(cout);
    v.liberar(); // Libera la memoria dinámica reservada
}

