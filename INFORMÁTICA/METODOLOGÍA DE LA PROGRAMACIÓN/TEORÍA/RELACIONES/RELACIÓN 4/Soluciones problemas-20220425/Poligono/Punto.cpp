/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.cpp
 * Author: Andrés Cano Utrera <Universidad de Granada>
 * 
 * Created on 30 de marzo de 2020, 13:07
 */

#include <cmath>

#include "Punto.h"

double Punto::distancia(const Punto &punto) const {
    return sqrt((this->x - punto.x)*(this->x - punto.x)+
            (this->y - punto.y)*(this->y - punto.y));
}

Punto Punto::puntoMedio(const Punto &punto) const {
    Punto pMedio;
    pMedio.setXY((x + punto.x) / 2, (y + punto.y) / 2);
    return pMedio;
}

void Punto::mostrar(std::ostream& flujo) const {
    flujo << x << " " << y;
}

void Punto::leer(std::istream& flujo) {
    flujo >> x;
    flujo >> y;
}
