/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

39. Escriba una función que compruebe si un dato string contiene la
representación binaria de un número entero positivo o cero.
Escriba una función que simplifique la representación binaria de un número
entero positivo o cero.

La representación binaria se representa en un dato  string. Se supone que es
una representación binaria correcta.

Escriba una función que calcule el valor decimal (int) de un valor binario.
El valor binario se suministra en un string del que se supone que contiene una
representación binaria correcta.
Estas funciones puede usarlas en un programa que tendrá la funcionalidad
descrita en el ejercicio 85 de la Relación de Problemas II: se pedirá un valor
binario (se leerá sobre un dato string), se verificará, se simplificará y
finalmente se calculará su valor decimal y se mostrará el resultado.

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

//Funcion de control de errores.
bool Datos_ok (string numero_binario){


      int longitud = numero_binario.length();
      int datos_ok = true;

      for (int posicion1 = 0; posicion1 < longitud; posicion1 ++){

          if((numero_binario.at (posicion1) != '0'
          && numero_binario.at(posicion1) != '1')
          || (stoi) (numero_binario) < 0){

              datos_ok = false;
          }
      }
      if (datos_ok) return true;
      else return false;
}

string Simplificar (string numero_binario){

    int longitud = numero_binario.length();
    int posicion = 0;

    while (posicion <= longitud - 1 && numero_binario.at (posicion) == '0'){

          posicion++;
      }

      /*Sustituimos el numero binario introducido por aquel formado a partir
      del primer termino distinto de 0. */
      string numero_binario_simplificado =
      numero_binario.substr (posicion, longitud - posicion);

    return numero_binario_simplificado;

}

  /* El proceso consiste en sumar todas las potencias de base dos elevadas a la
  posicion donde este cada 1, siendo la posicion de mas a la derecha la
  posicion 0. */
  int Bin_to_dec (string numero_binario){

      int longitud = numero_binario.length();
      int exponente = 0;
      int numero_decimal = 0;

      for (int posicion2 = longitud - 1 ; posicion2 >= 0; posicion2--){

          if (numero_binario.at (posicion2) == '1'){

              numero_decimal = numero_decimal + pow (2, exponente);
          }

          exponente++;

      }
      return numero_decimal;
  }

int main() {

  //Declaraciones

  string numero_binario;
  int numero_decimal;


  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do{
    cout << "Introduzca un numero binario. ";
    cin >> numero_binario;
  }while (!Datos_ok (numero_binario));

  //Calculos.

  numero_decimal = Bin_to_dec (Simplificar (numero_binario));


  //Salida de datos.
  cout << "El numero en decimal es " << numero_decimal << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
