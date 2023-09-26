/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
/*	
    (ver enunciado) 
	
	Usa la clase "Cronometro" para medir el tiempo empleado por las dos 
	versiones implementadas para hacer la suma de los factoriales. 
	En realidad, para poder apreciar el tiempo hacemos la suma 2e+7 veces.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Cronometro
{
	
private:
	
   typedef std::chrono::time_point<std::chrono::steady_clock>
           Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano> IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;

public:
	
	/***********************************************************************/
	void Reset() { 
		inicio = chrono::steady_clock::now();
	}
	
	/************************************************************************/
	double NanoSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count());
	}
	
	/************************************************************************/
	double MiliSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count()/1e6);
	}
	/************************************************************************/  
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Calcula n!
// PRE: n<=15

long Factorial (int n)
{
	long factorial = 1;

	for (int k = 2; k<=n ; k++)
		factorial = factorial * k;
			
	return (factorial);
}

/***************************************************************************/
// Calcula Sum (n!) n=1,...tope
// PRE: n<=15

long SumaFactorial_Directo (int tope)
{
	long suma_factoriales = 0;
	
	for (int i=1; i<=tope; i++) {
		suma_factoriales += Factorial (i);
	}
	return (suma_factoriales);
}

/***************************************************************************/
// Calcula n!
// Versión "optimizada" 
/* El método directo realiza muchos cálculos repetidos 
   Por ejemplo, para calcular la suma con T=5, realiza:   
  		1! = 1
  	 	2! = 1 * 2 = (1*2)
		3! = 1 * 2 * 3 = (1*2)*3
		4! = 1 * 2 * 3 * 4 = ((1*2)*3)*4
		5! = 1 * 2 * 3 * 4 * 5= (((1*2)*3)*4)*5
	Observe que 1*2, se realiza 4 veces, (1*2)*3 se calcula 
	3 veces y ((1*2)*3)*4 se calcula 2 veces. 
	
	Si reescribimos las operaciones para que al mismo tiempo que se 
	suma se van multiplicando términos podemos simplificar los 
	cálculos y un ciclo es suficiente: 
	
    (1) + 2 * (1) + 3 * (2*1) + 4 * (3*2*1) + 5 * (4*3*2*1)
               ^		  ^            ^             ^
		     antes	    antes        antes         antes 
*/
// PRE: n<=15

long SumaFactorial_Optimizado (int tope)
{
	long suma_factoriales = 1;
	long termino_i = 1;
	
	for (int i=2; i<=tope; i++) {

		termino_i = i*termino_i;
		suma_factoriales += termino_i;
	}
	return (suma_factoriales);	
}

/***************************************************************************/
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	const int MAX_TOPE = 15;
	const double VECES = 2e+7;
	
	int tope;
	long suma1, suma2;	
	
	Cronometro mi_crono;  // Objeto de clase Cronometro


	// Lectura y filtrado de "tope"
	
	do {
		cout << "Introduzca un entero positivo entre 1 y " << MAX_TOPE << ": ";
		cin >> tope;
	} while ((tope<1) || (tope>MAX_TOPE));



	// Cálculos
	
	// 1. Método directo	
	
	mi_crono.Reset(); // Puesta en marcha de mi_crono!!
		
	for (int i=0; i < VECES; i++)
   		suma1 = SumaFactorial_Directo(tope);
   		
   	// Leer tiempo (ms)
	double marca_1_ms = mi_crono.MiliSegundosTranscurridos(); 

	double marca_1_ns = marca_1_ms*1e6; // pasar a ns
   

	// 2. Método optimizado

	mi_crono.Reset(); // Puesta en marcha de mi_crono!!

	for (int i=0; i < VECES; i++)
   		suma2 = SumaFactorial_Optimizado(tope);	

   	// Leer tiempo (ns)
	double marca_2_ns = mi_crono.NanoSegundosTranscurridos(); 
	
	double marca_2_ms = marca_2_ns/1e6; // pasar a ms
   

	// Presentación de resultados
	
	cout << endl;
	cout << "Resultado 1 (Cálculo directo)    = " << suma1 << endl;
	cout << "Tiempo = " <<setw(18) <<setprecision(6) << marca_1_ns << " ns = " 
	                    <<setw(18) <<setprecision(6) << marca_1_ms << " ms" 
						<< endl;
	cout << endl;  
	
	cout << endl;
	cout << "Resultado 2 (Cálculo optimizado) = " << suma2 << endl;
	cout << "Tiempo = " <<setw(18) <<setprecision(6) << marca_2_ns << " ns = " 
	                    <<setw(18) <<setprecision(6) << marca_2_ms << " ms" 
						<< endl;
	cout << endl;
	
	return 0;
}
