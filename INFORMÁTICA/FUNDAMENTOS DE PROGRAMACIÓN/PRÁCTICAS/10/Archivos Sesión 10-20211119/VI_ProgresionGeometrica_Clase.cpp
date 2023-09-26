/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N 
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 6
//
/*	 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construir� una clase "ProgresionGeometrica" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "ProgresionGeometrica" queda completamente 
	determinado por el primer t�rmino y la raz�n. 

	Los m�todos ofertados por la clase ser�n los conocidos: 
	- Sumar hasta un tope todos los t�rminos de la progresi�n
	- Obtener el t�rmino n-�simo de la progresi�n
	- Multiplicar hasta un tope todos los t�rminos de la progresi�n
	- Suma hasta el infinito todos los t�rminos de la progresi�n

	En el dise�o de esta clase se ha decidido que, una vez creado 
	el objeto, no se pueda cambiar ni el primer t�rmino ni la raz�n 
	de la progresi�n. En caso contrario, habr�a que a�adir los 
	m�todos correspondientes:  
	
		SetRazon()
		SetPrimerTermino()
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/*
	La clase "ProgresionGeometrica" representa un modelo de generaci�n de 
	datos que siguen una relaci�n num�rica dada por su t�rmino general:

                      i-1        
        a_i =  a_1 * r    = a_{i-1} * r

	donde "a_1" es el primer t�rmino de la serie, y "r" es la raz�n
*/

class ProgresionGeometrica
{
	
private:

	double primer_termino;	// Una progresi�n geom�trica queda completamente
	double razon;			// especificada por estos dos valores

public:

	/***********************************************************************/
	// Constructor con argumentos
	// No se han fijado precondiciones

	ProgresionGeometrica (double primer_termino_progresion, 
						  double razon_progresion)
	{
		primer_termino = primer_termino_progresion;
		razon = razon_progresion;
	}

	/***********************************************************************/
	// M�todos de lectura (Get) de los datos individuales 
	
	double PrimerTermino()
	{
		return primer_termino;
	}

	double Razon()
	{
		return razon;
	}

	/***********************************************************************/
	// C�lculo del t�rmino i-�simo
	//                 i-1
	//	a_i =  a_1 * r 
	//
	// Entradas: 
	//		i: �ndice del t�rmino (posici�n en la serie)
	// Salida: a_i 
	//
	// PRE: i >= 1
	
	double Termino (int i) 
	{
		return (primer_termino * pow (razon, i-1));
	}

	/*****************************************************************/
	// C�lculo de la sumatoria por la expresi�n simple:
	//
	// 		  i=tope 		    
	//		  __                     tope
	//		<		               r      - 1
	//		 >    a_i	= 	a_1 * ------------
	//		< __   		            r - 1
	//		  i=1		     
	//		     
	// Entradas: 
	//		tope: �ndice del �ltimo t�rmino a sumar
	// Salida: a_1 + a_2 + ... + a_{tope} 
	//
	// PRE: tope >= 1

	double SumaHasta (int tope) 
	{
		return (primer_termino * ((pow(razon,tope) - 1) / (razon-1)));
	}

	/*****************************************************************/
	// C�lculo de la sumatoria hasta infinito:
	//
	//		 i=OO
	//		  __
	//		<              a_1
	//		 >    a_i  = -------	siempre que |r| < 1
	//		< __          1 - r
	//		  i=1
	//
	// Salida: a_1 + a_2 + ...  
	//
	// PRE: |razon| < 1

	double SumaHastaInfinito () 
	{
		return (primer_termino / (1 - razon));
	}

	/*****************************************************************/
	// C�lculo del producto de los primeros k valores de la serie: 
	//
	//        i=tope      i=tope
	//		  __          __                  _____________________
	//		 |  |  		 |	|         i-1    /                tope
	//		 |  |  a_i = |  |  a_1 * r    = V  (a_1 * a_{tope}    )
	//		  i=1         i=1
	//
	// Entradas: 
	//		tope: �ndice del �ltimo t�rmino a multiplicar  
	// Salida: a_1 * a_2 * ... * a_{tope} 
	//
	// PRE: tope >= 1

	double MultiplicaHasta (int tope) 
	{
		return (sqrt (pow (primer_termino * Termino (tope), tope)));
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/
/*********************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Lectura de los par�metros que definen la progresi�n. 
	// No hay precondiciones establecidas para ellos.

	double primero, razon;

	cout << "Primer termino de la progresion: ";
	cin >> primero;
	cout << "Razon de la progresion: ";
	cin >> razon;
	
	
	// Creaci�n de la progresi�n (constructor)

	ProgresionGeometrica prog (primero, razon);


	// Informaci�n sobre la progresi�n creada
	
	cout << endl;
	cout << "Calculos sobre la progresion: "<< endl;
	cout << "\tPrimer termino: = " << setw(10) << setprecision (6)
		 << prog.PrimerTermino() << endl;
	cout << "\tRazon: = " << setw(10) << setprecision (6)
		 << prog.Razon() << endl;
	cout << endl;

	// Variables para c�lculos
	
	int tope; // M�ximo �ndice para la suma / producto
	
	double suma_hasta_tope,		// Para guardar los 
		   suma_hasta_inf,		// resultados de los 
		   producto_hasta_tope;	// c�lculos
		   
	// C�lculo de la suma
			   
	// Lectura del m�ximo �ndice para la suma
	do {
		cout << "Indice (debe ser >=1) del ultimo termino a sumar: ";
		cin >> tope;
	} while (tope < 1);
	
	suma_hasta_tope = prog.SumaHasta (tope);

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << suma_hasta_tope;
	cout << endl;
	

	// C�lculo y resultado de la sumatoria hasta "infinito"
	// El c�lculo presupone que |razon| < 1
	
	if (abs(prog.Razon()) < 1) {
		suma_hasta_inf = prog.SumaHastaInfinito ();
		cout << "Suma hasta infinito = " 
			 << setw(10) << setprecision (2) << suma_hasta_inf;
		cout << endl << endl;	 
	}
	else 
		cout << "No puede calcularse suma hasta infinito " 
			 << "porque |" << setprecision (2) << prog.Razon() << "| >= 1";
		
	cout << endl << endl;
	
	
	// C�lculo del producto 

	// Lectura del m�ximo �ndice para el producto
	do {
		cout << "Indice (debe ser >=1) del ultimo termino a multiplicar: ";
		cin >> tope;
	} while (tope < 1);
	
	producto_hasta_tope = prog.MultiplicaHasta (tope);

	cout << "\nProducto hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << producto_hasta_tope;
	cout << endl << endl;
	
	return 0;
}

/*********************************************************************/
/*********************************************************************/

