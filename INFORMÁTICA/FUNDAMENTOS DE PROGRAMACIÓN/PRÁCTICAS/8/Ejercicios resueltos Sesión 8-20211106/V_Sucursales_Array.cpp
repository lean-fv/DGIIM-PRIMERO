/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Arrays)
//
/*	
	Una empresa que tiene varias sucursales decide llevar la contabilidad
	de las ventas de sus productos a lo largo de una semana. 
	Para ello registra cada venta con tres datos: el identificador de 
	la sucursal (int), el código del producto (char) y el número
	de unidades vendidas (int). 
	* La empresa dispone de 100 sucursales. No todas las sucursales tienen 
	  ventas, y una sucursal puede tener más de una operación de venta. 
	* Los códigos de los productos son caracteres entre 'a' y 'j'. 
	
	El programa debe leer un número indeterminado de datos de ventas 
	(código de sucursal, código de producto y número de unidades vendidas).
	No se sabe, a priori, el número de operaciones de venta. La serie de 
	datos de venta termina cuando en la lectura del número de sucursal se 
	introduce -1. 
	
	Entradas: Una serie de tripletas (sucursal, producto, unidades) 
			  La serie de datos termina cuando la sucursal 
			  introducida vale -1. 
	Salidas:  1) Para cada sucursal con venta, su número total de ventas.
			  2) La sucursal con más ventas.
			  3) Número total de operaciones de venta, número de sucursales 
			     con ventas y número total de unidades vendidas.   
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	const int  MAX_SUCURSALES_EMPRESA = 100;	// Num. máximo de sucursales
	
	const char MIN_PRODUCTO = 'a';	// Cod. mínimo de producto
	const char MAX_PRODUCTO = 'j';	// Cod. máximo de producto
	const int  NUM_PRODUCTOS = MAX_PRODUCTO-MIN_PRODUCTO+1; // Num. productos 

	const int TERMINADOR = -1;  			// Terminador de lectura
	
	// Todas las ventas se registran en el array "ventas_sucursal"
	// Las ventas de la sucursal i [int] se guardarán en la casilla i-1
	
	int ventas_sucursal[MAX_SUCURSALES_EMPRESA];
	
	// Iniciar los contadores

	for (int num=0; num<MAX_SUCURSALES_EMPRESA; num++)
	
		ventas_sucursal[num] = 0;


	// Para la lectura de los datos se necesitan tres variables:

	int  num_sucursal;	// Num. de sucursal
	char producto;	// Cód. de producto
	int  unidades;	// Unidades vendidas

	// La lectura debe interrumpirse cuando el número de sucursal 
	// sea -1, por eso debe leerse de forma anticipada y ser ésta 
	// la condición del ciclo while

	int contador_operaciones = 0; // Número de operaciones de venta
	
	cin >> num_sucursal;         

	while (num_sucursal != TERMINADOR) {

		// Si se ha entrado al ciclo, procesar esta venta

		cin >> producto; 
		cin >> unidades; 

		contador_operaciones++;
		
		ventas_sucursal[num_sucursal-1] += unidades;
		
		cin >> num_sucursal;  // Preparando una nueva iteración
	}

	if (contador_operaciones > 0) {
		
		
		// Mostrar número de operaciones de ventas

		cout << endl;
		cout << "Num.operaciones de ventas = "
			 << setw (4) << contador_operaciones<< endl;
		cout << endl;
			 
			 
		// Calcular sucursal con más ventas
		
		// El primer máximo será el de la primera sucursal
		
		int maximo = ventas_sucursal[0]; // ventas de la sucursal 1
		int sucursal_maximo = 1;

		for (int num=2; num<=MAX_SUCURSALES_EMPRESA; num++) {
			
			int ventas_sucursal_actual = ventas_sucursal[num-1];
			
			if (ventas_sucursal_actual > maximo) {
				maximo = ventas_sucursal_actual;
				sucursal_maximo = num;
			}
			
		} // for sucursal

		cout << endl;
		cout << "La sucursal con mas ventas es: " << endl;
		cout << "\tSUCURSAL: " << sucursal_maximo << endl;
		cout << "\tVENTAS:   " << maximo << endl;
		cout << endl << endl;


		// Listado de ventas por sucursal

		cout << "Ventas por sucursal: " << endl;

		for (int num=1; num<=MAX_SUCURSALES_EMPRESA; num++) {

			int ventas_sucursal_actual = ventas_sucursal[num-1];

			if (ventas_sucursal_actual > 0) {
				cout << "\tSUCURSAL: " << setw(3) << num << " VENTAS: "
				     << setw(5) << ventas_sucursal_actual << endl;
			}
		}
		cout << endl;

			 
		// Cálculo del número de sucursales con ventas

		int num_sucursales_con_ventas = 0;
		
		for (int c=0; c<MAX_SUCURSALES_EMPRESA; c++)
			if (ventas_sucursal[c] > 0)
				num_sucursales_con_ventas++;
		
		cout << "Num.sucursales con ventas = "
			 << setw (4) <<num_sucursales_con_ventas << endl;
			 
		// Cálculo del número total de ventas

		int cantidad_total_ventas = 0;

		for (int num=1; num<=MAX_SUCURSALES_EMPRESA; num++)
				cantidad_total_ventas += ventas_sucursal[num-1];
			 
		cout << "Cantidad total ventas =     "
			 << setw (4) << cantidad_total_ventas << endl;

	} // if (contador_operaciones > 0)

	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
