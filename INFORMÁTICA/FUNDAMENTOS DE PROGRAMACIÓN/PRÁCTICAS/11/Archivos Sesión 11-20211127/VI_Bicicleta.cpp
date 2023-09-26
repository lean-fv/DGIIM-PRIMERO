/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// 
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 6
//
/* 
	Se presenta una clase (Bicicleta) para representar la tracción de una 
	bicicleta, es decir, el conjunto de platos (engranaje delantero), cadena 
	y piñones (engranaje trasero).

	El número de platos y piñones se establece por sendas constantes. 
	En cualquier caso, supondremos que ambos engranajes se numeran desde 1, 
	correspondiendo a ese número el plato más pequeño y el piñón más grande.

	La clase proporciona métodos para cambiar de plato y piñón. 
	Los platos avanzan o retroceden de 1 en 1 y los piñones cambian a 
	saltos de uno o de dos. 
	Si ha llegado al límite superior (inferior) y se llama al método para 
	subir (bajar) de plato, la posición no cambia. Lo mismo se aplica al piñón.

	Este programa lee los movimientos realizados e imprime los estados por los
	que pasan los dos engranajes. Cada movimiento se indica con una pareja 
	de caracteres, de manera que el primero indica el tipo de engranaje:
 
		* 'E' indica un plato, 
		* 'P' indica un piñón, 	

	y el segundo, el tipo de movimiento:

		* 'S' se emplea para subir una posición, 
		* 'B' se emplea para bajar una posición, 
		* 'T' se emplea para subir dos posiciones, y 
		* 'C' se emplea para bajar dos posiciones.
			
		NOTA 1: 'T' y 'C' sólo se aplicarán sobre los piñones.
	
		NOTA 2: Se termina cuando se lee 'X' como engranaje. 

	Se presenta la clase mejorada de manera que no permite cambiar la marcha 
	(con el plato o el piñón) cuando haya riesgo de que se rompa la cadena. 
	Este riesgo se produce cuando la marcha a la que queremos cambiar es:
	
		1) Plato igual a 1 y piñón mayor o igual que 5
		2) Plato igual a 2 y piñón o bien igual a 1 o bien igual a 7
		3) Plato igual a 3 y piñón menor o igual que 3
		
		
	Secuencia de prueba: E S P S P S P S P C E S E B E B X
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
 
/////////////////////////////////////////////////////////////////////////////

class Bicicleta {
	
private: 
	
	const int NUM_PLATOS;    // El valor lo establece el constructor
	const int NUM_PINIONES;  // El valor lo establece el constructor
	
	int plato;
	int pinion;
	
public:
	
	/***********************************************************************/
	// Constructor con parámetros 
	// Es el constructor quien establece los valores de las constantes
	
	Bicicleta (int num_platos, int num_piniones) : 
		NUM_PLATOS (num_platos), NUM_PINIONES (num_piniones)
	{
		plato  = 1; // plato inicial
		pinion = 1; // Piñón inicial
	}
 
	/***********************************************************************/
	// Métodos de acceso para lectura
	// Devuelven una copia de los valores de los datos privados
	
	int Getplato (void)
	{
		return (plato);	
	}
	
	int GetPinion (void)
	{
		return (pinion);	
	}
	
	int GetNumplatos (void)
	{
		return (NUM_PLATOS);	
	}
	
	int GetNumPiniones (void)
	{
		return (NUM_PINIONES);	
	}
	
	/***********************************************************************/
	// Métodos que modifican (incrementa/decrementa) el plato actual. 
	// 
	// NOTA: Observe que si no hay más platos (por arriba o por abajo 
	// del actual), no se modifica la posicion. No es escribe como una 
	// precondición ya que si se llama a estos métodos no hay riesgo de 
	// quedar en un estado inválido.
	
	void Subeplato ()
	{
		if (plato < NUM_PLATOS)
			plato++;	
	}
	
	void Bajaplato ()
	{
		if (plato > 1)
			plato--;	
	}

	/***********************************************************************/
	// Métodos que modifican (incrementa/decrementa) el pinón actual.
	// 
	// NOTA: Observe que si no hay más piñones (por arriba o por abajo 
	// del actual), no se modifica la posicion. No es escribe como una 
	// precondición ya que si se llama a estos métodos no hay riesgo de 
	// quedar en un estado inválido.

	void SubePinion ()
	{
		if (pinion < NUM_PINIONES)
			pinion++;	
	}
	
	void BajaPinion ()
	{
		if (pinion > 1)
			pinion--;	
	}

	// Los métodos que modifican en dos posiciones el piñón actal no 
	// requieren nada especial, ya que usan los métodos anteriores. 
	// Si se intenta subir/bajar dos posiciones y sólo se puede una 
	// se sube/baja una posición. 
	
	void SubeDosPiniones ()
	{
		SubePinion();
		SubePinion();		
	}
	
	void BajaDosPiniones ()
	{
		BajaPinion();
		BajaPinion();
	}

	/***********************************************************************/
	// Comprueba si es posible realizar un cambio sin riesgo de que se 
	// rompa la cadena. En caso de que exista el riesgo, devuelve true.
	//
	// Recibe: 	engranaje, el engranaje que se va a modificar
	// 			operacion, la operación que se va a aplicar
	// Devuelve: true, si hay riesgo de rotura (si se cumple alguna 
	// 				de las tres situaciones de riesgo. 
	
	bool RiesgoRoturaCadena (char engranaje, char operacion) 
	{		
		// La variables "nuevo_plato" y "nuevo_pinion" registran los 
		// nuevos engranajes, en el caso de que la operación de cambio 
		// pudiera realizarse con éxito.
		// Sobre estas variables se comprueba la situación de riesgo. 
		int nuevo_plato, nuevo_pinion; 
		
		if (engranaje == 'E') {
		 
			if (operacion == 'S') 
				nuevo_plato = plato+1;	
			else 
				nuevo_plato = plato-1;	

			// Que no "se salga la cadena"
			if (nuevo_plato > NUM_PLATOS)
				nuevo_plato = NUM_PLATOS;
			if (nuevo_plato <= 0) 
				nuevo_plato = 1;
			
			nuevo_pinion = pinion; 
		}
		else { // engranaje == 'P' 
			
			switch (operacion) {
					
				case ('S'): nuevo_pinion = pinion+1;
							break; 
				case ('B'): nuevo_pinion = pinion-1;
							break; 
				case ('T'): nuevo_pinion = pinion+2;
							break; 
				case ('C'): nuevo_pinion = pinion-2;
							break; 
			}
			
			// Que no "se salga la cadena"
			if (nuevo_pinion > NUM_PINIONES) 
				nuevo_pinion = NUM_PINIONES;
			if (nuevo_pinion <= 0) 
				nuevo_pinion = 1;
			
			nuevo_plato = plato; 		
		}

		return (HayRiesgo (nuevo_plato, nuevo_pinion));
	}
	
	/***********************************************************************/
	// Comprobar las situaciones de riesgo
	//
	// NOTA: Situaciones de riesgo para 3 platos y 7 piñones
	//       Para otras configuraciones deberá personalizarse.
	//
	// Situaciones de riesgo:
	// 		1) plato=1 y piñón >= 5
	// 		2) plato=2 y (piñón = 1 ó piñón = 7)
	// 		2) plato=3 y piñón <= 3

	bool HayRiesgo (int nuevo_plato, int nuevo_pinion)
	{
		bool peligro1 = ((nuevo_plato == 1) && (nuevo_pinion >= 5));
		bool peligro2 = ((nuevo_plato == 2) &&
						 ((nuevo_pinion == 1) || (nuevo_pinion == 7)));
		bool peligro3 = ((nuevo_plato == 3) && (nuevo_pinion <= 3));

		return (peligro1 || peligro2 || peligro3);
	}
	
	/***********************************************************************/
		
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
int main (void)
{
	// La bicicleta tiene 3 platos y 7 piñones. 
	// UNa vez creada, estos datos no pueden modificarse. 
	
	Bicicleta mi_bicicleta (3, 7);

	cout << "Situacion inicial: " << "(" << setw(3) << mi_bicicleta.Getplato() 
	     << ", " << setw (3) << mi_bicicleta.GetPinion() << ")" << endl; 
	cout << endl; 
	
			 
	char engranaje; // E (plato), P (Piñón)
	char operacion; // S (Sube 1), B (Baja 1), T (sube 2), C (Baja 2)
	
	cout << endl;
	cin >> engranaje; 
	
	while (engranaje != 'X') {
		
		cin >> operacion;	
		
		// COmprobar si se va a ir a una situación de riesgo
		
		if (!mi_bicicleta.RiesgoRoturaCadena (engranaje, operacion)) {
		
			// No hay riesgo de rotura al efectuar el cambio 		
					
			if (engranaje == 'E') // Cambiar plato 
			
				if (operacion == 'S')
					mi_bicicleta.Subeplato();				
				else 
					mi_bicicleta.Bajaplato();
			
			else { // engranaje == 'P' --> Cambiar piñón
			
				switch (operacion) {
					
					case ('S'): mi_bicicleta.SubePinion();
								break; 
					case ('B'): mi_bicicleta.BajaPinion();
								break; 
					case ('T'): mi_bicicleta.SubeDosPiniones();
								break; 
					case ('C'): mi_bicicleta.BajaDosPiniones();
								break; 
				}
			}
			cout << endl;
			cout << "Cambio Ok con "<< engranaje <<" " << operacion<< " --> "; 	
								
		}
		else {
			cout << endl;
			cout << "Peligro con "<<engranaje <<" " << operacion << " ----> "; 	
		}
		
		cout << "(" << setw (3) << mi_bicicleta.Getplato() << ", " 
			 << setw (3) << mi_bicicleta.GetPinion() << ")" << endl; 
		
		cout << endl;
		cin >> engranaje; 		
	}	
	
	return 0;
}
