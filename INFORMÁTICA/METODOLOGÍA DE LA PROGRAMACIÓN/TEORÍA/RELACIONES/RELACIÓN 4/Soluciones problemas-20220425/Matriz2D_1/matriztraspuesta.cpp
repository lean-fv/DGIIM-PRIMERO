/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriztraspuesta.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 29 de marzo de 2020, 14:12
 */

#include <iostream>
#include <fstream>

#include "Matriz2D_1.h"

using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {
    Matriz2D_1 matriz;

    if (argc == 1)
        matriz.leer(cin);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error al abrir fichero " << argv[1] << endl;
            return 1;
        }
        matriz.leer(flujo);
        flujo.close();
    }
    cout << "Matriz leída: " << endl;
    matriz.imprimir(cout);
    Matriz2D_1 matrizTraspuesta(matriz.getNumeroColumnas(), matriz.getNumeroFilas());

    for (int fila = 0; fila < matriz.getNumeroFilas(); fila++) {
        for (int col = 0; col < matriz.getNumeroColumnas(); col++) {
            matrizTraspuesta.set(col, fila, matriz.get(fila, col));
        }
    }
    cout << "Matriz traspuesta: " << endl;
    matrizTraspuesta.imprimir(cout);
    
    matriz.liberar();
    matrizTraspuesta.liberar();

    return 0;
}

