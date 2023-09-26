/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

85. Escribir un programa que muestre el valor decimal de un valor dado en el
sistema de numeración binario.

El programa pedirá el valor binario, que se leerá sobre un dato string, se
calculará su valor decimal que se guardará a un entero y se mostrará el
resultado.

Comprobar y controlar adecuadamente toda las situaciones de error.

ENTRADA: numero binario.
SALIDA: numero decimal.

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

  //Declaraciones

  string numero_binario;
  int longitud, numero_decimal;



  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  bool datos_ok;

  do{ //Filtro.

    cout << "Introduzca un numero binario. ";
    cin >> numero_binario;
    longitud = numero_binario.length();
    datos_ok = true;

    for (int posicion1 = 0; posicion1 < longitud; posicion1 ++){

      if((numero_binario.at (posicion1) != '0'
      && numero_binario.at(posicion1) != '1') || (stoi) (numero_binario) < 0){

        datos_ok = false;
      }
    }
  } while (!datos_ok);

  //Calculos.

  int exponente = 0;

  for (int posicion2 = longitud - 1 ; posicion2 >= 0; posicion2--){

    if (numero_binario.at (posicion2) == '1'){

      numero_decimal = numero_decimal + pow (2, exponente);
  }

    exponente++;

  }


  //Salida de datos.

  cout << "El numero en decimal es " << numero_decimal << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
