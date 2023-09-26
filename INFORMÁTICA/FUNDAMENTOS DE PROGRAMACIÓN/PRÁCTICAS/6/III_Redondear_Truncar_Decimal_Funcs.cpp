/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

13. En cmath está definida la función round que permite redondear un real al
entero más próximo. Por ejemplo: round(3.6) devuelve 4, round(3.5) devuelve 4,
round(3.1) devuelve 3 y round(3.49) devuelve 3.

Nuestro interés es hacer algo similar pero para permitir el redondeo de la
parte decimal, especificando el número de cifras decimales que nos interese.

Por ejemplo:
• El resultado de redondear 3.49 a la primera cifra decimal es 3.5
• El resultado de redondear 3.49 a la segunda cifra decimal es 3.49
• El resultado de redondear 3.496 a la segunda cifra decimal es 3.5

Defina la función Redondea para calcular un número real aproximado a un número
de cifras decimales dado.

En el ejercicio 36 se pedía truncar la parte decimal de un número real usando
un número dado de cifras decimales. Por ejemplo:
• El resultado de truncar 3.49 a una cifra decimal es 3.4
• El resultado de truncar 3.496 a la segunda cifra decimal es 3.49
• El resultado de truncar 3.496 sin decimales es 3 (3.0)

Defina la función Trunca para truncar un número real usando un número de cifras
decimales dado.

En la implementación de estas funciones, necesitará calcular potencias enteras
(potencias de 10 en este caso). Para ello, use la función Potencia del
ejercicio 2.

ENTRADA: un numero, a cuantos decimales redondearse y truncarse.
SALIDA: el numero redondeado y truncado.

*/

#include <iostream>
#include <cmath>

using namespace std;

int Potencia10 (int decimales){

    int numero_decimales;
    numero_decimales = pow (10, decimales);

    return numero_decimales;
}

/* El proceso consiste en desplazar la coma tantos lugares como decimales
quiere truncar el usuario, truncar ese valor, y devolver la coma. */

double Truncar (double dato, int numero_decimales){

    double a_truncar;
    a_truncar = (trunc (dato * (Potencia10 (numero_decimales))))
                / (Potencia10 (numero_decimales));

    return a_truncar;
}

//El proceso es analogo al truncamiento.
double Redondear (double dato, int numero_decimales){

    double a_redondear;
    a_redondear = (round (dato * (Potencia10 (numero_decimales))))
                / (Potencia10 (numero_decimales));

    return a_redondear;
}

int main() {

  //Declaración de variables.

  double numero, numero_truncado, numero_redondeado;
  int truncamiento, redondeo;

  //Solicitud de datos al usuario.

  cout << "***********************************************" << endl << endl;

  cout << "Introduzca un numero. ";
  cin >> numero;
  cout << endl << endl;

  do{
      cout << "Introduzca el numero de decimales que quiere dejar, positivo. ";
      cin >> truncamiento;
  } while (truncamiento < 0);
  cout << endl;

  do{
      cout << "Introduzca los decimales a los que quiere aproximar, positivo. ";
      cin >> redondeo;
  } while (redondeo < 0);

  cout << endl;

  //Calculos.
  numero_truncado = Truncar (numero, truncamiento);
  numero_redondeado = Redondear (numero, redondeo);


  //Salida de datos.

  cout << "Su numero truncado es " << numero_truncado << endl;
  cout << "Su numero redondeado es " << numero_redondeado << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
