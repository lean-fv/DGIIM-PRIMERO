/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.h
 * Author: Andrés Cano Utrera <Universidad de Granada>
 *
 * Created on 30 de marzo de 2020, 13:07
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto {
    double x;
    double y;
public:

    Punto() {
        x = 0;
        y = 0;
    };

    Punto(int x, int y) {
        this->x = x;
        this->y = y;
    };

    double getX() const {
        return x;
    };

    double getY() const {
        return y;
    };

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    };

    double distancia(const Punto &punto) const;
    Punto puntoMedio(const Punto &punto) const;
    void mostrar(std::ostream& flujo) const;
    void leer(std::istream& flujo);
};

#endif /* PUNTO_H */

