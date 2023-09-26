/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorSD.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 14 de abril de 2020, 12:33
 */

#include <cassert>
#include "VectorSD.h"

using namespace std;

VectorSD::VectorSD() {
    reservar(10);
}

VectorSD::VectorSD(int n) {
    reservar(n);
}

void VectorSD::reservar(int n) {
    assert(n > 0);
    info = new int[n];
    util = 0;
    capacidad = n;
}

int VectorSD::getDato(int posicion) const {
    assert(posicion >= 0 && posicion < util);
    return info[posicion];
}

int VectorSD::nElementos() const {
    return util;
}

void VectorSD::aniadir(int dato) {
    if (capacidad == util) {
        int *v_ampliado = new int[capacidad * 2];
        for (int i = 0; i < capacidad; i++) {
            v_ampliado[i] = info[i];
        }
        delete[] info;
        info = v_ampliado;
        capacidad *= 2;
    }
    info[util] = dato;
    util++;
}

void VectorSD::copia(const VectorSD &vector) {
    liberar();
    reservar(vector.util);
    util = vector.util;
    for (int i = 0; i < util; i++) {
        info[i] = (vector.info)[i];
    }
}

void VectorSD::liberar() {
    if (info != nullptr) {
        delete[] info;
        info = nullptr;
    }
    capacidad = 0;
    util = 0;
}

void VectorSD::mostrar(ostream& flujo) const {
    for (int i = 0; i < util; i++) {
        flujo << info[i] << " ";
    }
    flujo << endl;
}

void VectorSD::leer(istream& flujo) {
    int dato;
    while (flujo >> dato) {
        aniadir(dato);
    }

}





