/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "VectorDinamicoChars.h"

using namespace std;

void inicializar(VectorDinamicoChar &vectorDinamico) {
    vectorDinamico.arrayChar = nullptr;
    vectorDinamico.nCaracteres = 0;
}

void liberar(VectorDinamicoChar &vectorDinamico) {
    delete[] vectorDinamico.arrayChar;
    inicializar(vectorDinamico);
    //arrayChars = nullptr;
    //nCaracteres = 0;
}

void mostrar(ostream& flujo, const VectorDinamicoChar &vectorDinamico) {
    for (int i = 0; i < vectorDinamico.nCaracteres; i++) {
        flujo << vectorDinamico.arrayChar[i];
    }
}

void redimensionar(VectorDinamicoChar &vectorDinamico, int aumento) {
    if (vectorDinamico.nCaracteres + aumento > 0) {
        char *v_ampliado = new char[vectorDinamico.nCaracteres + aumento];
        for (int i = 0; (i < vectorDinamico.nCaracteres) && 
                (i < vectorDinamico.nCaracteres + aumento); i++)
            v_ampliado[i] = vectorDinamico.arrayChar[i];
        delete[] vectorDinamico.arrayChar;
        vectorDinamico.arrayChar = v_ampliado;
        vectorDinamico.nCaracteres = vectorDinamico.nCaracteres + aumento;
    }
}

void aniadir(VectorDinamicoChar &vectorDinamico, char caracter) {
    redimensionar(vectorDinamico, 1);
    vectorDinamico.arrayChar[vectorDinamico.nCaracteres - 1] = caracter;
}

void leer(istream& flujo, VectorDinamicoChar &vectorDinamico) {
    char caracter;
    liberar(vectorDinamico);
    while (flujo.get(caracter)) {
        aniadir(vectorDinamico, caracter);
    }
}