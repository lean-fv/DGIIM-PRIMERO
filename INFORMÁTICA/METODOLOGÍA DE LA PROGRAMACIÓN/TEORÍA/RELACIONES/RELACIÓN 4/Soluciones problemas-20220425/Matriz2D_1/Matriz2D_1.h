/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz2D_1.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 29 de marzo de 2020, 14:13
 */

#ifndef MATRIZ2D_1_H
#define MATRIZ2D_1_H

class Matriz2D_1 {
    int** matriz;
    int nfilas;
    int ncols;
    void reservar(int nf, int nc);
public:
    Matriz2D_1();
    Matriz2D_1(int nf, int nc);
    int getNumeroFilas() const;
    int getNumeroColumnas() const;
    int get(int fila, int columna) const;
    void set(int fila, int columna, int dato);
    void liberar();
    void imprimir(std::ostream& flujo) const;
    void leer(std::istream& flujo);
    void copiar(const Matriz2D_1 &matriz);

};

#endif /* MATRIZ2D_1_H */

