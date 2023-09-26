/*
20. En atletismo se expresa la rapidez de un atleta en términos de ritmo
(minutos y segundos por kilómetro) más que en unidades de velocidad
(kilómetros por hora).

Escribid dos programas para convertir entre estas dos medidas:

a) El primero leerá el ritmo (minutos y segundos, por separado) y mostrará
la velocidad (kilómetros por hora).
*/

#include <iostream>

using namespace std;

//1º programa.

int main() {


  //Declaración de variables.

  double ritmo, minutos, segundos, km_hora;

  //Solicitud de datos al usuario.

  cout << "*************************************************+" << endl << endl;
  cout << " Introduzca un número de minutos / km. ";
  cin >> minutos;

  cout << "*************************************************+" << endl << endl;
  cout << " Introduzca un número de segundos / km. ";
  cin >> segundos;

  /* Operaciones: el ritmo debe pasarse a segundos para trabajar con él. La
  velocidad es la inversa del ritmo, que debe pasarse de segundos a horas. */

  ritmo = segundos + minutos * 60;
  km_hora = (1 / ritmo) * 3600;

  //Salida de datos.

  cout << "*************************************************+"<< endl << endl;
  cout << "Un ritmo de " << ritmo << " segundos/km equivale a ";
  cout << km_hora << " km/h." << endl;

  return 0;

}
