/*
7. Una compañía aérea establece el precio del billete como sigue: en primer
lugar se fija una tarifa base de 150 euros, la misma para todos los destinos.
A continuación se suman 10 céntimos por cada kilómetro de distancia al destino.
Cree un programa que lea el número de kilómetros al destino y calcule el precio
final del billete.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables

  const int TARIFA_BASE = 150;
  const double PRECIO_KM = 0.1;  //Declaración de variables.
  double numero_km, precio_final;

  //Solicitud de datos al usuario.

  cout << "*************************************************" << endl << endl;
  cout << "Introduzca los kilómetros hasta su destino. ";
  cin >> numero_km;
  cout << endl << endl;

  //Cálculo del precio.

  precio_final = TARIFA_BASE + numero_km * PRECIO_KM;

  //Salida de datos.
  
  cout << "*************************************************" << endl << endl;
  cout << "El precio es " << precio_final << " euros " << endl << endl;


  return 0;
}
