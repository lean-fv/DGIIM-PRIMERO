
/***************************************************************************/
/***************************************************************************/

int main()
{	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales	
	
	
	// Lectura de un entero arbitrario

	Lector lector_temp("Temperatura (sin decimales): "); 
	
	int temp = lector_temp.LeeEntero();
	
	cout << endl;
	cout << "Temperatura leida = " << temp << endl;
	cout << endl;


	// Lectura de enteros acotados superior e inferiormente 
	
	int hora, minuto, segundo;
	
	Lector lector_hora; 
	
	lector_hora.SetTitulo ("Introduzca hora: "); 	
	hora = lector_hora.LeeEnteroEnRango (0, 23);
	
	lector_hora.SetTitulo ("Introduzca minuto: "); 		
	minuto = lector_hora.LeeEnteroEnRango (0, 59);
	
	lector_hora.SetTitulo ("Introduzca segundo: "); 		
	segundo = lector_hora.LeeEnteroEnRango (0, 59);

	cout << endl;
	cout << "Hora: " << hora << ":" << minuto << ":" << segundo << endl;
	cout << endl << endl;
		
		
	// Lectura de un entero acotado inferiormente 
	
	int ingreso;
	
	Lector lector_ingreso("Cantidad a ingresar: "); 

	ingreso = lector_ingreso.LeeEnteroMayorOIgual (0);
	
	cout << endl;
	cout << "Valor del ingreso = " << ingreso << endl;
	cout << endl << endl;
	
	
	// Lectura de un valor real arbitrario 
	
	double temperatura;
	
	Lector lector_temperatura("Temperatura (con decimales): "); 

	temperatura = lector_temperatura.LeeReal ();
	
	cout << endl;
	cout << "Valor de la temperatura = " 
	     << setw(6) << setprecision(2) << temperatura << endl;
	cout << endl << endl;
	
	
	// Lectura de un real acotado superior e inferiormente 
	
	Lector lector_iva ("Introduzca IVA -entre 4.0 y 21.0-: "); 	 
	
	double iva = lector_iva.LeeRealEnRango (4.0, 21.0);
	
	cout << endl;
	cout << "Valor del IVA = " << setw(5) << setprecision(2) << iva << endl;
	cout << endl << endl;
	
	
	// Lectura de un real acotado superior e inferiormente 
	
	lector_iva.SetTitulo("Introduzca IVA (>=4.0): "); 	 

	iva = lector_iva.LeeRealMayorOIgual (4.0);
	
	cout << endl;
	cout << "Valor del IVA = " << setw(5) << setprecision(2) << iva << endl;
	cout << endl << endl;
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
