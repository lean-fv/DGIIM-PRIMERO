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


void inicializar(char * &arrayChars, int &nCaracteres);
void liberar(char * &arrayChars, int &nCaracteres);
void mostrar(std::ostream& flujo, char* array, int nCaracteres);
void redimensionar(char * &array, int &nCaracteres, int aumento);
void aniadir(char * &array, int &nCaracteres, char caracter);
void leer(std::istream& flujo, char* &array, int& nchar);



#endif /* VECTORDINAMICOCHARS_H */

