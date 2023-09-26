/*

FUNDAMENTOS DE PROGRAMACIÓN

LEANDRO JORGE FERNÁNDEZ VEGA

DOBLE GRADO EN INGENIERÍA INFORMÁTICA Y MATEMÁTICAS

RELACIÓN DE PROBLEMAS VII

37. Reescriba la solución del ejercicio 23 de la Relación de Problemas V usando
las clases Punto2D, Circunferencia y Rectangulo.
Las circunferencias en las que estamos interesados se guardarán en un array
conforme se vayan calculando. Después, se mostrará cuántas circunferencias se
han guardado y sus propiedades.

ENTRADA: Las coordenadas de dos vertices.
SALIDA: el punto de corte de las diagonales, las circunferencias que caben en el
rectangulo.

*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>



using namespace std;

/*---------------------------------------------------------------------------
								Clase Punto2D
---------------------------------------------------------------------------*/

class Punto2D
{

private:

	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:

	Punto2D (void)
	{}

	/********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� creando.

	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/********************************************************************/
	// M�todos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/********************************************************************/

	bool SonIguales (double coordenada1, double coordenada2)
	{
		bool son_iguales = (coordenada1 == coordenada2);

		return(son_iguales);
	}

	/********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/********************************************************************/

	string ToString ()
	{
		return ("["+to_string(x)+", "+to_string(y)+"]");
	}

	/********************************************************************/


};

/*---------------------------------------------------------------------------
								Clase Rectangulo
---------------------------------------------------------------------------*/


class Rectangulo {

private:

	Punto2D punto_1; // Coordenada superior izquierda
	Punto2D punto_2; // Coordenada inferior derecha


public:



	//Pre: abscisa1 < abscisa2 y ordenada1 > ordenada2.
	Rectangulo (double abscisa1, double ordenada1,
		double abscisa2, double ordenada2) : punto_1 (abscisa1, ordenada1),
		punto_2 (abscisa2, ordenada2)

	{}

	/*************************************************************************
	El metodo PuntoMedio calcula el punto medio (abscisa y ordenada) entre dos
	vertices.
	**************************************************************************/
	Punto2D PuntoMedio (void){


		double punto_medio_abs =
		(punto_1.GetX() + punto_2.GetX())/2;

		double punto_medio_ord =
		(punto_1.GetY() + punto_2.GetY())/2;

		return Punto2D(punto_medio_abs, punto_medio_ord);
	}


	/**************************************************************************
	El metodo AreaRectangulo calcula el area del rectangulo a partir de las
	coordenadas de los vertices introducidas.
	**************************************************************************/

	double AreaRectangulo (void){

		double base;
		double altura;
		double resultado; // Area del rectangulo

		base = punto_2.GetX() - punto_1.GetX();

		altura = punto_1.GetY() - punto_2.GetY();

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

	//Constructor sin argumentos.
	Circunferencia (void)
	{}

	//Constructor con argumentos.

	//Pre: el_radio > 0
	Circunferencia (Punto2D el_centro, double el_radio) : centro(el_centro),
	radio(el_radio)

	{}

	//Pre: el_radio > 0
	void SetRadio (double el_radio){

		radio = el_radio;
	}


	//Getters.

	string GetCentro(){

		string coord_centro = "[" + to_string (centro.GetX()) + ","
		+ to_string (centro.GetY()) + "]";

		return coord_centro;
	}


	double GetRadio (void){
		return (radio);
	}


	/*************************************************************************
	Metodo AreaCircunferencia: calcula el area de la circunferencia a partir
	del punto medio de la diagonal.
	*************************************************************************/

	double AreaCircunferencia (void){

		const double PI = 6 * asin(0.5);
		double resultado;

		resultado = PI * radio * radio;

		return (resultado);
	}

	/*************************************************************************
	Metodo MuestraCircunferencia: compone en un string los el radio y area de
	la circunferencia.
	*************************************************************************/

	string MuestraCircunferencia (void){

		string circunferencia = "Radio: " + to_string (GetRadio())
		+ " Area: " + to_string (AreaCircunferencia());

		return circunferencia;
	}


};


/*---------------------------------------------------------------------------
								Programa principal
---------------------------------------------------------------------------*/

int main() {

	// Declaraciones

	double abscisa1, ordenada1, abscisa2, ordenada2;
	double area_rectangulo;


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

	Rectangulo rectangulo (abscisa1, ordenada1, abscisa2, ordenada2);


	//Calculos.

	area_rectangulo = rectangulo.AreaRectangulo();


	Punto2D el_centro = rectangulo.PuntoMedio();

	const int TAM = 100;
	const double SALTO = 0.25;
	const double RADIO_INICIAL = 0.5;

	double el_radio = RADIO_INICIAL;

	Circunferencia circunferencia (el_centro, el_radio);

	Circunferencia array_circunferencias[TAM];


	double area_circunferencia = circunferencia.AreaCircunferencia();
	int numero_circ = 0;

	while (area_circunferencia <= area_rectangulo){

		array_circunferencias[numero_circ] = circunferencia;
		numero_circ++;

		el_radio = el_radio + SALTO;
		circunferencia.SetRadio(el_radio);
		area_circunferencia = circunferencia.AreaCircunferencia();
	}

	// Salida de datos

	cout << endl;
	cout << "El area del rectangulo es " << area_rectangulo << endl;

	if (numero_circ > 0){

		cout << "Las circunferencias de centro " << circunferencia.GetCentro()
			 << " que caben dentro del rectangulo son: " << endl << endl;

		 for (int i = 0; i < numero_circ; i++){

			 cout << setw(5) << i+1 << "º: "
			 << array_circunferencias[i].MuestraCircunferencia() << endl;
		 }
	}

	else cout << "No cabe ninguna circunferencia." << endl;

	cout << "***********************************************" << endl << endl;

	return 0;
}
