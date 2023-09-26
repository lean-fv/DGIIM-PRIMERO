/**
 * @file main.cpp
 * @brief 
 * Universidad de Granada - DGIM
 * Metodología de la Programación 
 * Examen de laboratorio 2021-222
 * Por favor, rellene las funciones que se indican.
 * No olvide pasar valgrind.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

/**
 * @brief Clase círculo
 */
class Circulo;

/**
 * @brief Clase punto bidimensional
 */
class Punto {
public:
    double _x, _y;
    /**
     * @brief Constructor que inicializa el punto dependiendo de la IP
     * del ordenador en la que se ejecute
     */
    Punto();
    /**
     * Método que calcula si un punto está dentro de un círculo o no
     * @param c El círculo a comprobar
     * @return @retval true si @a p está dentro del círculo, @retval false en otro caso
     */
    bool estaDentro(Circulo c) const;
    
    
};

class Circulo {
public:
    Punto _centro;
    double _radio;
    
};

bool Punto::estaDentro(Circulo c) const {
    return sqrt(pow(_x - c._centro._x, 2) + pow(_y - c._centro._y, 2)) <= c._radio;
}

Punto::Punto() {
    srand(time(NULL));
    _x = rand() % 20;
    _y = rand() % 20;
}


/**
@brief Imprime el contenido de un vector de Circulo
@param v 	Vector de Circulo
@param n	Número de elementos que contiene @a v
 */
void imprimirVector(Circulo *, int);

int main() {
    Punto P; /// Punto. Se inicializa automáticamente según la IP del ordenador
    
    string sCirculos = "data/datos1.dat", /// Nombre del fichero de entrada
            // Cambiar XXX por su Apellido_Nombre
            sDentro = "data/salida_FernandezVega_Leandro.in", /// Fichero de salida para los puntos que están dentro
            sFuera = "data/salida_FernandezVega_Leandro.out"; /// Fichero de salida para los puntos que están fuera

    /// Examen: Leer fichero de datos
    
    Circulo *circulos;
    int num_circulos;
    int x,y,z;
    
    int error=0;
    const int OPEN_ERROR=1;
    const int FORMAT_ERROR=2;
    const int DATA_ERROR=3;
    
    ifstream entrada;
    
    entrada.open(sCirculos);
    
    if (entrada){
        entrada>>num_circulos;
        
        if (num_circulos>0){
            circulos= new Circulo [num_circulos];
            for (int i=0; i<num_circulos; i++){
                
                entrada>>x>>y>>z;
                circulos[i]._centro._x=x;
                circulos[i]._centro._y=y;
                circulos[i]._radio=z;
            }
            if (!entrada) error=DATA_ERROR;
            
        }else error=FORMAT_ERROR;
        
        entrada.close();
    } else error=OPEN_ERROR;
    
    switch (error){
    
        case (OPEN_ERROR):
            cout <<"Error de apertura";
            std::exit(OPEN_ERROR);
            break;
            
        case (FORMAT_ERROR):
            cout <<"Error de formato";
            std::exit(FORMAT_ERROR);
            break;
        
        case (DATA_ERROR):
            cout <<"Error en el numero de datos";
            std::exit(DATA_ERROR);
            break;
    
    }
    
    /// Examen: Imprimir los datos leídos
    
    imprimirVector(circulos,num_circulos);

    /// Examen: Calcular resultado
    
    Circulo* circ_dentro;
    int n_dentro=0;
    Circulo* circ_fuera;
    int n_fuera=0;
    Punto punto_random;
    
    for (int i=0; i<num_circulos; i++){
        if (punto_random.estaDentro(circulos[i])) n_dentro++;
        else n_fuera++;
    }
    
    //cout<< endl <<endl<<num_circulos <<" " << n_dentro<<" "<<n_fuera<<endl<<endl;
    
    
    circ_dentro= new Circulo[n_dentro];
    circ_fuera=new Circulo [n_fuera];
    n_dentro=0;
    n_fuera=0;
    
    for (int i=0; i<num_circulos; i++){
        if (punto_random.estaDentro(circulos[i])){
            circ_dentro[n_dentro]._centro._x= circulos[i]._centro._x;
            circ_dentro[n_dentro]._centro._y= circulos[i]._centro._y;
            circ_dentro[n_dentro]._radio= circulos[i]._radio;
            n_dentro++;
        }
        else {
            circ_fuera[n_fuera]._centro._x= circulos[i]._centro._x;
            circ_fuera[n_fuera]._centro._y= circulos[i]._centro._y;
            circ_fuera[n_fuera]._radio= circulos[i]._radio;
            n_fuera++;
        }
    }
    
    /// Examen: Mostrar resultado
    cout <<endl <<endl<< "Circulos Dentro:" <<endl;
    imprimirVector(circ_dentro,n_dentro);
    cout <<endl <<endl<< "Circulos Fuera:" <<endl;
    imprimirVector(circ_fuera,n_fuera);

    
    /// Examen: Guardar resultado en disco
    
    ofstream salida_dentro;
    
    salida_dentro.open(sDentro);
    
    if (salida_dentro){
        salida_dentro<<n_dentro<<"\n";
        for (int i=0; i<n_dentro; i++) 
            salida_dentro<<circ_dentro[i]._centro._x<<" "<<circ_dentro[i]._centro._y<<" "<<circ_dentro[i]._radio<<"\n";
    }
    
    else error=OPEN_ERROR;
    

    ofstream salida_fuera;
    
    salida_fuera.open(sFuera);
    
    if (salida_fuera){
        salida_fuera<<n_fuera<<"\n";
        for (int i=0; i<n_fuera; i++) 
            salida_fuera<<circ_fuera[i]._centro._x<<" "<<circ_fuera[i]._centro._y<<" "<<circ_fuera[i]._radio<<"\n";
    }
    
    else error=OPEN_ERROR;
    
    if (error==OPEN_ERROR) std::exit(OPEN_ERROR);
    
    /// Examen: Terminación del programa
    
    delete []circulos;
    circulos=nullptr;
    delete []circ_dentro;
    circ_dentro=nullptr;
    delete []circ_fuera;
    circ_fuera=nullptr;
     
    return 0;
}

void imprimirVector(Circulo* v_circulos, int n){
    
    for (int i=0; i<n; i++){
        cout << v_circulos[i]._centro._x << " " << v_circulos[i]._centro._y <<" "<< v_circulos[i]._radio << endl;
    }
}
