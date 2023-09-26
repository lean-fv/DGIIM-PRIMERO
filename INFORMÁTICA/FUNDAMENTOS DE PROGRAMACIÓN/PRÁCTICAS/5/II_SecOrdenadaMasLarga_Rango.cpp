/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

42. Construya un programa que calcule cuándo se produjo la mayor secuencia de
días consecutivos con temperaturas crecientes. El programa leerá una secuencia
de reales representando temperaturas, hasta llegar al -1 y debe calcular la
subsecuencia de números ordenada, de menor a mayor, de mayor longitud. El
programa nos debe decir la posición donde comienza la subsecuencia y su
longitud.

Por ejemplo, ante la entrada siguiente:
17.2 17.3 16.2 16.4 17.1 19.2 18.9 -1

el programa nos debe indicar que la mayor subsecuencia empieza en la posición
3 (en el 16.2) y tiene longitud 4 (termina en 19.2).

Puede suponer que siempre se introducirá al menos un valor de temperatura.

43. Modifique el ejercicio 42 para que la lectura de datos finalice cuando se
introduce un valor fuera de un rango establecido entre los valores
MIN_TEMP_VALIDA y MAX_TEMP_VALIDA.

ENTRADA: secuencia de temperaturas.
SALIDA: posición donde comienza la subsecuencia y su longitud.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {

  //Declaraciones

  double temperatura;
  const double MIN_TEMP_VALIDA = - 10;
  const double MAX_TEMP_VALIDA = 40;
  const int TERMINADOR = -1;
  double max, min;
  int contador, longitud, pos_min, longitud_max;


  //Entrada de datos.

  cout << "***********************************************" << endl << endl;


  //Utilizo lectura anticipada con filtro.

  cout << "Introduzca una temperatura entre -10 y 40 grados, o -1 para "
       << "terminar. ";

  do { //Filtro
    cin >> temperatura;

    if (temperatura < MIN_TEMP_VALIDA || temperatura > MAX_TEMP_VALIDA) {

      cout << "Introduzca una temperatura correcta. ";
    }
  } while (temperatura < MIN_TEMP_VALIDA || temperatura > MAX_TEMP_VALIDA);


  //Operaciones.

  min = temperatura;
  longitud = 0;
  longitud_max = 0;
  pos_min = longitud_max;
  contador = 1;

  while (temperatura != TERMINADOR){

    if (temperatura > min){
      longitud ++;
    }

    else {
      min = temperatura;
      longitud_max = longitud;
      longitud = 1;

    }

    if (longitud > longitud_max){

      longitud_max = longitud;
      pos_min = contador - longitud_max;
    }

    cout << "Introduzca una temperatura entre -10 y 40 grados, o -1 para "
         << "terminar. ";

    do { //Filtro
      cin >> temperatura;

      if (temperatura < MIN_TEMP_VALIDA || temperatura > MAX_TEMP_VALIDA) {

        cout << "Introduzca una temperatura correcta. ";
      }
    } while (temperatura < MIN_TEMP_VALIDA || temperatura > MAX_TEMP_VALIDA);
    contador ++;

  }

  //Salida de datos.

  cout << "El intervalo mayor empieza en la posicion " << pos_min
       << " y tiene longitud " << longitud_max << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
