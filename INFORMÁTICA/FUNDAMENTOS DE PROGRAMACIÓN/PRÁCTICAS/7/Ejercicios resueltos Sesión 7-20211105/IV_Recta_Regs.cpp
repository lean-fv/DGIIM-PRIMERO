/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
/*	
	Una recta r viene determinada por tres coeficientes A, B, C, de forma 
	que todos los puntos (x, y) del plano que pertenecen a la recta verifican:
		r : Ax + By + C = 0 (ecuación general)
	
	Es más frecuente utilizar la ecuación explícita de la recta, en la que 
	se expresa la abscisa en función de la pendiente de la recta (m) y de 
	la ordenada en origen (n):
		r : y = mx + n  (ecuación explícita)
	de manera que m = -A/B y n = -C/B
	
	Este programa realiza las mismas tareas que el ejercicio 20 de la 
	Relación de Problemas 3 pero incorporando los tipos de datos
	
		struct Punto2D {
			double x, y; // abscisa y ordenada de un punto
		};
		struct Recta {
			double A, B, C; // coeficientes de la recta
		};
		
	NOVEDADES: 
		* función que devuelve el punto de corte entre dos rectas secantes. 
		* función que indica si un punto pertenece a una recta.
		* En la función main se lee un número indeterminado de puntos y nos 
	  	  dice si forman parte de la primera recta (finaliza cuando se 
		  escriba FIN al leer el valor de la coordenada x).					
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/
// Constantes
/***************************************************************************/
	
const double UMBRAL_IGUALES = 0.00000001;
const int TAM_CAD = 100;
		
/***************************************************************************/
// Tipos de datos usados en este programa
/***************************************************************************/

// Punto en un plano

struct Punto2D {
	double x, y; // abscisa y ordenada de un punto
};


// Recta en un plano
// r: Ax + By + C = 0
// PRE: A y B no pueden ser ambos 0 

struct Recta {
	double A, B, C; // coeficientes de la recta
};

		
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Calcula la ordenada "y" dada la abscisa "x" para la recta Ax+By+C=0
// Recibe: r, struct con los parámetros de la recta.
//         x, valor de la abscisa.
// PRE: r.B != 0
/***************************************************************************/

double Ordenada (double x, Recta r)
{
	return ((-r.A*x - r.C) / r.B);
}

/***************************************************************************/
// Calcula la abscisa "x" dada la ordenada "y" para la recta Ax+By+C=0
// Recibe: r, struct con los parámetros de la recta.
//         y, valor de la ordenada.
// PRE: r.A != 0
/***************************************************************************/

double Abscisa  (double y, Recta r)
{
	return ((-r.B*y - r.C) / r.A);	
}
	
/***************************************************************************/
// Devuelve la pendiente de la recta (m = -A/B)
// Recibe: r, struct con los parámetros de la recta.
// PRE: r.B != 0
/***************************************************************************/

double Pendiente (Recta r)
{
	return (-r.A/r.B);
}
		
/***************************************************************************/
// Devuelve la ordenada en origen de la recta (n = -C/B)
// Recibe: r, struct con los parámetros de la recta.
// PRE: r.B != 0
/***************************************************************************/

double OrdenadaEnOrigen (Recta r)
{
	return (-r.C/r.B);	
}

/***************************************************************************/
// Devuelve un string con la expresión de la ecuación explicita
// Recibe: r, struct con los parámetros de la recta.
// Devuelve: un string con la ecuación explícita de la recta.
// PRE: r.B != 0
/***************************************************************************/

string ToStringEcuacionExplicita (Recta r)
{
	double m = Pendiente (r);
	double n = OrdenadaEnOrigen (r);	
	
	string explicita;
	
	explicita = "y = ";
	
	if (m!=0) explicita = explicita + to_string (m) + " x ";	
	
	if (n != 0) {
		
		if (n>0) explicita = explicita + " +";
		else     explicita = explicita + " -";
		
		explicita = explicita + to_string (fabs(n));	
	}
	
	return (explicita);
}
			
/***************************************************************************/
// Calcula si dos rectas son coincidentes.
// Recibe: r1, struct con los parámetros de una recta.
//         r2, struct con los parámetros de otra recta.
// Devuelve: "true" si las rectas son coincidentes.
//
// PRE: r1.A != 0,  r2.B != r2.0, r3.C != 0
/***************************************************************************/

