/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "VectorDinamicoChars.h"


using namespace std;

void VectorDinamicoChar::inicializar(){
    
    capacidad=10;
    arraychar=new char[capacidad];
    nCaracteres=0;
}

void VectorDinamicoChar::liberar(){
    
    delete[]arraychar;
    arraychar=nullptr;
    nCaracteres=0;
    capacidad=0;
    
}

void VectorDinamicoChar::clear(){
    liberar();
    inicializar();
}

void VectorDinamicoChar::mostrar(ostream& flujo){
    
    for (int i=0; i<nCaracteres;i++)
        flujo << arraychar[i];
}

/*void redimensionar(VectorDinamicoChar &vectorDinamico, int aumento){
    
    if (vectorDinamico.nCaracteres+aumento>0){
        char* ampliado= new char[vectorDinamico.nCaracteres+aumento];
        for (int i=0; (i<vectorDinamico.nCaracteres)&&(i<vectorDinamico.nCaracteres+aumento);i++){
            ampliado[i]=vectorDinamico.arraychar[i];
        }
        
        delete[]vectorDinamico.arraychar;
        vectorDinamico.arraychar=ampliado;
        vectorDinamico.nCaracteres+=aumento;
    }
}
*/
void VectorDinamicoChar::aniadir(char caracter){
    
    if (nCaracteres==capacidad){
        
        char* aux= new char[2*capacidad];
        for (int i=0; i<capacidad;i++){
            aux[i]=arraychar[i];
        }
        
        delete[]arraychar;
        arraychar=aux;
        capacidad*=2;
    }
        
    arraychar[nCaracteres]=caracter;
    nCaracteres++;
}

void VectorDinamicoChar::leer(istream& flujo){
    
    char caracter;
    clear();
    while (flujo.get(caracter)) aniadir(caracter);
}
