/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
//
/*	
	En este programa se presenta la clase "Distancia".
	Internamente se usa un único dato miembro privado llamado "kilometros"
	al que se le asignará un valor a través de métodos Set, realizando la
	conversión oportuna. La clase también proporcionará métodos Get, para
	lo que tendrá que realizar la conversión oportuna.
		* una milla es 1,609344 kilómetros.
		* un kilómetro es 0,621371192 millas.

	NOTA: La implementación de la clase podría haber utilizado como dato
	miembro privado "millas", en vez de utilizar como base los kilómetros.
	Esto se oculta a los usuarios de la clase, que sólo ven los métodos
	públicos SetKilometros, SetMillas, GetKilometros y GetMillas.
*/
 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// La clase "Distancia" representa distancias expresadas en kilómetros,
// aunque permite gestionar distancias en kilómetros y/o millas.

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
	double kilometros;  // Num. de kilómetros

public:

	/***********************************************************************/
	// Constructor sin argumentos.
	
	Distancia (void) : kilometros(0)
	{ }
	
	/***********************************************************************/
	// Constructor con argumentos.
	// Inicia el campo "kilometros" con el valor dado.
	// Recibe:
	//		los_kilometros, núm. de kilómetros
	// PRE: 0 <= los_kilometros

	Distancia (double los_kilometros)
	{
		kilometros = los_kilometros;
	}

	/***********************************************************************/
	// Métodos Get

	double GetKilometros (void)
	{
		return (kilometros);
	}

	double GetMillas (void)
	{
		return (kilometros*MILLA_POR_KM);
	}

	/***********************************************************************/
	// Métodos Set

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
// Inicialización de las constantes estáticas 

const double Distancia :: KM_POR_MILLA = 1.609344;
const double Distancia :: MILLA_POR_KM = 1.0/(Distancia::KM_POR_MILLA);
*/
	
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/*
	Una sencilla aplicación: proggrama que muestra una tabla de distancias
	entre 0 y 10 Km, con incrementos de 0.5 Km.
*/

int main()
{	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	const double DIST_INIC = 0.0;
	const double DIST_FIN = 10.0;
	const double INCR_DIST = 0.5;

	Distancia distancia;
	
	// Tabla kilómetros - millas
	
	cout << "KILOMETROS" << "     " << "    MILLAS" << endl;
	
	for (double d=DIST_INIC; d<=DIST_FIN; d+=INCR_DIST) {

		distancia.SetKilometros(d);
		
		cout << setw(10) << setprecision(3) << distancia.GetKilometros();
		cout << "     ";
		cout << setw(10) << setprecision(3) << distancia.GetMillas();
		cout << endl;
	}
	cout << endl;

	// Tabla millas - kilómetros

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
