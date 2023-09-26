/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz2D_1.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 29 de marzo de 2020, 14:13
 */

#include <cassert>
#include <iostream>
#include "Matriz2D_1.h"

Matriz2D_1::Matriz2D_1() {
    reservar(0, 0);
}

Matriz2D_1::Matriz2D_1(int nf, int nc) {
    reservar(nf, nc);
}

void Matriz2D_1::reservar(int nf, int nc) {
    nfilas = nf;
    ncols = nc;
    if (nfilas == 0 || ncols == 0) {
        matriz = nullptr;
    } else {
        matriz = new int*[nfilas];
        for (int fila = 0; fila < nfilas; fila++) {
            matriz[fila] = new int[ncols];
        }
    }
}

int Matriz2D_1::getNumeroFilas() const {
    return nfilas;
}

int Matriz2D_1::getNumeroColumnas() const {
    return ncols;
}

int Matriz2D_1::get(int fila, int columna) const{
    assert(fila < nfilas && columna < ncols && fila >= 0 && columna >= 0);
    return matriz[fila][columna];
}

void Matriz2D_1::set(int fila, int columna, int dato) {
    assert(fila < nfilas && columna < ncols && fila >= 0 && columna >= 0);
    matriz[fila][columna] = dato;
}

void Matriz2D_1::liberar() {
    if (matriz != nullptr) {
        for (int fila = 0; fila < nfilas; fila++) {
            delete[] matriz[fila];
        }
        delete[] matriz;
        matriz = nullptr;
    }
}

void Matriz2D_1::imprimir(std::ostream& flujo) const {
    flujo << nfilas << " " << ncols << std::endl;
    for (int fila = 0; fila < nfilas; fila++) {
        for (int col = 0; col < ncols; col++) {
            flujo << matriz[fila][col] << " ";
        }
        flujo << std::endl;
    }
}

void Matriz2D_1::leer(std::istream& flujo) {
    int nFilas, nColumnas;

    flujo >> nFilas;
    flujo >> nColumnas;
    assert(nFilas >= 0 && nColumnas >= 0);
    liberar();
    reservar(nFilas, nColumnas);
    for (int fila = 0; fila < nfilas; fila++) {
        for (int col = 0; col < ncols; col++) {
            flujo >> matriz[fila][col];
        }
    }
}

void Matriz2D_1::copiar(const Matriz2D_1 &matriz) {
    liberar();
    reservar(matriz.nfilas, matriz.ncols);
    for (int fila = 0; fila < nfilas; fila++) {
        for (int col = 0; col < ncols; col++) {
            this->matriz[fila][col] = matriz.matriz[fila][col];
        }
    }
}



