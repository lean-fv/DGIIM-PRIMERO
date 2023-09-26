/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 29 de marzo de 2022, 17:06
 */



#include <iostream>
#include <fstream> // ifstream

#include "VectorDinamicoChars.h"

using namespace std;


/*
 * 
 */
int main(int argc, char* argv[]) {
    VectorDinamicoChar vectorDinamico;
    
    inicializar(vectorDinamico);
    if (argc == 1)
        leer(cin, vectorDinamico);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        leer(flujo, vectorDinamico);
        flujo.close();
    }
    mostrar(cout, vectorDinamico);
    liberar(vectorDinamico); // Libera la memoria dinámica reservada
    
}

