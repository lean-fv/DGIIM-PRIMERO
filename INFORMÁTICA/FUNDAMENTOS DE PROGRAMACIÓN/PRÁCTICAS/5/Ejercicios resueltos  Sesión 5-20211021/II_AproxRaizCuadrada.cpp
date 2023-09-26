/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	
	Se implementan dos aproximaciones para el cálculo de la raiz cuadrada:
	
	1) 	En primer lugar, el método descrito en 
			https://www.youtube.com/watch?v=sOSdi9z8S6E

	2) 	El segundo método está basado en la proporcionalidad entre triángulos. 
		Se trata de aproximar la función  y=sqrt(x) por rectas entre los tramos 
		determinados por los valores con raices exactas. 
		
		Se unen los puntos (x,sqrt(x)) que verifican que x tiene raiz exacta.
		Si tomamos un segmento cualquiera en el eje x entre dos valores con 
		raiz cuadrada exacta se observa una región triangular bien delimitada. 
		Por ejemplo, entre x=1 y x=4 consideramos el triángulo delimitado por 
		los puntos (1,sqrt(1)), (4,sqrt(1)) y (4,sqrt(4)). El triángulo 
		delimitado por (1,sqrt(1)), (3.5,sqrt(1)) y (3.5,sqrt(3.5)) es 
		equivalente al delimitado por los puntos   (1,sqrt(1)), (4,sqrt(1)) 
		y(4,sqrt(4)). 
	
	Finalmente se muestra una tabla comparativa en la que se muestran los 
	valores estimados por los dos métodos y por la función sqrt para valores 
	de x desde 0 a 16, con saltos de 0.5. ¿Puede extraer alguna conclusión 
	de esta tabla? ¿Puede proponer un método de estimación mejor -más ajustado 
	al "verdadero" valor- que los dos implementados?
*/
/***************************************************************************/

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std; 

