/*
35. Los compiladores utilizan siempre el mismo número de bits para representar
un tipo de dato entero (este número puede variar de un compilador a otro).
Por ejemplo, 32 bits para un int. Pero, realmente, no se necesitan 32 bits
para representar el 6, por ejemplo, ya que bastarían 3 bits: 110

Se pide crear un programa que lea un entero positivo n, y calcule el mínimo
número de dígitos que se necesitan para su representación. Para simplificar
los cómputos, suponed que sólo queremos representar valores enteros positivos
(incluido el cero).

Consejo: se necesitará usar el logaritmo en base 2 y obtener la parte
entera de un real (se obtiene tras el truncamiento que se produce al asignar
un real a un entero).
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //Declaración de variables.

  int numero, numero_bits, log_numero;
  double numero_double;


  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un numero mayor o igual que 0. ";
  cin >> numero;
  cout << endl;

  /* Debo declarar esta variable para hacer nulo un posible log2 (0) y evitar
  errores matemáticos. */

  bool numero_distinto_0 = (numero != 0);

  /* Cálculos: La parte entera del log2 de un número es común a todos los
  números que se representan con el mismo número de bits. Sin embargo, se debe
  sumar un bit más. */


  // Paso a double para que opere bien el log2 y me quedo con su parte entera.

  numero_double = (double) numero;

  log_numero = log2 (numero_double);

  numero_bits = (numero_distinto_0 * log_numero) + 1;

  //Salida de datos.

  cout << "El numero minimo de bits para codificar " << numero << " es ";
  cout << numero_bits << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
