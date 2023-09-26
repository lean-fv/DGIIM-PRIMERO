/*
7. Una compañía aérea establece el precio del billete como sigue: en primer
lugar se fija una tarifa base de 150 euros, la misma para todos los destinos.
A continuación se suman 10 céntimos por cada kilómetro de distancia al destino.
Cree un programa que lea el número de kilómetros al destino y calcule el precio
final del billete.

8. La compañía aérea del ejercicio 7 quiere aplicar una política de descuentos
al precio del billete. Amplíe el programa anterior para después de imprimir el
precio del billete pida un porcentaje de descuento (dato double) y muestre el
precio final después de aplicar el descuento indicado.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  const int TARIFA_BASE = 150;
  const double PRECIO_KM = 0.1;
  double numero_km, precio_final, descuento, precio_final_descuento;

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca los kilómetros hasta su destino. ";
  cin >> numero_km;
  cout << endl << endl;

  //Cálculo del precio.


  precio_final = TARIFA_BASE + numero_km * PRECIO_KM;

  //Salida de datos.

  cout << "***********************************************" << endl << endl;
  cout << "El precio es " << precio_final << " euros." << endl << endl;

  //Solicitud de datos al usuario (descuento).

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un descuento en porcentaje. ";
  cin >> descuento;
  cout << endl << endl;

  //Cálculo del precio con descuento.

  precio_final_descuento = precio_final - precio_final * (descuento / 100);

  //Salida de datos.

  cout << "***********************************************" << endl << endl;
  cout <<"El precio con descuento es " << precio_final_descuento << " euros.";
  cout << endl << endl;

  return 0;
}
