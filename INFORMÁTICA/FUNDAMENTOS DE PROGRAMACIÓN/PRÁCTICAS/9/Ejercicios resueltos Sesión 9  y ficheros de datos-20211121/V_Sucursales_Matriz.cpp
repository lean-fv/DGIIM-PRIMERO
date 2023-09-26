/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Matrices)
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
		
	Ahora queremos almacenar en memoria no sólo las ventas totales de cada 
	sucursal, sino la información referente a los productos vendidos. 
	En definitiva:
		* Total de unidades vendidas de cada producto.
		* Producto más vendido. 
		* Cuántos tipos de producto han sido vendidos (número de tipos de 
		  producto con unidades vendidas mayores que cero).
		* Número total de unidades vendidas entre todas las sucursales. 
	
	Para poder guardar en memoria la información requerida para los cálculos 
	se usará la matriz "bidimensional" que tendrá tantas filas como número 
	(máximo) de sucursales y tantas columnas como número (máximo) de 
	productos. 	
	
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
	
	// Todas las ventas se registran en la matriz "ventas"
	// Las ventas de la sucursal i [int] se guardarán en la fila i-1
	// Las ventas del producto 'j' [char] se guardarán en la columna 'j'-'a'
	
	int ventas[MAX_SUCURSALES_EMPRESA][NUM_PRODUCTOS];
	

	// Iniciar los contadores

	for (int sucursal=0; sucursal<MAX_SUCURSALES_EMPRESA; sucursal++)
	
		for (int producto=0; producto<NUM_PRODUCTOS; producto++)

			ventas[sucursal][producto] = 0;


	// Para la lectura de los datos se necesitan tres variables:

	int  sucursal;	// Num. de sucursal
	char producto;	// Cód. de producto
	int  unidades;	// Unidades vendidas

	// La lectura debe interrumpirse cuando el número de sucursal 
	// sea -1, por eso debe leerse de forma anticipada y ser ésta 
	// la condición del ciclo while

	int contador_operaciones = 0; // Número de operaciones de venta
	
	cin >> sucursal;         

	while (sucursal != TERMINADOR) {

		// Si se ha entrado al ciclo, procesar esta venta

		cin >> producto; 
		cin >> unidades; 

		contador_operaciones++;
		
		ventas[sucursal-1][producto-'a'] += unidades;
		
		cin >> sucursal;  // Preparando una nueva iteración
	}

	if (contador_operaciones > 0) {
		
		
		// Mostrar número de operaciones de ventas

		cout << endl;
		cout << "Num.operaciones de ventas = "
			 << setw (4) << contador_operaciones<< endl;
		cout << endl;
			 
		//...................................................................
		// CALCULOS POR SUCURSALES
		
		// Calcular ventas por sucursal
		
		int ventas_sucursal[MAX_SUCURSALES_EMPRESA] = {0};
		

		for (int sucursal=0; sucursal<MAX_SUCURSALES_EMPRESA; sucursal++)

			for (int producto=0; producto<NUM_PRODUCTOS; producto++)

				ventas_sucursal [sucursal] += ventas[sucursal][producto];


		// Calcular sucursal con más ventas
		
		// El primer máximo será el de la primera sucursal
		
		int maximo = ventas_sucursal[0]; // ventas de la sucursal 1
		int sucursal_maximo = 1;

		for (int sucursal=2; sucursal<=MAX_SUCURSALES_EMPRESA; sucursal++) {
			
			int ventas_sucursal_actual = ventas_sucursal[sucursal-1];
			
			if (ventas_sucursal_actual > maximo) {
				maximo = ventas_sucursal_actual;
				sucursal_maximo = sucursal;
			}
			
		} // for sucursal

		cout << endl;
		cout << "La sucursal con mas ventas es: " << endl;
		cout << "\tSUCURSAL: " << sucursal_maximo << endl;
		cout << "\tVENTAS:   " << maximo << endl;
		cout << endl << endl;


		// Listado de ventas por sucursal

		cout << "Ventas por sucursal: " << endl;

		for (int sucursal=1; sucursal<=MAX_SUCURSALES_EMPRESA; sucursal++) {

			int ventas_sucursal_actual = ventas_sucursal[sucursal-1];

			if (ventas_sucursal_actual > 0) {
				cout << "\tSUCURSAL: " << setw(3) << sucursal << " VENTAS: "
				     << setw(5) << ventas_sucursal_actual << endl;
			}
		}
		cout << endl;

			 
		// Cálculo del número de sucursales con ventas

		int num_sucursales_con_ventas = 0;
		
		for (int sucursal=1; sucursal<=MAX_SUCURSALES_EMPRESA; sucursal++)
			if (ventas_sucursal[sucursal-1] > 0)
				num_sucursales_con_ventas++;
		
		cout << "Num.sucursales con ventas = "
			 << setw (4) <<num_sucursales_con_ventas << endl;
			 
		// Cálculo del número total de ventas

		int cantidad_total_ventas = 0;

		for (int sucursal=1; sucursal<=MAX_SUCURSALES_EMPRESA; sucursal++)
				cantidad_total_ventas += ventas_sucursal[sucursal-1];
			 
		cout << "Cantidad total ventas =     "
			 << setw (4) << cantidad_total_ventas << endl;

		//...................................................................
		// CALCULOS POR PRODUCTOS
		
		// Calcular ventas por producto

		int ventas_producto[NUM_PRODUCTOS] = {0};

		for (int producto=0; producto<NUM_PRODUCTOS; producto++)

			for (int sucursal=0; sucursal<MAX_SUCURSALES_EMPRESA; sucursal++)

				ventas_producto [producto] += ventas[sucursal][producto];


		// Calcular producto más vendido

		// El primer máximo será el de la primera sucursal

		int maximo_unidades = ventas_producto[0]; // ventas del producto 'a'
		char producto_maximo = 'a';

		for (char producto='b'; producto<=MAX_PRODUCTO; producto++) {

			int ventas_producto_actual = ventas_producto[producto-'a'];

			if (ventas_producto_actual > maximo_unidades) {
				maximo_unidades = ventas_producto_actual;
				producto_maximo = producto;
			}

		} // for sucursal

		cout << endl;
		cout << "El producto mas vendido es: " << endl;
		cout << "\tPRODUCTO: " << producto_maximo << endl;
		cout << "\tVENTAS:   " << maximo_unidades << endl;
		cout << endl << endl;
		

		// Listado de ventas por producto

		cout << "Ventas por producto: " << endl;

		for (char producto='a'; producto<=MAX_PRODUCTO; producto++) {

			int ventas_producto_actual = ventas_producto[producto-'a'];

			if (ventas_producto_actual > 0) {
				cout << "\tPRODUCTO: " << setw(3) << producto << " VENTAS: "
				     << setw(5) << ventas_producto_actual << endl;
			}
		}
		cout << endl;


		// Cálculo del número de productos con ventas

		int num_productos_con_ventas = 0;

		for (char producto='a'; producto<=MAX_PRODUCTO; producto++)
			if (ventas_producto[producto-'a'] > 0)
				num_productos_con_ventas++;

		cout << "Num.productos con ventas =  "
			 << setw (4) <<num_productos_con_ventas << endl;

		// Cálculo del número total de ventas

		int cantidad_total_ventas_prod = 0;

		for (char producto='a'; producto<=MAX_PRODUCTO; producto++)
				cantidad_total_ventas_prod += ventas_producto[producto-'a'];

		cout << "Cantidad total ventas =     "
			 << setw (4) << cantidad_total_ventas_prod << endl;
		cout << endl;

		//...................................................................
		// PRESENTACION GLOBAL DE DATOS LEIDOS
		
		// Línea con etiquetas de producto
		cout << "   ";
		for (char producto='a'; producto<=MAX_PRODUCTO; producto++)
			if (ventas_producto[producto-'a'] > 0)
				cout << setw (5) << producto;
		cout << endl << endl;
			
		// Por cada sucursal
		for (int sucursal=1; sucursal<=MAX_SUCURSALES_EMPRESA; sucursal++) {

			if (ventas_sucursal [sucursal-1] > 0 ) {
				
				cout << setw(3) << sucursal;

				for (char producto='a'; producto<=MAX_PRODUCTO; producto++) {
					
					if (ventas_producto[producto-'a'] > 0)

						cout << setw(5) <<  ventas[sucursal-1][producto-'a'];

				} // for producto
				
				cout << "  --> " << setw (4) << ventas_sucursal [sucursal-1];

				cout << endl;
			}
			
		} // for sucursal
		
		cout << endl;
		
		
		cout << "   ";

		for (char producto='a'; producto<=MAX_PRODUCTO; producto++) {

			if (ventas_producto[producto-'a'] > 0)
		
				cout << setw(5) <<  ventas_producto[producto-'a'];
		}

		cout << "     " << setw(5) << cantidad_total_ventas_prod << endl;
		
	} // if (contador_operaciones > 0)

	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/
