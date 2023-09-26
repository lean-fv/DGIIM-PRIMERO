/*

18. Leed desde teclado tres variables correspondientes a un número de horas,
minutos y segundos, respectivamente.

Diseñar un algoritmo que calcule las horas, minutos y segundos dentro de su
rango correspondiente. Por ejemplo, dadas 10 horas, 119 minutos y 280 segundos,
debería dar como resultado 12 horas, 3 minutos y 40 segundos.

En el caso de que nos salgan más de 24 horas, daremos también los días
correspondientes (pero ya no pasamos a ver los meses, años, etc)
Como consejo, utilizad los operadores / (representa la división entera cuando
los dos argumentos son enteros) y % (representa el resto de la división
entera).

*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  int dias, horas, minutos, segundos, total_segundos;

  //Solicitud de datos al usuario.

  cout << "*************************************************" << endl << endl;

  cout << "Introduzca un número de horas. " << endl;
  cin >> horas;
  cout << "*************************************************" << endl << endl;

  cout << "Introduzca un número de minutos. " << endl;
  cin >> minutos;
  cout << "*************************************************" << endl << endl;

  cout << "Introduzca un número de segundos. " << endl;
  cin >> segundos;
  cout << "*************************************************" << endl << endl;

  cout << horas << " horas, " << minutos << " minutos y ";
  cout << segundos << " segundos equivale a ";

  /* Operaciones: calculo cada unidad de tiempo sumando al resto la cantidad
  de días, horas, minutos o segundos que hay en un escalón inferior de tiempo.
  Hay que tener en cuenta que para los días no hay resto y para los segundos no
  hay escalón inferior. */


  dias = horas / 24;
  horas = horas % 24 + minutos / 60;
  minutos = minutos % 60 + segundos / 60;
  segundos = segundos % 60;

  //Salida de datos.

  cout << dias << " días, " << horas << " horas, " << minutos << " minutos y ";
  cout << segundos << " segundos. " << endl << endl;



  return 0;
}
