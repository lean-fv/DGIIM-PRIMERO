/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II


36. Se quiere construir un programa que lea un número real r y un número
entero n y trunque r a tantas cifras decimales como indique n. El resultado
debe guardarse en una variable diferente. La única función que puede usar
de cmath es pow.

Por ejemplo, si r vale 1.2349 y n vale 2 el resultado será 1.23,
si r vale 1.237 y n vale 2 el resultado será 1.23,
si r vale 1.237 y n vale 1 el resultado será 1.2
y si  r vale 1.237 y n vale 0 el resultado será 1.

ENTRADA: numero con o sin decimales.
SALIDA: numero con el numero de decimales que se desee.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //Declaración de variables.

  double numero, numero_truncado;
  int truncar, desplazamiento_coma;

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca un numero. ";
  cin >> numero;
  cout << endl << endl;

  cout << "***********************************************" << endl << endl;
  cout << "Introduzca el numero de decimales que quiere dejar. ";
  cin >> truncar;
  cout << endl << endl;

  bool truncar_correcto = (truncar >= 0);   //Bandera


  /*
  Operaciones: consisten en desplazar la coma tantas decimales como quiera
  dejar el usuario, truncar ese número completamente y devolver la coma a
  su lugar inicial.
 */


 if (truncar_correcto){

   desplazamiento_coma = pow (10 , truncar);
   numero_truncado = (trunc (numero * desplazamiento_coma))
   / desplazamiento_coma;

 }

  //Salida de datos.

  cout << "***********************************************" << endl << endl;

  if (truncar_correcto){

    cout << "Su numero truncado es " << numero_truncado << endl << endl;

  }

  else {

    cout << "No ha introducido bien los datos." << endl << endl;

  }

  cout << "***********************************************" << endl << endl;

  return 0;
}
