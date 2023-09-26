/*

20. En atletismo se expresa la rapidez de un atleta en términos de ritmo
(minutos y segundos por kilómetro) más que en unidades de velocidad
(kilómetros por hora).

Escribid dos programas para convertir entre estas dos medidas:

b) El segundo leerá la velocidad (kilómetros por hora) y mostrará el ritmo
(minutos y segundos).

*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  double km_hora, ritmo;
  int minutos, segundos;

  //Solicitud de datos al usuario.

  cout << "*************************************************+" << endl << endl;
  cout << " Introduzca una velocidad en km/h. ";
  cin >> km_hora;

  /* Operaciones: el ritmo es la inversa de la velocidad, y debemos obtener
  cuantos minutos y segundos por kilómetro es. Para los minutos, basta con
  dividir un ritmo en segundos entre 60. Para los segundos, restamos al total
  de segundos del ritmo los de los minutos (minutos * 60). */


  ritmo = (1 / km_hora) * 3600;
  minutos = ritmo / 60;
  segundos = ritmo - minutos * 60;

  //Salida de datos.

  cout << "*************************************************+"<< endl << endl;
  cout << "Una velocidad de " << km_hora << " km/h equivale a ";
  cout << minutos << " min y " << segundos << " segundos /km." << endl;


  return 0;
}
