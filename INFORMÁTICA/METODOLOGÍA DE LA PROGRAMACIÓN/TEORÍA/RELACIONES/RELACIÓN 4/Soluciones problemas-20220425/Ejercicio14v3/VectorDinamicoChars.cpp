/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "VectorDinamicoChars.h"

using namespace std;

void inicializar(VectorDinamicoChar &vectorDinamico) {
    vectorDinamico.arrayChar = new char[10];
    vectorDinamico.nCaracteres = 0;
    vectorDinamico.capacidad = 10;
}

void clear(VectorDinamicoChar &vectorDinamico) {
    liberar(vectorDinamico);
    inicializar(vectorDinamico);
}

void liberar(VectorDinamicoChar &vectorDinamico) {
    delete[] vectorDinamico.arrayChar;
    //inicializar(vectorDinamico);
    vectorDinamico.arrayChar = nullptr;
    vectorDinamico.nCaracteres = 0;
    vectorDinamico.capacidad = 0;
}

void mostrar(ostream& flujo, const VectorDinamicoChar &vectorDinamico) {
    for (int i = 0; i < vectorDinamico.nCaracteres; i++) {
        flujo << vectorDinamico.arrayChar[i];
    }
}

/*void redimensionar(VectorDinamicoChar &vectorDinamico, int aumento) {
    if (vectorDinamico.nCaracteres + aumento > 0) {
        char *v_ampliado = new char[vectorDinamico.nCaracteres + aumento];
        for (int i = 0; (i < vectorDinamico.nCaracteres) && 
                (i < vectorDinamico.nCaracteres + aumento); i++)
            v_ampliado[i] = vectorDinamico.arrayChar[i];
        delete[] vectorDinamico.arrayChar;
        vectorDinamico.arrayChar = v_ampliado;
        vectorDinamico.nCaracteres = vectorDinamico.nCaracteres + aumento;
    }
}*/

void aniadir(VectorDinamicoChar &vectorDinamico, char caracter) {
    //redimensionar(vectorDinamico, 1);
    if (vectorDinamico.nCaracteres == vectorDinamico.capacidad) {
        char *arrayAuxiliar;
        arrayAuxiliar = new char[vectorDinamico.capacidad * 2];
        for (int i = 0; i < vectorDinamico.capacidad; i++) {
            arrayAuxiliar[i] = vectorDinamico.arrayChar[i];
        }
        delete[] vectorDinamico.arrayChar;
        vectorDinamico.arrayChar = arrayAuxiliar;
        vectorDinamico.capacidad *= 2;
    }
    vectorDinamico.arrayChar[vectorDinamico.nCaracteres] = caracter;
    vectorDinamico.nCaracteres++;
}

void leer(istream& flujo, VectorDinamicoChar &vectorDinamico) {
    char caracter;
    //liberar(vectorDinamico);
    clear(vectorDinamico);
    while (flujo.get(caracter)) {
        aniadir(vectorDinamico, caracter);
    }
}

