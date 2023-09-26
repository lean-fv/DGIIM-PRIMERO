/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
/*	
	El número aúreo se conoce desde la Antigüedad griega y aparece en muchos 
	temas de la geometría clásica. La forma más sencilla de definirlo es 
	como el único número positivo  que cumple que Phi^2 - Phi = 1 y por 
	consiguiente su valor es
	                ___
               1 + V 5
		Phi = ---------- = 1,6180339887...
                  2
	Se pueden construir aproximaciones al número aúreo mediante la fórmula

		      fib(n + 1)
	   a_n = -----------
                fib(n)

	siendo fib(n) el término n-ésimo de la sucesión de fibonacci, definida:
		fib(1) = 1
		fib(2) = 1
		fib(n) = fib(n-2) + fib(n-1) para n>2

	A medida que n aumenta, a_n oscila, y es alternativamente menor y mayor 
	que la razón áurea (Para más información, véase, por ejemplo 
	http://es.wikipedia.org/wiki/Número_áureo) 

	Este programa calcula el menor valor de n que hace que la aproximación
	dada por a_n difiere en menos de Delta del número Phi, sabiendo que n>=1. 
	
	Entradas: Un número real, Delta, que establece la precisión. 
	Salidas:  El valor de n
	
	EXPLICACIÓN DETALLADA EN MI CANAL DE YOUTUBE:
	
		https://www.youtube.com/watch?v=Xdo_-UlSSO0
	
*/	
/***************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	// Valor "real" de Phi: 1,6180339887...
	const double PHI = (1 + sqrt(5.0)) / 2.0; 

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Lectura de datos
	
	double Delta;	// Precisión de la aproximación 	
	
	cout << "Calculando la aproximacion al numero Aureo = "
		 << setw(15) << setprecision(13) << PHI << endl << endl;
	
	do {
		cout << "Introduzca la precision (< 1) deseada para la aproximacion: ";
		cin >> Delta;
	} while (Delta>=1);

	cout << endl; 
	
	
	// Cálculos
	
	double	a_n;			// Término n-ésimo de la serie
	double	diferencia; 	// |a_n - Phi|

	double 	diferencia_anterior = 1; // Primer mínimo

	int n = 1;	// Resultado: índice del término buscado (1,2,3...)
	
	bool sigo = true; 

	while (sigo) {
	
		// Calcular el término n-ésimo de la serie dada por   
		//		      fib(n+1)
		//	   a_n = ----------
		//             fib(n)
		//
		// Antes, calcular fib(n) y fib(n+1)
		//
		//    n:  1  2  3  4  5  6   7   8 ...
		//fib(n): 1  1  2  3  5  8  13  21 ...
		
		int resultado = 1; 
	
		int ant1 = 1; // fib(2)
		int ant2 = 1; // fib(1) 
	
		for (int i=2 ; i<=n; i++) {
			
			resultado = ant1 + ant2; // fib (i)
	
			// Preparamos la siguiente iteracion
			ant2 = ant1; 		// fib(n)		
			ant1 = resultado;	// fib(n+1)	
		}
		
		int fib_n = ant2;		
		int fib_n_mas_1 = ant1;
				
		// Calcular  a_n = fib(n+1)/fib(n)	
		a_n = ((double)fib_n_mas_1) / fib_n;  
	
		// Calcular el error de la aproximación		
		diferencia = fabs(a_n-PHI);	// |a_n - Phi|
				
		// Mensajes -optativos- 
		cout << "a_" << setw(3) << n << " = "
		     << setw(15) << setprecision(13) << a_n;
		cout << " (Dif = " << setw(15) <<setprecision(13)
		     << diferencia << ")" << endl;
		
		// Evaluar criterio de parada
		
		if (diferencia <= Delta)
			sigo = false;
		else {
			n++;
			diferencia_anterior = diferencia;	
		}
		
	} // while (sigo) 

	cout << endl;
	cout << "Valor buscado   = "
		 << setw(15) << setprecision(13) << PHI << endl;
	cout << "Valor calculado = "
		 << setw(15) << setprecision(13) << a_n << endl << endl;
	cout << endl;
	
	cout << "Menor valor de n = " << setw(3) << n << endl << endl; 
	cout << "Diferencia actual =   " << setw(15) << setprecision(8) 
		 << diferencia << endl;
	cout << "Precision =           " << setw(15) << setprecision(8)
		 << Delta << endl;;
	cout << "Diferencia anterior = " << setw(15) << setprecision(8) 
	     << diferencia_anterior << endl;	
	cout << endl << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
/*

Valor de Phi que queremos aproximar con una precisión Delta: 
               1 + V 5
		Phi = ---------- = 1,6180339887...
                  2

Calculamos a_1, a_2, a_3, ..... donde 

		      fib(n+1)
	   a_n = ----------
               fib(n)

y seleccionamos n:  |a_n-Phi| < Delta

Cálculo de los fib(n): 

fib(1) = 1
fib(2) = 1
fib(3) = fib(2) + fib(1)
fib(4) = fib(3) + fib(2)
.... 
  
    n:  1  2  || 3  4  5  6   7   8 ...
fib(n): 1  1  || 2  3  5  8  13  21 ...
		

Por ejemplo: 
		
	    fib (2)     1
a_1 = --------- =  --- = 1.0000000000000
        fib (1)     1
         
        fib (3)     2
a_2 = --------- =  --- = 2.0000000000000
        fib (2)     1

        fib (4)     3
a_3 = --------- =  --- = 1.5000000000000
        fib (3)     2
         
        fib (5)     5
a_4 = --------- =  --- = 1.6666666666667
        fib (4)     3
        
        fib (6)     8
a_5 = --------- =  --- = 1.6000000000000
        fib (5)     5

......

Los valores a_n se distribuyen alternativamente a ambos lados de Phi, 
y cada vez están más próximos a su valor: la serie connverge a Phi 

--|----------------|----------*------|------------|----
 a_1              a_3        Phi     a_4         a_2
 1.0              1.5      1.618...  1.666...    2.0

Ejemplo.

si Delta = 0.0001 (diezmilésimas), como Phi = 1,6180339887... 

a_  1 = 1.0000000000000 (Dif = 0.6180339887499)
a_  2 = 2.0000000000000 (Dif = 0.3819660112501)
a_  3 = 1.5000000000000 (Dif = 0.1180339887499)
a_  4 = 1.6666666666667 (Dif = 0.0486326779168)
a_  5 = 1.6000000000000 (Dif = 0.0180339887499)
a_  6 = 1.6250000000000 (Dif = 0.0069660112501)
a_  7 = 1.6153846153846 (Dif = 0.0026493733653)
a_  8 = 1.6190476190476 (Dif = 0.0010136302977)
a_  9 = 1.6176470588235 (Dif = 0.0003869299264)
a_ 10 = 1.6181818181818 (Dif = 0.0001478294319)
a_ 11 = 1.6179775280899 (Dif = 0.0000564606600)

Valor buscado   = 1.6180339887499
Valor calculado = 1.6179775280899

Menor valor de n =  11

Diferencia actual (n=11) -----> 0.00005646 < 0.0001
Precision =                     0.00010000
Diferencia anterior (n=10) ---> 0.00014783 > 0.0001

*/
/***************************************************************************/

