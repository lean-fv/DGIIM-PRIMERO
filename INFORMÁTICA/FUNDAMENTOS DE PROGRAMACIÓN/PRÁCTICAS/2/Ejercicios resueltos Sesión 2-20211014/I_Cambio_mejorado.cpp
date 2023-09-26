/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
/*	
	Programa para una caja de un supermercado que que lee el total a pagar 
	y la cantidad pagada (cantidad pagada >= total a pagar) e indique 
	el número de monedas de 2 euros, 1 euro, 50 céntimos, 20 céntimos, 
	10 céntimos, 5 céntimos, 2 céntimos y 1 céntimo que se debe dar de cambio. 
	===> Se indicará el menor número de monedas de cada clase. 
   
   Entradas: total y pagado
		   	 PRE: pagado >= total
   Salidas:  Número de monedas de 2 euros, 1 euro, 50 céntimos, 
   			 20 céntimos, 10 céntimos, 5 céntimos, 2 céntimos y 1 céntimo  
   			 
   	Pruebas: total=28.12 y pagado=50
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos
#include <iomanip>    // Formato 
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	double total, pagado;
	int monedas_2e, monedas_1e, monedas_50ct, monedas_20ct, monedas_10ct,
	    monedas_5ct, monedas_2ct, monedas_1ct;  

	// Entradas
	// PRE: pagado >= total

	cout << "Total a pagar: ";
	cin >> total;
	cout << "Cantidad pagada: ";
	cin >> pagado;
 
	// "total" y "pagado" se ajustan (truncan) a dos decimales 
 	total = trunc(total * 100) / 100;							
 	pagado = trunc(pagado * 100) / 100;							


	// Cálculos
 
 	int total_int, pagado_int; // "total" y "pagado" en céntimos
 	int vuelta_int, euros_vuelta, centimos_vuelta; // Vuelta
	
 	total_int  = trunc(total * 100);     // Convertir "total" a céntimos 
 	pagado_int = trunc(pagado * 100);	 // Convertir "pagado" a céntimos 
 	
	vuelta_int = pagado_int - total_int; //	Céntimos -totales- a devolver  	
	euros_vuelta = vuelta_int / 100;     // Euros a devolver
	centimos_vuelta = vuelta_int % 100;  // Céntimos a devolver

	// Valor de las monedas devueltas
	double valor_2E, valor_1E, valor_50ct, valor_20ct, valor_10ct, 
	       valor_5ct, valor_2ct, valor_1ct;
	// Valor total de las monedas devueltas
	double valor_vuelta_calculado = 0.0;    
	
	// Monedas de 2E y 1E
	
	monedas_2e = euros_vuelta / 2;   // Num. monedas de 2E
	valor_2E = monedas_2e*2.0; 
	valor_vuelta_calculado += valor_2E;
	
	monedas_1e = euros_vuelta % 2;   // Num. monedas de 1E
	valor_1E = monedas_1e*1.0; 
	valor_vuelta_calculado += valor_1E;

	// Monedas de céntimos
	
	// Céntimos pendientes de distribuir en monedas de céntimos	
	int centimos_vuelta_quedan = centimos_vuelta;

	monedas_50ct = centimos_vuelta_quedan / 50; // Monedas de 50ct 
	centimos_vuelta_quedan -= monedas_50ct*50;
	valor_50ct = monedas_50ct*0.5; // Valor de las modedas de 50ct
	valor_vuelta_calculado += valor_50ct;

	monedas_20ct = centimos_vuelta_quedan / 20; // Monedas de 20ct 
	centimos_vuelta_quedan -= monedas_20ct*20;
	valor_20ct = monedas_20ct*0.2; // Valor de las modedas de 20ct
	valor_vuelta_calculado += valor_20ct;
	
	monedas_10ct = centimos_vuelta_quedan / 10; // Monedas de 10ct 
	centimos_vuelta_quedan -= monedas_10ct*10;
	valor_10ct = monedas_10ct*0.1;  // Valor de las modedas de 10ct
	valor_vuelta_calculado += valor_10ct;
	
	monedas_5ct = centimos_vuelta_quedan / 5; // Monedas de 5ct 
	centimos_vuelta_quedan -= monedas_5ct*5;
	valor_5ct = monedas_5ct*0.05;  // Valor de las modedas de 5ct
	valor_vuelta_calculado += valor_5ct;
			
	monedas_2ct = centimos_vuelta_quedan / 2; // Monedas de 2ct 
	centimos_vuelta_quedan -= monedas_2ct*2;
	valor_2ct = monedas_2ct*0.02;  // Valor de las modedas de 2ct
	valor_vuelta_calculado += valor_2ct;
	
	monedas_1ct = centimos_vuelta_quedan; // Monedas de 1ct 
	valor_1ct = monedas_1ct*0.01;  // Valor de las modedas de 1ct
	valor_vuelta_calculado += valor_1ct;
	
	// Salidas
		
	cout << endl; 		
	cout << "---------------------------------------" << endl; 			
	cout << "Total a pagar = " << setw(7) << setprecision(2) 
	     << total << " E " << endl;   
	cout << "Pagado ...... = " << setw(7) << setprecision(2) 
	     << pagado << " E " << endl;     
	cout << endl; 
	cout << "Vuelta (euros) .. = " << setw(3) << euros_vuelta 
	     << " E"<< endl;   
	cout << "Vuelta (centimos) = " << setw(3) << centimos_vuelta 
	     << " ct"<< endl;  
	cout << endl; 
	
	cout << "Monedas   2E = " << setw(2) << monedas_2e;   
	cout << " --> " << setw(2) << monedas_2e << " x 2E   = " << setw(7) 
	     << setprecision(2) << valor_2E << " E " << endl; 
		  
	cout << "Monedas   1E = " << setw(2) << monedas_1e;   
	cout << " --> " << setw(2) << monedas_1e << " x 1E   = " << setw(7) 
	     << setprecision(2) << valor_1E << " E " << endl;   
	
	cout << "Monedas 50ct = " << setw(2) << monedas_50ct;   
	cout << " --> " << setw(2) << monedas_50ct << " x 50ct = " << setw(7) 
	     << setprecision(2) << valor_50ct << " E " << endl;   
		 	
	cout << "Monedas 20ct = " << setw(2) << monedas_20ct;   
	cout << " --> " << setw(2) << monedas_20ct << " x 20ct = " << setw(7) 
	     << setprecision(2) << valor_20ct << " E " << endl; 
		  	
	cout << "Monedas 10ct = " << setw(2) << monedas_10ct;
	cout << " --> " << setw(2) << monedas_10ct << " x 10ct = " << setw(7) 
	     << setprecision(2) << valor_10ct << " E " << endl; 
		  	   
	cout << "Monedas  5ct = " << setw(2) << monedas_5ct;
	cout << " --> " << setw(2) << monedas_5ct << " x 5ct  = " << setw(7) 
	     << setprecision(2) << valor_5ct << " E " << endl; 
		  	   
	cout << "Monedas  2ct = " << setw(2) << monedas_2ct;
	cout << " --> " << setw(2) << monedas_2ct << " x 2ct  = " << setw(7) 
	     << setprecision(2) << valor_2ct << " E " << endl; 
		  	   
	cout << "Monedas  1ct = " << setw(2) << monedas_1ct;
	cout << " --> " << setw(2) << monedas_1ct << " x 1ct  = " << setw(7) 
	     << setprecision(2) << valor_1ct << " E " << endl; 
		  	
	cout << setw(35) << " " << "--------" << endl;
	cout << setw(34) << " " << setw(7) << setprecision(2) 
	     << valor_vuelta_calculado << " E " << endl;
			  	      
	cout << endl;
	
	return 0;
}
