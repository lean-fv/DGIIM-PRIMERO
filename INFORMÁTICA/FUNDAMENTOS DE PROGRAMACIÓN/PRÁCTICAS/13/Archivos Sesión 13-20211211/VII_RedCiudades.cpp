/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*	
	TABLA RECTANGULAR -	MATRIZ CLASICA

	(Examen Ordinario 2017) Las distancias entre un conjunto de ciudades se 
	almacenan en una tabla rectangular de datos double. En realidad se 
	almacenan las distancias de los caminos directos que conectan un conjunto 
	de ciudades. Si entre dos ciudades no existe un camino directo, 
	se almacenar� un cero. Se supone que la distancia de una ciudad consigo 
	misma ser� cero y que las distancias son sim�tricas. 
	
	Se implementa la clase "MapaDistancias" para representar estos datos.
	Se usa como base la clase "TablaRectangular". Suponemos que nunca se 
	trabajar� con m�s de 50 ciudades. La funcionalidad de la clase responde 
	al enunicado del ejercicio. 
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros
{

private:

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	int vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:

	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaEnteros (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// M�todos de lectura (Get) de los datos individuales

	// Devuelve el n�mero de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el n�mero de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// A�ade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (int nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Eliminar el dato de la posici�n dada por "indice".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	//
	// PRE: 0 <= indice < total_utilizados

	void Elimina (int indice)
	{
		// Recorremos de izquierda a derecha toda las componentes
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo

			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];

			total_utilizados--;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	int Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// Devuelve true si la secuencia est� vac�a

	bool EstaVacia (void)
	{
		return (total_utilizados == 0);
	}

	/***********************************************************************/
	// "Vac�a" una secuencia

	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}

    /***********************************************************************/
    // Compone un string con todos los valores que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)
	        	cadena = cadena + to_string(vector_privado[i])+", ";

			// A�adie el �ltimo seguido de '}'
	        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
		}

        cadena = cadena + "}";

        return (cadena);
    }
    
   	/***********************************************************************/
 
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////

class MapaDistancias
{

private:
	
    static const int MAX_CIUDADES = 50; 
    
    double  matriz_distancias[MAX_CIUDADES][MAX_CIUDADES];
    
    // Como "matriz_distancias" es una matriz cuadrada solo necesitamos 
	// el valor de "num_ciudades" (n�mero de filas y columnas)
    // PRE: 0 <= num_ciudades <= MAX_CIUDADES

    int num_ciudades;
	
public:

	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	MapaDistancias (void) : num_ciudades(0) {}
	
	/***********************************************************************/
	// Constructor con argumentos--> Crea matriz lista para escribir datos 
	// de distancias entre "ciudades" ciudades
    // PRE: 0 <= ciudades <= MAX_CIUDADES

