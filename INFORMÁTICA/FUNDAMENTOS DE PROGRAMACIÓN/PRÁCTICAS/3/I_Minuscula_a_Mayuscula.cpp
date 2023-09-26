/*
25. Diseñar un programa que lea un carácter (supondremos que el usuario
introduce una minúscula), lo pase a mayúscula y lo imprima en pantalla.

Hacedlo sin usar las funciones toupper ni tolower de la biblioteca cctype.

Para ello, debe considerarse la equivalencia en C++ entre los tipos enteros
y caracteres.
*/

#include <iostream>

using namespace std;

int main() {

  //Declaración de variables.

  char caracter;
  const int CONVERSION_MAYUS = - 32;

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un caracter en minuscula. ";
  cin >> caracter;
  cout << endl;

  /* Proceso de transformación de minúscula a mayúscula: sumo al
  carácter el valor correspondiente (que en este caso es - 32), ya que
  todos los caracteres tienen un valor en la tabla ASCII. */

  cout << "***********************************************" << endl << endl;
  cout << "El caracter " << caracter << " en mayuscula es ";
  caracter = caracter + CONVERSION_MAYUS;

  //Salida de datos.

  cout << caracter << endl << endl;
  cout << "***********************************************" << endl << endl;


  return 0;
}
