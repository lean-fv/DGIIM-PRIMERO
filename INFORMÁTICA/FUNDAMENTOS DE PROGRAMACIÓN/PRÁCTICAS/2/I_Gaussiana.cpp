/*

24. La función gaussiana es muy importante en Estadística.
Es una función real de variable real en la que el parámetro µ se conoce como
esperanza o media y σ como desviación típica (mean y standard deviation
en inglés, respectivamente).

Realizar un programa que lea los coeficientes reales µ y σ de una función
gaussiana.

A continuación el programa leerá un valor de abscisa x y se imprimirá
el valor que toma la función en x.

Para realizar las operaciones indicadas, debe utilizar las siguientes funciones
(disponibles en cmath):

• Para elevar el número e a un valor cualquiera, use la función exp.
Por ejemplo, para calcular e elevado a 8 debería usar la expresión exp(8)

• Para calcular la raíz cuadrada, use sqrt. Por ejemplo, para calcular √
8 debería usar la expresión sqrt(8).

• Para elevar un número a otro, utilice la función pow en la siguiente forma:
pow(base, exponente). Por ejemplo, para calcular 2 elevado a 10
debería usar la expresión pow(2,10).

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  //Declaración de variables.

  double gaussiana, media, desviacion_tipica, valor_x;
  const double PI = 3.141592;

  //Solicitud de datos al usuario.

  cout << "**************************************************" << endl << endl;
  cout << "Introduzca un valor para la variable media. ";
  cin >> media;
  cout << endl;

  cout << "**************************************************" << endl << endl;
  cout << "Introduzca un valor para la variable desviacion típica. ";
  cin >> desviacion_tipica;
  cout << endl;

  cout << "**************************************************" << endl << endl;
  cout << "Introduzca un valor para la variable x. ";
  cin >> valor_x;
  cout << endl;

  //Operaciones.

  gaussiana = (1/(desviacion_tipica * sqrt (2 * PI)))
              * exp (- 0.5 * pow ((valor_x - media) / desviacion_tipica, 2));

  //Salida de datos.

  cout << "**************************************************" << endl << endl;
  cout << "La Gaussiana vale " << gaussiana << endl << endl;







  return 0;
}
