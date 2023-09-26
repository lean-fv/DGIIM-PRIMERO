/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
//
/*	 
	Programa que lee  tres enteros desde teclado y nos dice si están
	ordenados (da igual si es de forma ascendente o descendente)
	o no lo están.

	Entradas: los tres valores (int)
	Salidas: Un mensaje indicando si están ordenados o no lo están.
*/
/***************************************************************************/

#include <iostream>
using namespace std;
 
int main()
{
	int num1, num2, num3; // datos de entrada

	// Entrada de datos

	cout << "Introduzca primer valor:  ";
	cin >> num1;
	cout << "Introduzca segundo valor: ";
	cin >> num2;
	cout << "Introduzca tercer valor:  ";
	cin >> num3;
   
   
	// Cálculos

	enum class TipoOrden {Creciente, Decreciente, SinOrden};

	TipoOrden orden;
	
   	if ((num1 <= num2) && (num2 <= num3))
		orden =  TipoOrden::Creciente;
   	else 
	   	if ((num1 >= num2) && (num2 >= num3))
			orden =  TipoOrden::Decreciente;
   		else
			orden =  TipoOrden::SinOrden;


	// Salida de Resultados

	cout << endl;
	cout << "Valor asociado a la etiqueta de ordenacion: " 
	     << (static_cast<int> (orden)) << "   "  
		 << "De otra manera: "<< ((int) orden) << endl;
	cout << endl;
	
	
	switch (orden) {
		
		case (TipoOrden::Creciente) : 
			cout << "Ordenados. Orden creciente.";
			break;
		case (TipoOrden::Decreciente) : 
			cout << "Ordenados. Orden decreciente.";
			break;
		case (TipoOrden::SinOrden) : 
			cout << "No estan ordenados.";
			break;
		/* Este último caso podría haberse escrito:  
		default: 
			cout << "No están ordenados.";
			break;
		*/		
	}
	
	cout << endl;
	
	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	
	// Cálculos (2) 

	enum class TipoOrdenacion {DecEstricto, DecNoEstricto1, DecNoEstricto2, 
	                           CrecEstricto, CrecNoEstricto1, CrecNoEstricto2, 
							   SinOrden1, SinOrden2, Iguales};
	TipoOrdenacion ordenacion;

   	if (num1 > num2) { // (num1 > num2)
   		
   		if (num2 > num3) { // (num1 > num2) && (num2 > num3)
   				
			ordenacion =  TipoOrdenacion::DecEstricto; // 0
   		}
   		else { // !(num2 > num3) --> (num2 < num3) || (num2 == num3)
   			
   			if (num2 < num3) { // (num1 > num2) && (num2 < num3)
   				
				ordenacion =  TipoOrdenacion::SinOrden1; // 6	
			} 
			else { // (num1 > num2) && (num2 == num3)
			
				ordenacion =  TipoOrdenacion::DecNoEstricto1; // 1
			}	
		}
	}   		
	else { // !(num1 > num2) --> (num1 < num2) || (num1 == num2)
				
	   	if (num1 < num2) { // (num1 < num2)
	   		
	   		if (num2 > num3) { // (num1 < num2) && (num2 > num3)
	   				
				ordenacion =  TipoOrdenacion::SinOrden2; // 7
	   		}
	   		else { // !(num2 > num3) --> (num2 < num3) || (num2 == num3)
	   			
	   			if (num2 < num3) { // (num1 < num2) && (num2 < num3)
	   				
					ordenacion =  TipoOrdenacion::CrecEstricto;	// 3	
				} 
				else { // (num1 < num2) && (num2 == num3)
				
					ordenacion =  TipoOrdenacion::CrecNoEstricto1; // 4
				}	
			}
		}  
		else { // (num1 == num2)
				
	   		if (num2 > num3) { // (num1 == num2) && (num2 > num3)
		   				
				ordenacion =  TipoOrdenacion::DecNoEstricto2; // 2
		   	}
		   	else { // !(num2 > num3) --> (num2 < num3) || (num2 == num3)
		   			
		   		if (num2 < num3) { // (num1 == num2) && (num2 < num3)
		   				
					ordenacion =  TipoOrdenacion::CrecNoEstricto2; // 5		
				} 
				else { // (num1 == num2) && (num2 == num3)
					
					ordenacion =  TipoOrdenacion::Iguales; // 8
				}	
			}		
		} 					
	}
   		
	// Salida de Resultados (2) 
	
	cout << endl;
	cout << "Valor asociado a la etiqueta de ordenacion: " 
	     << (static_cast<int> (ordenacion)) << "   "  
		 << "De otra manera: "<< ((int) ordenacion) << endl;
	cout << endl;
	
	int num_ordenacion = ((int) ordenacion); 
	
	bool son_iguales = (ordenacion==TipoOrdenacion::Iguales);
//	bool son_iguales = (num_ordenacion==8);

	bool hay_orden_decreciente = ( (ordenacion==TipoOrdenacion::DecEstricto) || 
					(ordenacion==TipoOrdenacion::DecNoEstricto1) || 
	                (ordenacion==TipoOrdenacion::DecNoEstricto2) ); 
//	bool hay_orden_decreciente = (num_ordenacion < 3);

	bool hay_orden_creciente = ( (ordenacion==TipoOrdenacion::CrecEstricto) || 
					(ordenacion==TipoOrdenacion::CrecNoEstricto1) || 
	                (ordenacion==TipoOrdenacion::CrecNoEstricto2) ); 

//	bool hay_orden_creciente = (num_ordenacion >= 3 && num_ordenacion < 6);

	bool hay_orden_estricto = ( (ordenacion==TipoOrdenacion::DecEstricto) || 
				 (ordenacion==TipoOrdenacion::CrecEstricto) ); 
//	bool hay_orden_estricto = (num_ordenacion%3 == 0);

	bool hay_orden = (hay_orden_decreciente||hay_orden_creciente||son_iguales);
	bool hay_desorden = ( (ordenacion == TipoOrdenacion::SinOrden1) ||  
	                      (ordenacion == TipoOrdenacion::SinOrden2) );
	                      
	bool hay_orden_alternativo = !hay_desorden;
	bool hay_desorden_alternativo = !hay_orden;
	
	cout << endl;
	cout << "Orden: " << (hay_orden ? "SI":"NO") << endl;
	cout << "Orden -otro-: " << (hay_orden_alternativo ? "SI":"NO") << endl;	
	cout << "Desorden: " << (hay_desorden ? "SI":"NO") << endl;
	cout << "Desorden -otro-: "<<(hay_desorden_alternativo ? "SI":"NO")<< endl;	
	cout << endl;	
	cout << "Orden estricto: " << (hay_orden_estricto ? "SI":"NO") << endl;
	cout << "Orden creciente: " << (hay_orden_creciente ? "SI":"NO") << endl;
	cout << "Orden decreciente: " << (hay_orden_decreciente?"SI":"NO") << endl;	
	cout << endl;		
	cout << "Iguales: " << (son_iguales ? "SI" : "NO") << endl;
	cout << endl;		
	
	return 0;
}
