/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

76. Diremos que un número entero positivo es secuenciable si se puede generar
como suma de números consecutivos. Por ejemplo, 6 = 1 + 2 + 3, 15 = 7 + 8.
Esta descomposición no tiene por qué ser única.
Por ejemplo, 15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5.
Escribir un programa que lea un entero n y nos diga cuántas descomposiciones
posibles tiene. Por ejemplo:

15 -> 3 descomposiciones
94 -> 1 descomposición
108 -> 3 descomposiciones

Curiosidad: los únicos números con 0 descomposiciones son las potencias de 2.

ENTRADA: Un numero.
SALIDA: cuantas descomposiciones secuenciales tiene.

*/

#include <iostream>

using namespace std;

int main() {

  //Declaraciones
  int n;

  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do{ //Filtro
    cout << "Introduzca un numero entero positivo. ";
    cin >> n;
  }while (n < 0);

  cout << endl;

  //Calculos.
  int suma;
  int combinaciones=0;

  for (int i = 1; i <= n/2; i++){
    suma = i;
    for(int j = i + 1; j <= n/2 + 1; j++){
      suma = suma + j;

      if(suma == n){
        combinaciones++;
      }
    }
  }

  //Salida de datos.

  cout << n << " --> " << combinaciones << " combinaciones" << endl;
  cout << "***********************************************" << endl << endl;


  return 0;
}
