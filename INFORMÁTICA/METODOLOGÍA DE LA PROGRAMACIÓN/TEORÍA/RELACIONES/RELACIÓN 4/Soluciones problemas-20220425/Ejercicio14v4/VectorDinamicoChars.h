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

class VectorDinamicoChar {
    char* arrayChar; // array dinámico de char
    int nCaracteres; // no de caracteres actualmente en el array
    int capacidad; // capacidad del array
    void inicializar();


public:
    VectorDinamicoChar();
    void liberar();
    void clear();
    void mostrar(std::ostream& flujo) const;
    void aniadir(char caracter);
    void leer(std::istream& flujo);
    
};





#endif /* VECTORDINAMICOCHARS_H */

