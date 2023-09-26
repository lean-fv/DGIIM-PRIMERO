/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS II

51. Ahora estamos interesados en obtener el área que cubre la función gaussiana
en un intervalo dado. Si consideramos el intervalo (−∞, x] el valor del área de
la región que queda bajo la curva de g(x) se calcula con la distribución
acumulada (cumulative distribution function) en el punto x, abreviado CDF(x).

Puede obtenerse un valor aproximado de CDF(x) como la suma de valores de g(x),
empezando por valores alejados de la media (y menores que ella).

Escribid un programa calcule CDF(x) para un valor de x dado.
El programa debe pedir los parámetros que definen una función gaussiana (µ y σ)
y el valor de la abscisa, x, para el que se va a calcular CDF(x).

Para el cálculo práctico de CDF(x) la integral se convierte en una suma, y se
requiere concretar cuántas sumas se van a realizar. Bastará con indicar:
a) un valor inicial para x (tómese µ − 3σ).
b) un “salto” entre dos valores consecutivos de x (use una constante)

ENTRADA: esperanza, desviacion tipica y variable x.
SALIDA: distribucion acumulada.

*/

#include <iostream>
#include <cmath>


using namespace std;

int main() {

  //Declaraciones

  double variable_x, media, desviacion_tipica, gaussiana, cdf;
  const double PI = 3.141592, SALTO = 0.001;



  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do {

    cout << "Introduzca un valor mayor que 0 para la desviacion_tipica. ";
    cin >> desviacion_tipica;
  } while (desviacion_tipica <= 0);

  cout << endl;
  cout << "Introduzca un valor para la media. ";
  cin >> media;

  cout << endl;
  cout << "Introduzca un valor para la variable x. ";
  cin >> variable_x;

  cout << endl;

  //Calculos.
  double x_inicial = media - 3 * desviacion_tipica;
  cdf = 0;


  for (x_inicial; x_inicial <= variable_x; x_inicial = x_inicial + SALTO){

    gaussiana = (1/(desviacion_tipica * sqrt (2 * PI)))
                * exp (- 0.5 * pow ((x_inicial - media)
                / desviacion_tipica, 2));

    cdf = cdf + gaussiana * SALTO;
  }




  //Salida de datos.

  cout << "La distribucion acumulada es de " << cdf << endl << endl;
  cout << "***********************************************" << endl << endl;



  return 0;
}