int main (void)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);		
	
	double valor;
	
	do {
		cout << "Introduzca radicando: ";
		cin >> valor; 
	} while (valor < 0);
	
	
	// Método 1 (https://www.youtube.com/watch?v=sOSdi9z8S6E) 
	
	double raiz1; 
	
	if (valor==0) raiz1 = 0.0; 
	else {
		
		// Buscar las raices exactas más cercanas, superior e inferior 
		long raiz_sup = 0; // raiz exacta superior a "valor"
		long raiz_inf = 0; // raiz exacta inferior a "valor"
		 	 
		while (raiz_sup*raiz_sup <= valor) {
			raiz_inf = raiz_sup;
			raiz_sup++; 
		}
		
		long valor_sup = raiz_sup*raiz_sup;
		long valor_inf = raiz_inf*raiz_inf;
		
		// Ahora, valor_inf <= valor <= valor_sup
		
		/*
		cout << endl; 	
		cout << valor_inf << " <= "  << valor << " <= " << valor_sup << endl;  
		cout << endl; 	
		*/
		
		long raiz_mas_cercana, valor_mas_cercano;
		
		long dif_sup = fabs(valor_sup-valor);
		long dif_inf = fabs(valor-valor_inf);
		
		if (dif_sup<=dif_inf) {
			valor_mas_cercano = valor_sup;
			raiz_mas_cercana  = raiz_sup;
		}
		else {
			valor_mas_cercano = valor_inf;
			raiz_mas_cercana  = raiz_inf;
		}
		
		double dif = valor_mas_cercano-valor; 
		
		/*
		cout << "dif =  " << dif << " Valor mas cercano = " 
		     << valor_mas_cercano << endl;  
		cout << endl; 	
		*/		
		
		double parte_entera  = raiz_mas_cercana;
		double parte_decimal = dif/(2.0*raiz_mas_cercana); 
		
		/*
		cout << "parte_entera  =  " << parte_entera << endl;  
		cout << "parte_decimal =  " << parte_decimal << endl;  
		*/
		
		raiz1 =  parte_entera - parte_decimal; 
	}

	
	// Método 2 (Interpolacion) 
	
	// Buscar las raices exactas más cercanas, superior e inferior 
	// Nos interesa la inferior 
	
	long la_raiz_sup = 0; // raiz exacta superior a "valor"
	long la_raiz_inf = 0; // raiz exacta inferior a "valor"
	 
	while (la_raiz_sup*la_raiz_sup <= valor) {
		la_raiz_inf = la_raiz_sup;
		la_raiz_sup++; 
	}

	long el_valor_sup = la_raiz_sup*la_raiz_sup;
	long el_valor_inf = la_raiz_inf*la_raiz_inf;
	
	// Ahora, el_valor_inf <= valor <= el_valor_sup
	/*
	cout << endl; 	
	cout << el_valor_inf << " <= "  << valor << " <= " << el_valor_sup << endl;  
	cout << endl; 	
	*/
	
	double numerador   = (valor-el_valor_inf) * (la_raiz_sup-la_raiz_inf);
	double denominador = el_valor_sup-el_valor_inf;
	
	double raiz2 = la_raiz_inf + numerador/denominador; 

	// Resultados 
	
	cout << endl; 	
	cout << "La raiz aproximada (1) es =  " << setw(8) << setprecision(4) 
	     << raiz1 << endl;  
	cout << "La raiz aproximada (2) es =  " << setw(8) << setprecision(4) 
	     << raiz2 << endl;  
	cout << endl; 	
	cout << "La raiz -sqrt- es =  " << setw(15) << setprecision(8) 
	     << sqrt(valor) << endl;  
	cout << endl; 	
	
	
	// Tabla comparativa
	
	const double INIC  =  0.0; 
	const double FIN   = 100.0; 
	const double SALTO =  0.5; 
		
	cout << endl; 	
	cout << "  x       " << "RAIZ 2  " 
	     //<< "DIF 2   " 
		 << "SQRT    " 
	     //<< "DIF 1   " 
		 << "RAIZ 1" << " | " << "  SQRT    " << "MEDIA   " 
		 //<< "DIF M   " 
		 << endl; 	
	cout << endl; 	

	for (double valor=INIC; valor<=FIN; valor+=SALTO) {
			
		// MÉTODO 1	
			
		double raiz1; 
		
		if (valor==0) raiz1 = 0.0; 
		else {
			
			// Buscar las raices exactas más cercanas, superior e inferior 
			long raiz_sup = 0; // raiz exacta superior a "valor"
			long raiz_inf = 0; // raiz exacta inferior a "valor"
			 	 
			while (raiz_sup*raiz_sup <= valor) {
				raiz_inf = raiz_sup;
				raiz_sup++; 
			}
			
			long valor_sup = raiz_sup*raiz_sup;
			long valor_inf = raiz_inf*raiz_inf;
			
			// Ahora, valor_inf <= valor <= valor_sup
			
			long raiz_mas_cercana, valor_mas_cercano;
			
			long dif_sup = fabs(valor_sup-valor);
			long dif_inf = fabs(valor-valor_inf);
			
			if (dif_sup<=dif_inf) {
				valor_mas_cercano = valor_sup;
				raiz_mas_cercana  = raiz_sup;
			}
			else {
				valor_mas_cercano = valor_inf;
				raiz_mas_cercana  = raiz_inf;
			}
			
			double dif = valor_mas_cercano-valor; 
			
			double parte_entera  = raiz_mas_cercana;
			double parte_decimal = dif/(2.0*raiz_mas_cercana); 
			
			/*
			cout << "parte_entera  =  " << parte_entera << endl;  
			cout << "parte_decimal =  " << parte_decimal << endl;  
			*/
			
		 	raiz1 =  parte_entera - parte_decimal; 
		}
	
		// MÉTODO 2	
		
		double raiz2; 
		
		// Buscar las raices exactas más cercanas, superior e inferior 
		// Nos interesa la inferior 
		
		long la_raiz_sup = 0; // raiz exacta superior a "valor"
		long la_raiz_inf = 0; // raiz exacta inferior a "valor"
		 
		while (la_raiz_sup*la_raiz_sup <= valor) {
			la_raiz_inf = la_raiz_sup;
			la_raiz_sup++; 
		}
	
		long el_valor_sup = la_raiz_sup*la_raiz_sup;
		long el_valor_inf = la_raiz_inf*la_raiz_inf;
		
		// Ahora, el_valor_inf <= valor <= el_valor_sup
		
		double numerador   = (valor-el_valor_inf) * (la_raiz_sup-la_raiz_inf);
		double denominador = el_valor_sup-el_valor_inf;
		
		raiz2 = la_raiz_inf + numerador/denominador; 
		

		// FUNCION sqrt
		
		double raiz_sqrt = sqrt(valor);
		
		// MEDIA de raiz1 y raiz2
		
		double raiz_media = 0.5*(raiz1+raiz2);
		
		 			
		// Mostrar linea de resultados para "valor"
		
		cout << setw(8) << setprecision(4) << valor; 	
		cout << setw(8) << setprecision(4) << raiz2; 
		//cout << setw(8) << setprecision(4) << fabs(raiz2-raiz_sqrt); 
		cout << setw(8) << setprecision(4) << raiz_sqrt;
		//cout << setw(8) << setprecision(4) << fabs(raiz1-raiz_sqrt); 		
		cout << setw(8) << setprecision(4) << raiz1; 
		cout << " | ";
		cout << setw(8) << setprecision(4) << raiz_sqrt;
		cout << setw(8) << setprecision(4) << raiz_media;
		//cout << setw(8) << setprecision(4) << fabs(raiz_media-raiz_sqrt); 		
		cout << endl; 	
	}
	
	cout << endl; 	
	
	return 0; 	
} 
