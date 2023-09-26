/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 6
//
/*	
	En este programa se presenta la clase "Distancia".
	Internamente se usa un �nico dato miembro privado llamado "kilometros"
	al que se le asignar� un valor a trav�s de m�todos Set, realizando la
	conversi�n oportuna. La clase tambi�n proporcionar� m�todos Get, para
	lo que tendr� que realizar la conversi�n oportuna.
		* una milla es 1,609344 kil�metros.
		* un kil�metro es 0,621371192 millas.

	NOTA: La implementaci�n de la clase podr�a haber utilizado como dato
	miembro privado "millas", en vez de utilizar como base los kil�metros.
	Esto se oculta a los usuarios de la clase, que s�lo ven los m�todos
	p�blicos SetKilometros, SetMillas, GetKilometros y GetMillas.
*/
 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// La clase "Distancia" representa distancias expresadas en kil�metros,
// aunque permite gestionar distancias en kil�metros y/o millas.

const double KM_POR_MILLA = 1.609344;
const double MILLA_POR_KM = 1.0/KM_POR_MILLA;

class Distancia
{
	
private:

	/*	
	static const double KM_POR_MILLA;
	static const double MILLA_POR_KM;
	*/
	
	// PRE: 0 <= kilometros
	double kilometros;  // Num. de kil�metros

public:

	/***********************************************************************/
	// Constructor sin argumentos.
	
	Distancia (void) : kilometros(0)
	{ }
	
	/***********************************************************************/
	// Constructor con argumentos.
	// Inicia el campo "kilometros" con el valor dado.
	// Recibe:
	//		los_kilometros, n�m. de kil�metros
	// PRE: 0 <= los_kilometros

	Distancia (double los_kilometros)
	{
		kilometros = los_kilometros;
	}

	/***********************************************************************/
	// M�todos Get

	double GetKilometros (void)
	{
		return (kilometros);
	}

	double GetMillas (void)
	{
		return (kilometros*MILLA_POR_KM);
	}

	/***********************************************************************/
	// M�todos Set

	void SetKilometros (double los_kilometros)
	{
		kilometros = los_kilometros;
	}

	void SetMillas (double las_millas)
	{
		kilometros = las_millas*KM_POR_MILLA;
	}

	/***********************************************************************/
};

/*
// Inicializaci�n de las constantes est�ticas 

const double Distancia :: KM_POR_MILLA = 1.609344;
const double Distancia :: MILLA_POR_KM = 1.0/(Distancia::KM_POR_MILLA);
*/
	
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/*
	Una sencilla aplicaci�n: proggrama que muestra una tabla de distancias
	entre 0 y 10 Km, con incrementos de 0.5 Km.
*/

int main()
{	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	const double DIST_INIC = 0.0;
	const double DIST_FIN = 10.0;
	const double INCR_DIST = 0.5;

	Distancia distancia;
	
	// Tabla kil�metros - millas
	
	cout << "KILOMETROS" << "     " << "    MILLAS" << endl;
	
	for (double d=DIST_INIC; d<=DIST_FIN; d+=INCR_DIST) {

		distancia.SetKilometros(d);
		
		cout << setw(10) << setprecision(3) << distancia.GetKilometros();
		cout << "     ";
		cout << setw(10) << setprecision(3) << distancia.GetMillas();
		cout << endl;
	}
	cout << endl;

	// Tabla millas - kil�metros

	cout << endl;
	cout << "    MILLAS" << "     " << "KILOMETROS" << endl;

	for (double d=DIST_INIC; d<=DIST_FIN; d+=INCR_DIST) {

		distancia.SetMillas(d);

		cout << setw(10) << setprecision(3) << distancia.GetMillas();
		cout << "     ";
		cout << setw(10) << setprecision(3) << distancia.GetKilometros();
		cout << endl;
	}
	cout << endl;


	return 0;
}
