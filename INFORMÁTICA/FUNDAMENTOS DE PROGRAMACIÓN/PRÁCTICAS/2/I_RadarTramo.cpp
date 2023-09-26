/*
9. Un radar de tramo está organizado en tres sectores: 1) el primero,
de 5.3 Km, tiene la velocidad limitada a 80 Km/h, 2) el segundo, de 8.1 Km,
tiene la velocidad limitada a 100 Km/h, y 3) el tercero, de 6.4 Km,
tiene la velocidad limitada a 80 Km/h.
El tramo tiene dos pórticos de control, al inicio y al final.

Escribir un programa que calcule y muestre el tiempo umbral de sanción, o sea,
el tiempo mínimo en segundos que puede emplear un vehículo en recorrer el tramo
completo sin ser sancionado.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  const double TRAMO_1 = 5.3, TRAMO_2 = 8.1, TRAMO_3 = 6.4;
  const int VELOCIDAD_1 = 80, VELOCIDAD_2 = 100, VELOCIDAD_3 = 80;
  double tiempo_1, tiempo_2, tiempo_3, tiempo_total;

  /* Cálculos: el tiempo se calcula como espacio / velocidad, y se pasa a la
  unidad deseada. */

  tiempo_1 = TRAMO_1 / VELOCIDAD_1 * 60;
  cout << "*************************************************" << endl << endl;
  cout << " El tiempo umbral del tramo 1 es de " << tiempo_1 << " minutos.";
  cout << endl << endl;

  tiempo_2 = TRAMO_2 / VELOCIDAD_2 * 60;
  cout << "*************************************************" << endl << endl;
  cout << " El tiempo umbral del tramo 2 es de " << tiempo_2 << " minutos.";
  cout << endl << endl;

  tiempo_3 = TRAMO_3 / VELOCIDAD_3 * 60;
  cout << "*************************************************" << endl << endl;
  cout << " El tiempo umbral del tramo 3 es de " << tiempo_3 << " minutos.";
  cout << endl << endl;

  tiempo_total = tiempo_1 + tiempo_2 + tiempo_3;

  //Salida de datos.

  cout << "*************************************************" << endl << endl;
  cout << " El tiempo umbral total es de " << tiempo_total << " minutos = ";
  cout << tiempo_total * 60 << " segundos "<< endl << endl;


  return 0;
}
