/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   VectorDinamicoChars.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 29 de marzo de 2022, 17:10
 */

#ifndef VECTORDINAMICOCHARS_H
#define VECTORDINAMICOCHARS_H

#include <iostream>

struct VectorDinamicoChar {
    char* arrayChar; // array dinámico de char
    int nCaracteres; // no de caracteres actualmente en el array
};

void inicializar(VectorDinamicoChar &vectorDinamico);
void liberar(VectorDinamicoChar &vectorDinamico);
void mostrar(std::ostream& flujo, const VectorDinamicoChar &vectorDinamico);
void redimensionar(VectorDinamicoChar &vectorDinamico, int aumento);
void aniadir(VectorDinamicoChar &vectorDinamico, char caracter);
void leer(std::istream& flujo, VectorDinamicoChar &vectorDinamico);



#endif /* VECTORDINAMICOCHARS_H */

