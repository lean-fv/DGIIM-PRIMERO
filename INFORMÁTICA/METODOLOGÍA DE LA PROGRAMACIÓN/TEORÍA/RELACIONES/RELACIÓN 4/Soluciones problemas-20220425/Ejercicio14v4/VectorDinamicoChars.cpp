/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "VectorDinamicoChars.h"

using namespace std;


VectorDinamicoChar::VectorDinamicoChar(){
    inicializar();
}

void VectorDinamicoChar::inicializar(){
    arrayChar = new char[10];
    nCaracteres = 0;
    capacidad = 10; 
}


void VectorDinamicoChar::liberar() {
    delete[] arrayChar;
    arrayChar = nullptr;
    nCaracteres = 0;
    capacidad = 0;
}

void VectorDinamicoChar::clear() {
    liberar();
    inicializar();
}

void VectorDinamicoChar::mostrar(ostream& flujo) const {
    for (int i = 0; i < nCaracteres; i++) {
        flujo << arrayChar[i];
    }
}

/*void redimensionar(VectorDinamicoCharChar &vectorDinamico, int aumento) {
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

void VectorDinamicoChar::aniadir(char caracter) {
    //redimensionar(vectorDinamico, 1);
    if(nCaracteres == capacidad){
        char *arrayAuxiliar;
        arrayAuxiliar = new char[capacidad*2];
        for(int i=0; i<capacidad; i++){
            arrayAuxiliar[i] = arrayChar[i];
        }
        delete[] arrayChar;
        arrayChar = arrayAuxiliar;
        capacidad *=2;
    }
    arrayChar[nCaracteres] = caracter;
    nCaracteres++;
}

void VectorDinamicoChar::leer(istream& flujo) {
    char caracter;
    clear();
    while (flujo.get(caracter)) {
        aniadir(caracter);
    }
}