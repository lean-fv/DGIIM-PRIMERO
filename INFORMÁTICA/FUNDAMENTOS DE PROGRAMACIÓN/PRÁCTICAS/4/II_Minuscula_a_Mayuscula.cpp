/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

25. Diseñar un programa que lea un carácter (supondremos que el usuario
introduce una minúscula), lo pase a mayúscula y lo imprima en pantalla.

Hacedlo sin usar las funciones toupper ni tolower de la biblioteca cctype.

Para ello, debe considerarse la equivalencia en C++ entre los tipos enteros
y caracteres.

ENTRADA: caracter en minuscula.
SALIDA: caracter en mayuscula.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  char caracter;
  char caracter_mayuscula;

  const int CONVERSION_MAYUS = 'B' - 'b';
  const int EXTREMO_INTERVALO_1 = 'a';   //Corresponde a la 'a'.
  const int EXTREMO_INTERVALO_2 = 'z';  //Corresponde a la 'z'.

  //Entrada de datos.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un caracter en minuscula. ";
  cin >> caracter;
  cout << "***********************************************" << endl << endl;

  //Bandera.

  bool datos_correctos =
  (caracter >= EXTREMO_INTERVALO_1 && caracter <= EXTREMO_INTERVALO_2);

  /* Cálculos:

  Proceso de transformación de minúscula a mayúscula: sumo al
  carácter el valor correspondiente (que en este caso es - 32), ya que
  todos los caracteres tienen un valor en la tabla ASCII.

  */

  if (datos_correctos){

    caracter_mayuscula = caracter + CONVERSION_MAYUS;

  }


  //Salida de datos.

  if (datos_correctos){

    cout << "***********************************************" << endl << endl;
    cout << "El caracter " << caracter << " en mayuscula es ";
    cout << caracter_mayuscula << endl << endl;
    cout << "***********************************************" << endl << endl;

  }

  else {

    cout << "No ha introducido bien los datos. " << endl << endl;
    cout << "***********************************************" << endl << endl;

  }


  return 0;
}
