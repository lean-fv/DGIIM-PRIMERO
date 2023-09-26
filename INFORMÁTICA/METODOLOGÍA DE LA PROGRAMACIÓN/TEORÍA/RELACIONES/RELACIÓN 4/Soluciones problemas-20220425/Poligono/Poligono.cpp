/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Poligono.cpp
 * Author: Andrés Cano Utrera <Universidad de Granada>
 * 
 * Created on 30 de marzo de 2020, 13:09
 */

#include <cassert>
#include <cmath>

#include "Poligono.h"
#include "Punto.h"

Poligono::Poligono() {
    inicializar();
}

void Poligono::inicializar() {
    nVertices = 0;
    vertices = nullptr;
}

Poligono::Poligono(int n) {
    assert(n > 0);
    nVertices = n;
    vertices = new Punto[n];
}

void Poligono::liberar() {
    if (vertices != nullptr) {
        delete[] vertices;
        vertices = nullptr;
        nVertices = 0;
    }
}

int Poligono::getNumeroVertices() const {
    return nVertices;
}

Punto Poligono::getVertice(int index) const {
    assert(index >= 0 && index < nVertices);
    return vertices[index];
}

void Poligono::addVertice(const Punto& v) {
    Punto *nuevoArray = new Punto[nVertices + 1];
    for (int i = 0; i < nVertices; i++) {
        nuevoArray[i] = vertices[i];
    }
    delete[] vertices;
    vertices = nuevoArray;
    vertices[nVertices] = v;
    nVertices++;
}

double Poligono::getPerimetro() const {
    double perimetro = 0.0;
    for (int i = 0; i < nVertices; i++) {
        perimetro += vertices[i].distancia(vertices[(i + 1) % nVertices]);
    }
    return perimetro;
}

double areaTriangulo(const Punto& pto1, const Punto& pto2, const Punto& pto3) {
    double S1, S2, S3, T;

    S1 = pto1.distancia(pto2);
    S2 = pto2.distancia(pto3);
    S3 = pto3.distancia(pto1);
    T = (S1 + S2 + S3) / 2;
    return sqrt(T * (T - S1)*(T - S2)*(T - S3));
}

Punto Poligono::getPuntoInterior() const {
    assert(nVertices > 0);
    return vertices[0].puntoMedio(vertices[nVertices / 2]);
}

double Poligono::getArea() const {
    double area = 0.0;
    Punto pInterior = getPuntoInterior();
    for (int i = 0; i < nVertices; i++) {
        area += areaTriangulo(pInterior, vertices[i], vertices[(i + 1) % nVertices]);
    }
    return area;
}

void Poligono::mostrar(std::ostream& flujo) const {
    flujo << nVertices << std::endl;
    for (int i = 0; i < nVertices; i++) {
        vertices[i].mostrar(flujo);
        flujo << std::endl;
    }
}

void Poligono::leer(std::istream& flujo) {
    Punto punto;
    int n;
    
    liberar();
    inicializar();
    flujo >> n;
    for(int i=0; i<n; i++){
        punto.leer(flujo);
        addVertice(punto);
    }
}
