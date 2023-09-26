/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz2D_1.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 29 de marzo de 2020, 14:13
 */

#include <cassert>
#include <iostream>
#include "Matriz2D_1.h"

//Constructores y destructor.
Matriz2D_1::Matriz2D_1(){reservar(0,0);}
Matriz2D_1::Matriz2D_1(int nf,int nc){reservar(nf,nc);}
Matriz2D_1::Matriz2D_1(const Matriz2D_1& matriz_2d){copiar(matriz_2d);}
Matriz2D_1::~Matriz2D_1(){liberar();}



//Setters y Getters.
int Matriz2D_1::getNumeroFilas()const{return nfilas;}
int Matriz2D_1::getNumeroColumnas()const{return ncols;}
int& Matriz2D_1::get(int fila, int columna)const{return matriz[fila][columna];}
void Matriz2D_1::set(int fila, int columna, int dato){matriz[fila][columna]=dato;}


//Gestion de memoria.
void Matriz2D_1::reservar(int nf, int nc){
    nfilas=nf;
    ncols=nc;
    if (nfilas==0 || ncols==0) matriz=nullptr;
    else{
        matriz = new int* [nfilas];
        for (int f=0; f<nfilas; f++)
            matriz[f]= new int [ncols];
    }
}
void Matriz2D_1::liberar(){

    if (matriz!=nullptr){
        for (int f=0; f<nfilas;f++)
            delete[] matriz[f];
            
        delete []matriz;
    }
    
    matriz=nullptr;
    nfilas=0;
    ncols=0;
}

//Operadores.

Matriz2D_1& Matriz2D_1:: operator=(const Matriz2D_1& otra){

    if (this != &otra){
        liberar();
        reservar(otra.nfilas,otra.ncols);
        copiar(otra);
    }
    return *this;
}

Matriz2D_1& Matriz2D_1:: operator=(const int c){
    
    int nf=getNumeroFilas();
    int nc=getNumeroColumnas();
    
    for (int i=0; i<nf; i++)
        for (int j=0; j<nc;j++)
            set(i,j,c);
    
    return *this;
}


int& Matriz2D_1:: operator()(const int f, const int c) const{
    
    return(get(f,c));
}
int& Matriz2D_1:: operator()(const int f, const int c) {
    
    return(get(f,c));

}

Matriz2D_1 Matriz2D_1:: operator+(void){return *this;}

Matriz2D_1 Matriz2D_1:: operator-(void){
    
    int filas=getNumeroFilas();
    int columnas=getNumeroColumnas();
    Matriz2D_1 aux(filas,columnas);
    
    for (int i=0; i<nfilas; i++)
        for (int j=0; j<ncols; j++)
            aux.set(filas,columnas,get(i,j));
    return aux;
}

bool Matriz2D_1:: operator==(const Matriz2D_1& otra){
    
    int iguales=true;
    int filas=getNumeroFilas();
    int columnas=getNumeroColumnas();
    
    if (filas==otra.nfilas && columnas==otra.ncols)
    
        for (int i=0; i<filas;i++)
            for (int j=0; j<columnas;j++)
                if (get(i,j)!=otra.get(i,j)) iguales=false;
    
    else iguales=false;
    
    return iguales;
}
bool Matriz2D_1:: operator!=(const Matriz2D_1& otra){
    
    return !(*this==otra);
}


//Flujos.

void Matriz2D_1::imprimir(std::ostream& flujo) const{
    flujo << "Filas: " << nfilas << std::endl << "Columnas:" << ncols 
          << std::endl << std::endl;
    
    for (int i=0; i<nfilas;i++)
        for(int j=0; i<ncols;j++)
            flujo << matriz[i][j] << " ";
    
    flujo <<std::endl;
}

void Matriz2D_1::leer(std::istream& flujo){
    
    liberar();
    flujo>>nfilas;
    flujo>>ncols;
    reservar(nfilas,ncols);

    
    for (int i=0; i<nfilas; i++)
        for (int j=0; j<ncols; j++)
            flujo>>matriz[i][j];
}

//Otros
void Matriz2D_1::copiar (const Matriz2D_1& matriz_2d){
    
    liberar();
    reservar(matriz_2d.nfilas,matriz_2d.ncols);
    
    for (int i=0; i<nfilas; i++)
            for (int j=0; j<ncols; j++)
                matriz[i][j]=matriz_2d.matriz[i][j];
}

