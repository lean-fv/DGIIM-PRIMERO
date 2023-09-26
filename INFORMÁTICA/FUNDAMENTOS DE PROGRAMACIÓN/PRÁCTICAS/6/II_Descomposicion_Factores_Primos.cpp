/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

47. Escribir un programa que lea un número entero positivo y muestre su
descomposición en factores primos.

Hágalo de manera que se calcule y muestre el resultado de dos maneras:

a) La primera (más sencilla) consiste en enumerar todos los primos de la
descomposición (en el caso de que un primo intervenga más de una vez se
mostrará tantas veces como sea preciso). Por ejemplo:
360 = 2 * 2 * 2 * 3 * 3 * 5
121 = 11 * 11
11 = 11

b) La segunda consiste en expresar el resultado como el producto de potencias
(en el caso de que un primo intervenga más de una vez se mostrará una potencia
cuya base sea el valor del primo y el exponente será el número de veces que
se repite). Evite potencias triviales (de exponente 1) escribiendo, en ese
caso, únicamente la base (el valor del primo). Por ejemplo:
360 = 2^3 * 3^2 * 5
121 = 11^2
11 = 11

ENTRADA: un numero entero positivo.
SALIDA: su descomposición en factores primos.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {

  //Declaraciones

  string numero_string1, numero_string2;
  int numero, numero_inicial, factor;

  const char IGUAL = '=', PRODUCTO = '*', EXPONENTE = '^';



  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do{
    cout << "Introduzca un numero entero positivo. ";
    cin >> numero;
  } while (numero < 0);

  cout << endl;

  //Calculos.
  numero_string1 = to_string (numero) + IGUAL;
  numero_string2 = numero_string1;
  int exponente = 0;

  for (factor = 2; factor <= numero; factor++){

    /* Mientras el numero sea divisor se va dividiendo el numero entre él
    hasta que el resto sea distinto de 0. */
    while (numero % factor == 0){
      numero = numero / factor;
      numero_string1 = numero_string1 + to_string (factor) + PRODUCTO;
      exponente++; //Cuando se encuentra un divisor aumenta el exponente.

    }
    //Si el exponente vale 1 dejamos solo la base.
    if (exponente == 1) {
      numero_string2 = numero_string2 + to_string (factor) + PRODUCTO;

    }
    /* Si no se encuentra divisor, el exponente vale 0, por lo que se mostraria
    por pantalla la base elevada a exponente 0. Debo filtrar estos casos para
    que se muestren solo los divisores. */

    if (exponente != 0 && exponente != 1) {
      numero_string2 = numero_string2 + to_string (factor) + EXPONENTE
                       + to_string (exponente) + PRODUCTO;

    }

    exponente = 0; //Al tener que cambiar de divisor el exponente vuelve a 0.

  }

  numero_string1.pop_back();
  numero_string2.pop_back();

  //Salida de datos.

  cout <<  numero_string1 << endl;
  cout <<  numero_string2 << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
