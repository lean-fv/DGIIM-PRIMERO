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

private:
    int** matriz;
    int nfilas;
    int ncols;
    void reservar(int nf, int nc);
    void copiar(const Matriz2D_1 &matriz_2d);
    
public:
    Matriz2D_1();
    Matriz2D_1(int nf, int nc);
    Matriz2D_1(int nf,int nc,const int c);
    Matriz2D_1(const Matriz2D_1& matriz_2d);
    ~Matriz2D_1();
    
    int getNumeroFilas() const;
    int getNumeroColumnas() const;
    int& get(int fila, int columna) const;
    void set(int fila, int columna, int dato);
    
    void liberar();
    
    Matriz2D_1& operator=(const Matriz2D_1& otra);
    Matriz2D_1& operator=(const int c);
    int& operator()(const int f, const int c) const;
    int& operator()(const int f, const int c);
    Matriz2D_1 operator+(void);
    Matriz2D_1 operator-(void);
    bool operator==(const Matriz2D_1& otra);
    bool operator!=(const Matriz2D_1& otra);
    //ostream& operator<<(ostream& flujo, const Matriz2D_1& m);

    
    void imprimir(std::ostream& flujo) const;
    void leer(std::istream& flujo);
    
    
    

};

#endif /* MATRIZ2D_1_H */