bool SonCoincidentes (Recta r1, Recta r2)
{
	double razon = r1.A/r2.A;
	return ((razon == r1.B/r2.B) && (razon==r1.C/r2.C));
}
					 			
/***************************************************************************/
// Calcula si dos rectas son paralelas.
// Recibe: r1, struct con los parámetros de una recta.
//         r2, struct con los parámetros de otra recta.
// Devuelve: "true" si las rectas son paralelas.
//
// PRE: r1.A != 0,  r2.B != r2.0, r3.C != 0
/***************************************************************************/

bool SonParalelas    (Recta r1, Recta r2)		
{
	double razon = r1.A/r2.A;
	return ((razon == r1.B/r2.B) && (razon!= r1.C/r2.C));
}

/***************************************************************************/
// Calcula si dos rectas son secantes.
// Recibe: r1, struct con los parámetros de una recta.
//         r2, struct con los parámetros de otra recta.
// Devuelve: "true" si las rectas son secantes.
//
// PRE: r1.A != 0,  r2.B != r2.0, r3.C != 0
/***************************************************************************/

bool SonSecantes     (Recta r1, Recta r2)
{
	double razon = r1.A/r2.A;
	return (razon != r1.B/r2.B);
}
									  
				
/***************************************************************************/
// Calcula el punto de corte entre dos rectas secantes.
// Recibe: r1, struct con los parámetros de una recta.
//         r2, struct con los parámetros de otra recta.
// Devuelve: interseccion, el punto de intersección entre las dos rectas.
//
// PRE: las rectas r1 y r2 son secantes
/***************************************************************************/

Punto2D PuntoCorte     (Recta r1, Recta r2)
{
	Punto2D interseccion;
	
	interseccion.x = ((r2.C*r1.B)-(r1.C*r2.B)) / ((r1.A*r2.B)-(r2.A*r1.B));
	interseccion.y = ((r2.C*r1.A)-(r1.C*r2.A)) / ((r1.B*r2.A)-(r2.B*r1.A));
	
	return (interseccion);
}
			
/***************************************************************************/
// Comprueba si num1 y num2 son iguales (Si su diferencia es muy pequeña)
// Recibe: num1 y num2, los dos números que se comparan.
// Devuelve: true, si la diferencia entre ellos es muy pequeña.
/***************************************************************************/

bool SonIguales (double num1, double num2)
{
	return (fabs(num1-num2)<UMBRAL_IGUALES);
}	
		
/***************************************************************************/
// Comprueba la pertenencia de un punto a una recta
// Recibe: p, struct con los parámetros de un punto.
//         r, struct con los parámetros de una recta.
// Devuelve: true, si el punmto p pertenece a la recta r
/***************************************************************************/

bool PuntoEnRecta (Punto2D p, Recta r)
{	
	return (SonIguales(r.A*p.x + r.B*p.y + r.C, 0.0));
}	
				
/***************************************************************************/
// Devuelve un string con la expresión textual de un punto 
// Recibe: p, struct con los parámetros de un punto.
// Devuelve: un string con una representación textual de "p"
/***************************************************************************/

string ToString (Punto2D p)
{	
	string cad;
	cad = "[ " + to_string (p.x) + ", " + to_string (p.y) + "]";	
	return (cad);
}	
									  				
