/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS IV

4. Para modelar un rectángulo se usará el tipo de dato Rectangulo. Un
rectángulo se caracterizará por la coordenada superior izquierda y la
coordenada inferior derecha (ambos son datos de tipo Punto2D).

Escribir un programa que lea las coordenadas que definen un rectángulo y
calcule la circunferencia centrada en el punto de corte de las diagonales del
rectángulo tal que su superficie la menor entre todas las circunferencias de
área mayor que la del rectángulo.

Use datos de tipo Rectangulo, Circunferencia y Punto2D para la resolución de
este problema.

Para el cálculo, considere comenzar con radio=0.5 e ir incrementando su valor
0.25 en cada iteración.

ENTRADA: Coordenadas de dos vertices opuestos.
SALIDA: area del rectangulo y centro, radio, area de la circunferencia de mayor
		area dentro del rectangulo.

*/

#include <iostream>
#include <cmath>

using namespace std;

// Registros:

// 1. Un punto bidimensional

struct Punto2D {

	double abscisa;
	double ordenada;
};

// 2. Un rectangulo

struct Rectangulo {

	Punto2D punto_1; // Coordenada superior izquierda
	Punto2D punto_2; // Coordenada inferior derecha
};

// 3. Una circunferencia

struct Circunferencia {

	Punto2D centro;
	double radio;
};

// Funciones:


Punto2D PuntoMedio (Rectangulo rectangulo){

	Punto2D punto_medio;

	punto_medio.abscisa =
	(rectangulo.punto_1.abscisa + rectangulo.punto_2.abscisa)/2;

	punto_medio.ordenada =
	(rectangulo.punto_1.ordenada + rectangulo.punto_2.ordenada)/2;

	return (punto_medio);
}

/****************************************************************************
La funcion PuntoMedio calcula el punto medio (abscisa y ordenada) entre dos
vertices.
****************************************************************************/

double AreaRectangulo (Rectangulo rectangulo){

	double base;
	double altura;
	double resultado; // �rea del rect�ngulo

	base = rectangulo.punto_2.abscisa - rectangulo.punto_1.abscisa;
	altura = rectangulo.punto_1.ordenada - rectangulo.punto_2.ordenada;
	resultado = base * altura;

	return (resultado);
}

/****************************************************************************
La funcion AreaRectangulo calcula el area del rectangulo a partir de las
coordenadas de los vertices introducidas.
****************************************************************************/

double AreaCircunferencia (Circunferencia circunferencia){

	const double PI = 6 * asin(0.5);
	double resultado;

	resultado = PI*circunferencia.radio*circunferencia.radio;

	return (resultado);
}

/****************************************************************************
La funcion AreaCircunferencia calcula el area de la circunferencia a partir del
punto medio de la diagonal.
****************************************************************************/

int main() {

	// Declaraciones

	const double RADIO_INICIAL = 0.5;
	const double SALTO = 0.25;

	Rectangulo rectangulo;
	Circunferencia circunferencia;

	double radio = RADIO_INICIAL;
	double area_rectangulo;
	double area_circunferencia;

	// Entrada de datos
	cout << "***********************************************" << endl << endl;


	cout << "Introduzca la coordenada x del vertice superior izquierdo de su"
		 << " rectangulo: ";
	cin >> rectangulo.punto_1.abscisa;
	
	cout << "Introduzca la coordenada y del vertice superior izquierdo de su"
		 << " rectangulo: ";
	cin >> rectangulo.punto_1.ordenada;


	do{ //Filtro
		cout << "Introduzca la coordenada x del vertice inferior derecho de su"
			 << " rectangulo: ";
		cin >> rectangulo.punto_2.abscisa;
	}
	while (rectangulo.punto_2.abscisa <= rectangulo.punto_1.abscisa);


	do{ //Filtro
		cout << "Introduzca la coordenada y del vertice inferior derecho de su"
			 << " rectangulo: ";
		cin >> rectangulo.punto_2.ordenada;
	}
	while (rectangulo.punto_2.ordenada >= rectangulo.punto_1.ordenada);

	//Calculos.

	circunferencia.centro = PuntoMedio (rectangulo);

	area_rectangulo = AreaRectangulo (rectangulo);
	area_circunferencia = AreaCircunferencia (circunferencia);

	while (area_circunferencia < area_rectangulo){

		circunferencia.radio = radio;
		area_circunferencia = AreaCircunferencia (circunferencia);

		radio = radio + SALTO;
	}

	// Salida de datos

	cout << endl;
	cout << "El area del rectangulo es " << area_rectangulo;
	cout << endl;
	cout << "La circunferencia de centro (" << circunferencia.centro.abscisa
	<< "," << circunferencia.centro.ordenada << "), de radio "
	<< circunferencia.radio << " y de area " << area_circunferencia
	<< " es la que buscabamos" << endl;

	cout << "***********************************************" << endl << endl;

	return 0;
}
