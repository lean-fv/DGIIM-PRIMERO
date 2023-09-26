/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Poligono.h
 * Author: Andrés Cano Utrera <Universidad de Granada>
 *
 * Created on 30 de marzo de 2020, 13:09
 */

#ifndef POLIGONO_H
#define POLIGONO_H

#include "Punto.h"

class Poligono {
    int nVertices; // Número de puntos en el array dinámico
    Punto *vertices; // Array dinámico de objetos Punto
    void inicializar();
public:
    Poligono();
    Poligono(int n);
    void liberar();
    int getNumeroVertices() const;
    Punto getVertice(int index) const;
    void addVertice(const Punto& v);
    double getPerimetro() const;
    Punto getPuntoInterior() const;
    double getArea() const;
    void mostrar(std::ostream& flujo) const;
    void leer(std::istream& flujo);
};

double areaTriangulo(const Punto& pto1, const Punto& pto2, const Punto& pto3);

#endif /* POLIGONO_H */

