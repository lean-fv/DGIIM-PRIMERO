/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VI

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

6. Este ejercicio consiste en reescribir la solución al problema planteado en
el ejercicio 4 de la Relación de Problemas IV. Ahora se utilizarán clases para
entidades tipo rectangulo y circunferencia. En cualquier caso, la solución no
será la definitiva ya que necesitamos profundizar en la materia para poder
diseñar una correcta estructura de clases: en este momento no sabemos cómo
trabajar con una clase que tiene datos miembro de otra clase (p.e. la clase
Circunferencia se caracteriza a partir de un dato Punto2D -el centro- además
del radio). En el ejercicio ?? de la Relación de Problemas VII se solucionará
correctamente este problema. El nuevo enunciado es el siguiente:

Para modelar un rectángulo se usará la clase Rectangulo. Un rectángulo
se caracterizará por la coordenada superior izquierda y la coordenada inferior
derecha (ambos son datos struct de tipo Punto2D).

Para modelar una circunferencia se usará la clase Circunferencia.
Una circunferencia se caracterizará por la coordenada del centro (un dato
struct de tipo Punto2D) y el radio.

Escribir un programa que lea las coordenadas que definen un rectángulo y
calcule la circunferencia centrada en el punto de corte de las diagonales del
rectángulo tal que su superficie sea la menor entre todas las circunferencias
de área mayor que la del rectángulo. Para el cálculo, considere comenzar con
radio=0.5 e ir incrementando su valor 0.25 en cada iteración.

ENTRADA: Coordenadas de dos vertices opuestos.
SALIDA: area del rectangulo y centro, radio, area de la circunferencia de mayor
		area dentro del rectangulo.

*/

#include <iostream>
#include <cmath>

using namespace std;

/*---------------------------------------------------------------------------
								Registro Punto2D
---------------------------------------------------------------------------*/

struct Punto2D {

	double abscisa;
	double ordenada;
};

/*---------------------------------------------------------------------------
								Clase Rectangulo
---------------------------------------------------------------------------*/


class Rectangulo {

private:

	Punto2D punto_1; // Coordenada superior izquierda
	Punto2D punto_2; // Coordenada inferior derecha


public:

	//Setter.

	//Pre: abscisa1 < abscisa2 y ordenada1 > ordenada2.
	void SetPunto (double abscisa1, double ordenada1,
				double abscisa2, double ordenada2){

		punto_1.abscisa = abscisa1;
		punto_1.ordenada = ordenada1;
		punto_2.abscisa = abscisa2;
		punto_2.ordenada = ordenada2;
	}



	/*************************************************************************
	El metodo PuntoMedio calcula el punto medio (abscisa y ordenada) entre dos
	vertices.
	**************************************************************************/


	Punto2D PuntoMedio (void){

		Punto2D punto_medio;

		punto_medio.abscisa =
		(punto_1.abscisa + punto_2.abscisa)/2;

		punto_medio.ordenada =
		(punto_1.ordenada + punto_2.ordenada)/2;

		return (punto_medio);
	}


	/**************************************************************************
	El metodo AreaRectangulo calcula el area del rectangulo a partir de las
	coordenadas de los vertices introducidas.
	**************************************************************************/

	double AreaRectangulo (void){

		double base;
		double altura;
		double resultado; // Area del rectangulo

		base = punto_2.abscisa - punto_1.abscisa;

		altura = punto_1.ordenada - punto_2.ordenada;

		resultado = base * altura;

		return (resultado);
	}

};


/*---------------------------------------------------------------------------
								Clase Circunferencia
---------------------------------------------------------------------------*/

class Circunferencia {

private:

	Punto2D centro;
	double radio;


public:

	//Setters.

	void SetCentro (Punto2D el_centro){

		centro = el_centro;
	}

	//Pre: el_radio > 0
	void SetRadio (double el_radio){

		radio = el_radio;
	}


	//Getters.

	double GetCentroAbs (void){

		return (centro.abscisa);
	}

	double GetCentroOrd (void){

		return (centro.ordenada);
	}

	double GetRadio (void){
		return (radio);
	}



	/*************************************************************************
	El metodo AreaCircunferencia calcula el area de la circunferencia a partir
	del punto medio de la diagonal.
	*************************************************************************/

	double AreaCircunferencia (void){

		const double PI = 6 * asin(0.5);
		double resultado;

		resultado = PI * radio * radio;

		return (resultado);
	}

};


/*---------------------------------------------------------------------------
								Programa principal
---------------------------------------------------------------------------*/

int main() {

	// Declaraciones

	const double SALTO = 0.25;


	double abscisa1, ordenada1, abscisa2, ordenada2;
	Rectangulo rectangulo;
	double area_rectangulo;

	Circunferencia circunferencia;

	const double RADIO_INICIAL = 0.5;
	double area_circunferencia;

	// Entrada de datos

	cout << "***********************************************" << endl << endl;

	cout << "Introduzca la coordenada x del vertice superior izquierdo de su"
		 << " rectangulo: ";
	cin >> abscisa1;


	cout << "Introduzca la coordenada y del vertice superior izquierdo de su"
		 << " rectangulo: ";
	cin >> ordenada1;


	do{ //Filtro
		cout << "Introduzca la coordenada x del vertice inferior derecho de su"
			 << " rectangulo: ";
		cin >> abscisa2;
	} while (abscisa2 <= abscisa1);


	do{ //Filtro
		cout << "Introduzca la coordenada y del vertice inferior derecho de su"
			 << " rectangulo: ";
		cin >> ordenada2;
	} while (ordenada2 >= ordenada1);

	rectangulo.SetPunto(abscisa1, ordenada1, abscisa2, ordenada2);


	//Calculos.

	area_rectangulo = rectangulo.AreaRectangulo();

	Punto2D el_centro = rectangulo.PuntoMedio();
	circunferencia.SetCentro(el_centro);

	double el_radio = RADIO_INICIAL;
	circunferencia.SetRadio(el_radio);

	area_circunferencia = circunferencia.AreaCircunferencia();

	while (area_circunferencia <= area_rectangulo){

		el_radio = el_radio + SALTO;
		circunferencia.SetRadio(el_radio);
		area_circunferencia = circunferencia.AreaCircunferencia();
	}

	// Salida de datos

	cout << endl;
	cout << "El area del rectangulo es " << area_rectangulo << endl;

	cout << "La circunferencia de centro ("
		 << circunferencia.GetCentroAbs()
		 << "," << circunferencia.GetCentroOrd()
		 << "), de radio "
		 << circunferencia.GetRadio() << " y de area "
		 << area_circunferencia << " es la que buscabamos" << endl;

	cout << "***********************************************" << endl << endl;

	return 0;
}
