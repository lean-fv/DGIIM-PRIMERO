/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS III

30. En estadística, la regla 68-95-99.7, conocida también como la regla
empírica es una manera rápida de recordar el porcentaje de la población que se
encuentra en un entorno centrado en la media (si los datos siguen una
distribución normal) y con un ancho de una, dos y tres desviaciones estándar
respectivamente. De otra manera: el 68.27 %, 95.45 % y el 99.73 % de la
población está dentro del entorno centrado en la media y con un ancho de una,
dos y tres desviaciones estándar respectivamente. En la figura 17 mostramos los
intervalos que contienen el 68.27 %, 95.45 % y el 99.73 % de la población para
una distribución gaussiana.

Escribir un programa que lea los parámetros de una distribución gaussiana y a
continuación muestre los valores de:

a) g(x) con la función escrita en el ejercicio 8.

8. Modificad la solución al ejercicio 50 de la Relación de Problemas II.
En él se calculaba, repetidamente (para diferentes valores de la abscisa x) el
valor de la función gaussiana. Calcular el valor de la función gaussiana en un
punto arbitrario x con una función. Hacedlo de dos maneras: a) con una función
que admita un sólo parámetro (x) y b) con una función que admita tres
parámetros (x, µ y σ). ¿Cuál es la mejor solución?

b) CDF(x) con la función escrita en el ejercicio 28.

28. En el ejercicio 51 de la Relación de Problemas II se calculó la
distribución acumulada (cumulative distribution function) ó CDF de la función
gausssiana para un punto cualquiera x. Reescriba ese ejercicio calculando el
valor de la CDF en un punto x usando una función.

c) CDF(x) con la función escrita en el ejercicio 29,
para valores de x comprendidos entre µ − 3σ y µ + 3σ. Use 0.25 como la
diferencia entre dos valores consecutivos de x.

29. Puede obtenerse un valor aproximado de CDF(x) como el dado por la siguiente
fórmula (ver, por ejemplo, en el artículo de Wikipedia
https://es.wikipedia.org/w/index.php?title=Distribucion_normal la sección
Aproximaciones numéricas de la distribución normal y su función de
distribución)
CDF(x) ≈ w = 1 − g(|x|)(b1t + b2t^2 + b3t^3 + b4t^4 + b5t^5)
t = 1/(1 + b0|x|)
b0 = 0,2316419 b1 = 0,319381530 b2 = −0,356563782
b3 = 1,781477937 b4 = −1,821255978 b5 = 1,330274429

Finalmente, si x ≥ 0 entonces CDF(x) = w. Si no, CDF(x) = 1 − w.

Modifique el ejercicio 28 de esta misma relación de problemas calculando ahora
el valor de la CDF en un punto x usando una función que realice los cálculos
descritos en este ejercicio.

3. Los problemas propuestos en la Relación de Ejercicios III relacionados con
la función gaussiana tienen el “inconveniente” de que tanto la función que
calcula el valor de la gaussiana en x como la que calcula el valor de la CDF en
x requieren como argumentos los valores de la esperanza y la desviación típica.

Cree el tipo de datos Gaussiana usando un registro y reescriba las funciones
antes mencionadas en base a este nuevo tipo de dato.

Escriba un programa (similar al ejercicio 30 de la Relación de Problemas III)
que:

1.- lea los parámetros que definen una distribución gaussiana (filtrados como
sea conveniente) y los almacene en un dato de tipo Gaussiana,

2.- muestre los valores de x, g(x) y CDF(x) para valores de x en el intervalo
[µ − 3σ, µ + 3σ], y

3.- pregunte si desea continuar, y de ser así, volver al paso 1.

ENTRADA: la desviacion tipica, la media y el valor de x.
SALIDA: el valor de la gaussiana en el punto y su cdf.

*/

#include <iostream>
#include <cmath>

using namespace std;

struct Gaussiana {

	double desviacion_tipica;
	double media;
	double variable_x;

}

//a.

double Gaussiana (Gaussiana dato){

  const double PI = 3.141592;
  double gaussiana;

  gaussiana = (1/(desviacion_tipica * sqrt (2 * PI)))
              * exp (- 0.5 * pow ((dato.variable_x - dato.media)
              / dato.desviacion_tipica, 2));

  return gaussiana;
}

//b.

double Cdf_b (Gaussiana dato){

  Gaussiana x_inicial =  dato.media - 3 * dato.desviacion_tipica;
  const double SALTO = 0.25;
  double cdf_b = 0;

  for (dato.x_inicial; dato.x_inicial <= dato.variable_x;
	  dato.x_inicial = dato.x_inicial + SALTO){

    cdf_b = cdf_b + (Gaussiana
		(dato.desviacion_tipica, dato.media, dato.x_inicial)) * SALTO;
  }

  return cdf_b;
}

//c.

double Cdf_c (Gaussiana dato)){

  const double B0 = 0.2316419, B1 = 0.319381530, B2 = - 0.356563782;
  const double B3 = 1.781477937, B4 = - 1.821255978, B5 = 1.330274429;
  double t, cdf_c;
  double variable_x_estandarizada = (variable_x - media) / desviacion_tipica;
  t = 1 / (1 + B0 * fabs (dato.variable_x_estandarizada));
  double w;
  w = 1 - (Gaussiana (dato.desviacion_tipica, dato.media,
	  fabs(dato.variable_x_estandarizada))
  *(B1*t + B2*pow (t, 2) + B3*pow (t, 3) + B4*pow (t, 4) + B5*pow (t, 5)));

  if (variable_x_estandarizada >= 0) cdf_c =  w;

  else cdf_c = (1 - w);

  return cdf_c;

}

int main() {

  //Declaraciones.

  double gaussiana, cdf_b, cdf_c;
  Gaussiana dato;


  //Entrada de datos.

  cout << "***********************************************" << endl << endl;

  do { //Filtro
    cout << "Introduzca un valor mayor que 0 para la desviacion_tipica. ";
    cin >> dato.desviacion_tipica;
} while (dato.desviacion_tipica <= 0);

  cout << endl;
  cout << "Introduzca un valor para la media. ";
  cin >> dato.media;

  cout << endl;
  cout << "Introduzca un valor para la variable x. ";
  cin >> dato.variable_x;

  cout << endl;

  //Calculos.

  //a.

  double x_inicial = media - 3 * desviacion_tipica;
  const double SALTO = 0.25;
  gaussiana = Gaussiana (dato.desviacion_tipica, dato.media, dato.variable_x);

  //b.
  cdf_b = Cdf_b (dato.desviacion_tipica, dato.media, dato.variable_x);

  //c.
  cdf_c = Cdf_c (dato.desviacion_tipica, dato.media, dato.variable_x);


  //Salida de datos.

  cout << "En un rango entre la media - 3 * desviacion tipica y "
       << "el valor de x " << endl;

  cout << "-------------------------------------------------" << endl;

  for (x_inicial; x_inicial <= dato.variable_x; x_inicial+=SALTO){
    gaussiana = Gaussiana (dato.desviacion_tipica, dato.media, x_inicial);

    cout << "Para " << x_inicial << " el valor de la gaussiana es "
         << gaussiana << endl;
  }
  cout << "-------------------------------------------------" << endl << endl;

  cout << "La distribución acumulada es " << cdf_b << endl;

  cout << "-------------------------------------------------" << endl << endl;

  cout << "La distribución acumulada aproximada es " << cdf_c << endl;

  cout << "*************************************************" << endl << endl;



  return 0;
}