	MapaDistancias (int ciudades) : num_ciudades(ciudades)
	{
		for (int f=0; f<num_ciudades; f++)
			for (int c=0; c<num_ciudades; c++)
				matriz_distancias[f][c] = 0.0;
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de ciudades

	int CapacidadCiudades (void)
	{
		return (MAX_CIUDADES);
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero real de ciudades

	int NumCiudades (void)
	{
		return (num_ciudades);
	}	
	
	/***********************************************************************/
	// M�todo de escritura: modifica el valor de la distancia entre ciudades
	// PRE: 1 <= una, otra <= num_ciudades
	// 		La ciudad "i" se corresponde con la fila/columna "i"-1
	// PRE: dist >= 0

	void ModificaDistanciaDirecta (int una, int otra, double dist)
	{
		matriz_distancias[una-1][otra-1] = 
		matriz_distancias[otra-1][una-1] = dist;
	}	
		
	/***********************************************************************/
	// M�todo de consulta: devuelve TRUE si "una" y "otra" est�n conectadas 
	// de forma directa. No considera el caso trivial "una" == "otra"
	// PRE: "una" != "otra" 
	
	bool EstanConectadasDirecta (int una, int otra)
	{
		return (matriz_distancias[una-1][otra-1] > 0);
	}		
	
	/***********************************************************************/
	// M�todo de lectura: Distancia entre dos ciudades
	// PRE: "una" y "otra" est�n conectadas directamente
	
	double DistanciaDirecta (int una, int otra)
	{
		return (matriz_distancias[una-1][otra-1]);
	}	

	/***********************************************************************/
	// Calcula la ciudad m�s conectada de forma directa
	
	int CiudadMasConectadaDirecta (void)
	{
		int max = -1; 
		int ciudad_mas_conectada_directa;
		
		for (int origen=0; origen<num_ciudades; origen++) {
			
			int num_conexiones_directas = 0;
			
			for (int destino=0; destino<num_ciudades; destino++) 
			
				if (matriz_distancias[origen][destino] != 0.0) 
					num_conexiones_directas++;
					
			if (num_conexiones_directas > max)	{
				
				max = num_conexiones_directas;
				ciudad_mas_conectada_directa = origen;
			}	
					
		} // for origen
				
		
		return (ciudad_mas_conectada_directa+1);
	}	
		
	/***********************************************************************/
	// Devuelve una secuencia con los n�meros de las ciudades conectadas 
	// de forma directa con "ciudad"
	// NOTA: Los n�meros devueltos son n�meros de ciudad (>=1) -NO �ndices-. 
	
	SecuenciaEnteros CiudadesConectadasDirectamenteCon (int ciudad)
	{
		SecuenciaEnteros secuencia_ciudades;
			
		for (int destino=0; destino<num_ciudades; destino++) 
			
			if (matriz_distancias[ciudad-1][destino] != 0.0) 
				secuencia_ciudades.Aniade(destino+1);
		
		return (secuencia_ciudades);
	}	
				
	/***********************************************************************/
	// Calcula la mejor escala intermedia (de una sola ciudad) entre 
	// las ciudades "una" y "otra"
	// DEVUELVE: la mejor ciudad escala (m�nimma distancia total) si la hay
	//			 -1 si no existe conexi�n intermedia de uuna escala.
	// PRE: "una" y "otra" no tienen conexi�n directa
			
	int EscalaEntre (int una, int otra)
	{
		double min_dist = INFINITY;
		int mejor_escala = -1;
				
		for (int candidato=1; candidato<=num_ciudades; candidato++) {
			
			if (una!=candidato) {

				// �conexion entre {"una"-"candidato"} y {"candidato"-"otra"}?				
				
				double d1 = matriz_distancias[una-1][candidato-1];
				double d2 = matriz_distancias[candidato-1][otra-1];

				if ((d1 > 0) && (d2 > 0)) {  // Existe conexi�n intermedia

					// �Es mejor que la mejor hasta ahora?
					
					double distancia = d1 + d2;
					
					if (distancia < min_dist) { 
						// Actualizar datos de la mejor escala 
						min_dist = distancia;	
						mejor_escala = candidato;
					}
					
				} // if (existe conexion directa)  
				
			} // if (ciudades diferentes)
			
		} // for (candidato)
		
		return (mejor_escala);				
	}			
						
	/***********************************************************************/
	// Calcula si todas las ciudades de "secuencia_ciudades" tienen una 
	// conexi�n directa entre ellas, dos a dos
			
	bool HayTotalConexionDirecta (SecuenciaEnteros secuencia_ciudades)
	{			
		bool conexion_total = true;
		
		int num_ciudades_secuencia = secuencia_ciudades.TotalUtilizados();
		
		int una, otra; 	// origen y destino (1,2,...)
		int indice_una, indice_otra; 	// Indice de "una" y "otra" en 
										// "secuencia_ciudades" (0,1,...)
		indice_una = 0;

		bool seguir = true; // escapatoria
		
		while (indice_una<num_ciudades_secuencia  && seguir) {
			
			una = secuencia_ciudades.Elemento(indice_una);	
			
			indice_otra = indice_una+1;
			
			while (indice_otra<num_ciudades_secuencia  && seguir) {
				
				otra = secuencia_ciudades.Elemento(indice_otra);			
		
				// �Conexi�n directa entre "una" y "otra"?
				
				if (matriz_distancias[una-1][otra-1] == 0) {  // No --> fin
					seguir = false; 
					conexion_total = false;
				} 
				else indice_otra++; // Si --> seguir
				
			} // for indice_otra

			if (seguir) indice_una++; // seguir 
			
		} // for indice_una
		
		return (conexion_total);				
	}			
					
	/***********************************************************************/
	// Compone y devuelve un string con el contenido de la matriz
	
	string ToString ()
	{
		string cad; 
		
		for (int origen=0; origen<num_ciudades; origen++) {
			
			for (int destino=0; destino<num_ciudades; destino++) {
			
				cad = cad + "\t" + 
				      to_string(matriz_distancias[origen][destino]);  
			}
			cad = cad + "\n";
		}
		
		return (cad);
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main ()
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	
	// **********************************************************************
	// EJEMPLO 1 	
	// **********************************************************************
		
	MapaDistancias ejemplo (4);
	
	ejemplo.ModificaDistanciaDirecta(1,2,30);
	ejemplo.ModificaDistanciaDirecta(1,3,80);
	ejemplo.ModificaDistanciaDirecta(2,3,25);
	ejemplo.ModificaDistanciaDirecta(2,4,90);
	
	cout << endl; 
	cout << ejemplo.ToString();
	cout << endl; 
	
	
	// Ciudad mejor conectada directamente y mostrar con cu�les lo est�
	
	int c = ejemplo.CiudadMasConectadaDirecta();
	SecuenciaEnteros ciudades_directas_con_c =  
	                           ejemplo.CiudadesConectadasDirectamenteCon(c); 

	cout << "La ciudad con mas conexiones directas es: " << c << endl;
	cout << "Esta conectada con: "<< ciudades_directas_con_c.ToString()<< endl; 
	cout << endl; 
	
	// Calcular las mejores conexiones de una sola escala 
	
	cout << "Calculando conexiones indirectas de una escala. " << endl;

	for (int origen=1; origen<=ejemplo.NumCiudades(); origen++) 
						
		for (int destino=origen+1; destino<=ejemplo.NumCiudades(); destino++) 
			
			// Si no hay conexi�n directa, buscar escala de una sola ciudad
			
			if (!ejemplo.EstanConectadasDirecta(origen, destino)) {
				
				cout << "\tBuscando entre " << setw(3) << origen 
				     << " y " << setw(3) << destino << ": ";
				
				int escala = ejemplo.EscalaEntre(origen, destino);
				
				if (escala >= 0) 
					cout << "la escala es " << setw(3) << escala << endl; 
				else 
					cout << "no hay escala de una sola ciudad." << endl; 
					
			}


	// Puebas de conexi�n directa total
	
	SecuenciaEnteros sec;
	sec.Aniade(1); 	sec.Aniade(2);	sec.Aniade(3);

	cout << endl;	
	cout << "Secuencia de ciudades: "; 
	cout << sec.ToString(); 
	cout << endl;
		
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;
	

	sec.Aniade(4); // Ya no hay conexi�n total

	cout << endl;	
	cout << "Secuencia de ciudades: "; 
	cout << sec.ToString(); 
	cout << endl;
		
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;
		
	
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl;
		
		
	// **********************************************************************
	// EJEMPLO 2 	
	// **********************************************************************
				
	MapaDistancias ejemplo2 (6);
	
	ejemplo2.ModificaDistanciaDirecta(1, 2, 20);
	ejemplo2.ModificaDistanciaDirecta(1, 3, 20);
	ejemplo2.ModificaDistanciaDirecta(1, 4, 60);	
	ejemplo2.ModificaDistanciaDirecta(2, 3, 15);
	ejemplo2.ModificaDistanciaDirecta(2, 5, 30);
	ejemplo2.ModificaDistanciaDirecta(3, 4, 25);
	ejemplo2.ModificaDistanciaDirecta(3, 5, 25);
	ejemplo2.ModificaDistanciaDirecta(4, 5, 50);
	ejemplo2.ModificaDistanciaDirecta(4, 6, 90);
		
	cout << endl; 		
	cout << ejemplo2.ToString();
	cout << endl; 
	
	
	// Alternativa: Lectura de datos. Los datos se toman de cin. 
	// En primer lugar se lee el n�mero de ciudades y despu�s una 
	// serie indefinida de tripletas {c1, c2, dist(c1,c2)}. 
	// Se termina al leer el valor TERMINADOR
	
	int num_ciudades; 
	
	cin >> num_ciudades; 
	
	MapaDistancias ejemplo2_bis (num_ciudades);
	
	int c1, c2;
	double dist_c1_c2; 
	
	//const string TERMINADOR = "FIN";
	
	//string str_c1;
	
	const int TERMINADOR = 0;
	
	//cin >> str_c1; 
	cin >> c1;
		
	while (c1 != TERMINADOR) {
		
		//c1 = stoi(str_c1);
		
		cin >> c2; 
		cin >> dist_c1_c2; 
		
		ejemplo2_bis.ModificaDistanciaDirecta(c1, c2, dist_c1_c2);

		//cin >> str_c1; 
		cin >> c1;
	}

	cout << endl; 		
	cout << ejemplo2_bis.ToString();
	cout << endl; 


	// los c�lculos se realizan sobre "ejemplo2"
	// Ciudad mejor conectada directamente y mostrar con cu�les lo est�
	
 	c = ejemplo2.CiudadMasConectadaDirecta();
	ciudades_directas_con_c = ejemplo2.CiudadesConectadasDirectamenteCon(c); 

	cout << "La ciudad con mas conexiones directas es: " << c << endl;
	cout << "Esta conectada con: "<< ciudades_directas_con_c.ToString()<< endl; 
	cout << endl; 
	
	// Calcular las mejores conexiones de una sola escala 
	
	cout << "Calculando conexiones indirectas de una escala. " << endl;

	for (int origen=1; origen<=ejemplo2.NumCiudades(); origen++) 
						
		for (int destino=origen+1; destino<=ejemplo2.NumCiudades(); destino++) 
							
			// Si no hay conexi�n directa, buscar escala de una sola ciudad
			
			if (!ejemplo2.EstanConectadasDirecta(origen, destino)) {
				
				cout << "\tBuscando entre " << setw(3) << origen 
				     << " y " << setw(3) << destino << ": ";
				
				int escala = ejemplo2.EscalaEntre(origen, destino);
				
				if (escala >= 0) 
					cout << "la escala es " << setw(3) << escala << endl; 
				else 
					cout << "no hay escala de una sola ciudad." << endl; 
					
			}
	
	
	// Puebas de conexi�n directa total
	
	sec.EliminaTodos();
	sec.Aniade(1); 	sec.Aniade(2);	sec.Aniade(3);
	sec.Aniade(4);	sec.Aniade(5);	sec.Aniade(6);

	cout << endl;	
	cout << "Secuencia de ciudades: " << sec.ToString()<< endl; 
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo2.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;
	
				
	sec.EliminaTodos();
	sec.Aniade(1);	sec.Aniade(2);	sec.Aniade(3);	

	cout << endl;	
	cout << "Secuencia de ciudades: " << sec.ToString()<< endl; 
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo2.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;
	
	
	sec.Aniade(4); // Ya no hay conexi�n total
	
	cout << endl;	
	cout << "Secuencia de ciudades: " << sec.ToString()<< endl; 
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo2.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;	
		
		
					
	sec.EliminaTodos();
	sec.Aniade(3);	sec.Aniade(4);	sec.Aniade(5);	

	cout << endl;	
	cout << "Secuencia de ciudades: " << sec.ToString()<< endl; 
	cout << "Calculando si hay conexion total directa entre ellas: ";			
	cout << ((ejemplo2.HayTotalConexionDirecta (sec)) ?  "SI": "NO") << endl;
		
	return 0;
}

/***************************************************************************/
