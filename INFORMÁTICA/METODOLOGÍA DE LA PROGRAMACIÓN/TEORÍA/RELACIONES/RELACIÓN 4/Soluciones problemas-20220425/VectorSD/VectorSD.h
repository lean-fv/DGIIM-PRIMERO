/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorSD.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 14 de abril de 2020, 12:33
 */

#ifndef VECTORSD_H
#define VECTORSD_H

#include <iostream>

class VectorSD {
public:
    VectorSD();
    VectorSD(int n);
    int getDato(int pos) const;
    int nElementos() const;
    void aniadir(int dato);
    void copia(const VectorSD &vector);
    void liberar();
    void mostrar(std::ostream& flujo) const;
    void leer(std::istream& flujo);
private:
    int *info; // array dinámico de int
    int util; // no de enteros actualmente en el array
    int capacidad; // capacidad del array

    void reservar(int n);

};

#endif /* VECTORSD_H */