/***************************************************************************/											  				
/***************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// EL programa trabaja con dos rectas
	Recta r1, r2;
	
	
	// a) Lectura de los coeficientes de las dos rectas

	cout << endl;	
	cout << "Recta 1: ";

	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> r1.A;
		cout << "\tB: ";
		cin >>  r1.B;
	} while (r1.A==0 && r1.B==0);

	cout << "\tC: ";
	cin >> r1.C;
	
	cout << endl;	
	cout << "Recta 2: ";
	
	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> r2.A;
		cout << "\tB: ";
		cin >> r2.B;
	} while (r2.A==0 && r2.B==0);

	cout << "\tC: ";
	cin >> r2.C;
	
	cout << endl;	


	// b) Mostrar puntos (x,y) por los que pasan las rectas
	
	if (r1.B!=0) {
		cout << endl;	
		cout << "Recta 1. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (double x=-10.0; x<=10.0; x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (x, r1) << ")" << endl;
		}
	}
	else // r1.B==0
		cout << "Recta 1 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-r1.C/r1.A) << endl;
	cout << endl;	
	
	if (r1.A!=0) {
		cout << endl;
		cout << "Recta 1. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
		
		for (double y=-5.0; y<=5.0; y+=0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (y, r1)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else // r1.A==0
		cout << "Recta 1 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-r1.C/r1.B) << endl;
	cout << endl;
		
	if (r2.B!=0) {
		cout << endl;		
		cout << "Recta 2. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (double x=-10.0; x<=10.0; x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (x, r2) << ")" << endl;
		}
	}
	else // r2.B==0
		cout << "Recta 2 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-r2.C/r2.A) << endl;
	cout << endl;

	if (r2.A!=0) {			 	
		cout << endl;
		cout << "Recta 2. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
	
		for (double y=-5.0; y<=5.0; y+=0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (y, r2)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else
		cout << "Recta 2 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-r2.C/r2.B) << endl;
	cout << endl;	
				
					
	// c) Escribir la ecuación explícita de las dos rectas
	
	if (r1.B != 0) {
		/*		
		cout << "Recta 1: " << endl;
		PintaEcuacionExplicita (r1);
		cout << endl;
		*/
		cout << endl;
		cout << "Recta 1: " << ToStringEcuacionExplicita (r1) << endl;
		cout << endl;
	}
	
	if (r2.B != 0) {		
		/*
		cout << endl;
		cout << "Recta 2: " << endl;
		PintaEcuacionExplicita (r2);
		cout << endl;
		*/
		cout << endl;
		cout << "Recta 2: " << ToStringEcuacionExplicita (r2) << endl;
		cout << endl;
	}


	// d) Posición relativa de las dos rectas
	
	cout << endl;
	cout << "Las rectas son ";	
	
	if (SonCoincidentes(r1,r2))
		cout << " COINCIDENTES" << endl; 
	else if (SonParalelas(r1,r2))
		cout << " PARALELAS" << endl; 
	else if (SonSecantes(r1,r2))
		cout << " SECANTES" << endl;	
	cout << endl << endl;


	// PRUEBA DE NUEVAS PRESTACIONES

	// Punto de corte
	
	if (SonSecantes(r1,r2)) {

		Punto2D corte_r1_r2 = PuntoCorte (r1, r2);
		
		cout << endl;
		cout << "El punto de corte de las dos rectas es " 
		     << ToString (corte_r1_r2) << endl;
		cout << endl;
	}

	// Pertenencia a una recta (1)

	Punto2D un_punto = {5.0, 5.0};
	if (PuntoEnRecta(un_punto, r1)) 
		cout << "El punto " << ToString (un_punto) 
		     << " pertenece a la recta r1" << endl; 
	else 
		cout << "El punto " << ToString (un_punto) 
		     << " NO pertenece a la recta r1" << endl; 
	
	Punto2D otro_punto = {5.0, 15.0};
	if (PuntoEnRecta(otro_punto, r2)) 
		cout << "El punto " <<  ToString (otro_punto) 
		     << " pertenece a la recta r2" << endl; 
	else 
		cout << "El punto " <<  ToString (otro_punto) 
		     << " NO pertenece a la recta r2" << endl; 
	
	cout << endl;
	

	// Pertenencia a una recta (2)

	Punto2D p; // Cada uno de los puntos que se comprobarán
	string cadena; // Para leer coordenada (usando un string)

	// Extraer del buffer de entrada el salto de línea, si lo hubiera 
	cin.ignore (TAM_CAD,'\n');


	// Lectura adelantada 
			
	cout << endl;
	cout << "Introduzca coordenada x: ";
	getline (cin, cadena);
	
	while (cadena != "FIN") {
		
		p.x = stod(cadena); // string --> double
		
		cout << "Introduzca coordenada y: ";
		getline (cin, cadena);
		
		p.y = stod (cadena);  // string --> double
		
		if (PuntoEnRecta(p, r1)) 
		cout << "El punto " <<  ToString (p) 
		     << " pertenece a la recta r1" << endl; 
		else 
			cout << "El punto " <<  ToString (p) 
		     << " NO pertenece a la recta r1" << endl; 	
		
		
		if (PuntoEnRecta(p, r2)) 
		cout << "El punto " <<  ToString (p) 
		     << " pertenece a la recta r2" << endl; 
		else 
			cout << "El punto " <<  ToString (p) 
		     << " NO pertenece a la recta r2" << endl; 
		     
		     
		// Nueva lectura 
		
		cout << endl;
		cout << "Introduzca coordenada x: ";
		getline (cin, cadena);
		
	} // while (cadena != "FIN"


	return 0;
}
