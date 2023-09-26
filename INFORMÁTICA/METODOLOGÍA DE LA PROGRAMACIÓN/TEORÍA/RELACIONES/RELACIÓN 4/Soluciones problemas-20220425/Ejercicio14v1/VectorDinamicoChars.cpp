/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "VectorDinamicoChars.h"

using namespace std;

void inicializar(char * &arrayChars, int &nCaracteres) {
    arrayChars = nullptr;
    nCaracteres = 0;

}

void liberar(char * &arrayChars, int &nCaracteres) {
    delete[] arrayChars;
    inicializar(arrayChars, nCaracteres);
    //arrayChars = nullptr;
    //nCaracteres = 0;
}

void mostrar(ostream& flujo, char* array, int nCaracteres) {
    for (int i = 0; i < nCaracteres; i++) {
        flujo << array[i];
    }
}

void redimensionar(char * &array, int &nCaracteres, int aumento) {
    if (nCaracteres + aumento > 0) {
        char *v_ampliado = new char[nCaracteres + aumento];
        for (int i = 0; (i < nCaracteres) && (i < nCaracteres + aumento); i++)
            v_ampliado[i] = array[i];
        delete[] array;
        array = v_ampliado;
        nCaracteres = nCaracteres + aumento;
    }
}

void aniadir(char * &array, int &nCaracteres, char caracter) {
    redimensionar(array, nCaracteres, 1);
    array[nCaracteres - 1] = caracter;
}

void leer(istream& flujo, char* &array, int& nchar) {
    char caracter;
    liberar(array, nchar);
    while (flujo.get(caracter)) {
        aniadir(array, nchar, caracter);
    }
}