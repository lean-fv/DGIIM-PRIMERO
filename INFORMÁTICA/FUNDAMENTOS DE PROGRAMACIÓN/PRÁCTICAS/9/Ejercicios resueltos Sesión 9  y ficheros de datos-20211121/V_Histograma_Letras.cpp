/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5 (Matrices)
//
/* 	
	Ver enunciado
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <clocale> 

using namespace std;

/***************************************************************************/
// Devuelve "true" si "c" es un carácter especial del alfabeto español: 
// á é í ó ú ñ Á É Í Ó Ú Ñ ü

bool EsCaracterEspecialEspaniol (unsigned char c) 
{
	// á 225, é 233, í 237, ó 243, ú 250, ñ 241 
	// Á 193, É 201, Í 205, Ó 211, Ú 218, Ñ 209, ü 252
	
	return (c==225 || c==233 || c==237 || c==243 || c==250 || c==241 || 
			c==193 || c==201 || c==205 || c==211 || c==218 || c==209 || 
			c==252);
}

/***************************************************************************/
// Convierte un carácter especial "c" a su equivalente estándar
// á (225) Á (193) --> a       ó (243) Ó (211) --> o
// é (233) É (201) --> e       ú (250) Ú (218) ü (252) --> u 
// í (237) Í (205) --> i       ñ (241) Ñ (209) --> ñ  
//
// Si "c" no requiere transformación devuelve el mismo valor

char TransformaCaracterEspecialEspaniol (unsigned char c) 
{
	char nuevo; 
	
	switch (c) {
		
		case (225) : 
		case (193) : nuevo = 'a'; 
					 break; 
		case (233) : 
		case (201) : nuevo = 'e'; 
					 break; 
		case (237) : 
		case (205) : nuevo = 'i'; 
					 break; 
		case (243) : 
		case (211) : nuevo = 'o'; 
					 break; 
		case (250) : 
		case (218) : 
		case (252) : nuevo = 'u'; 
					 break; 
		case (241) : 
		case (209) : nuevo = 'n'; 
					 break; 
		default: 	nuevo = c; 
					break; 		 	
	}
	
	return (nuevo);
}

/***************************************************************************/
/***************************************************************************/	
	
int main (void)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	
	setlocale(LC_CTYPE, "Spanish");
	
 	/*********************************************************************/
	// Constantes fundamentales 
	
	// Numero de caracteres a considerar 
	const int MUM_CARACTERES = 'z'-'a'+1; 	
	
	// Dimensiones del tablero de dibujo
	const int NUM_FILAS = 30;	// Número de filas del tablero
	const int NUM_COLS  = MUM_CARACTERES; // Número de columnas del tablero
	
	/*********************************************************************/	
	// Vectores asociados a los caracteres procesados 

	char las_letras  [MUM_CARACTERES]; 	// Letras que vamos a procesar

	for (char c='a'; c<='z'; c++) // Rellenar vector "las_letras"   
		las_letras[c-'a'] = c;
	int num_letras = MUM_CARACTERES; 	

	int  veces_letras[MUM_CARACTERES] = {0}; // Frecuencias (contadores)
	
 	/*********************************************************************/
	// Leer caracteres de cin (hasta *) y para cada uno, buscar si 
	// está en "las_letras" e incrementar su frecuencia (contabilizada 
	// en el vector "veces_letras"
	
	unsigned char c;	
	
	while ((c=cin.get()) != '*')  {

		if (isalpha(c)) {
	
			c = tolower(c);
			c = TransformaCaracterEspecialEspaniol(c);
							
			veces_letras[c-'a']++;
			
		} // if (isalpha(c))
				
	} // while ((c=cin.get()) != '*')
	

	/*********************************************************************/
	// Mostrar letras y sus frecuencias
	
	cout << endl;
	cout << "Letras y sus frecuencias" << endl;
	cout << endl;

	const int NUMCOLS_LETRAS = MUM_CARACTERES/2; 
	int filas_enteras = num_letras/NUMCOLS_LETRAS; 
	int resto = num_letras%NUMCOLS_LETRAS;
	
	// Lineas completas

	for (int f=0; f<filas_enteras; f++) {
	
		cout << endl; 
		
		for (int i=0; i<NUMCOLS_LETRAS; i++) 
			cout << setw(4) << las_letras[f*NUMCOLS_LETRAS+i];
		cout << endl; 
		
		for (int i=0; i<NUMCOLS_LETRAS; i++) 
			cout << setw(4) << veces_letras[f*NUMCOLS_LETRAS+i];
		cout << endl; 
	}

	// Ultimo bloque (no completo)

	if (resto > 0) {	
	
		cout << endl; 
	
		for (int i=0; i<resto; i++) 
			cout << setw(4) << las_letras[filas_enteras*NUMCOLS_LETRAS+i];
		cout << endl; 
		
		for (int i=0; i<resto; i++) 
			cout << setw(4) << veces_letras[filas_enteras*NUMCOLS_LETRAS+i];
		cout << endl; 
	}
			
	cout << endl; 

	/*********************************************************************/
	// Tablero de dibujo
		
	char histograma [NUM_FILAS][NUM_COLS];

	// Para configurar la presentación. 
	const char TRAZO = '*'; // Caracter del "trazo" (dibujo) 
	const char HUECO = '.'; // Caracter del "hueco" (no dibujo) 
	
 	const int  ANCHO	= 3;    // Num. caracteres de ancho por cada valor
 	const char CARACTER_LINEA = '-';   // Para la línea sobre las letras
 	const char CARACTER_COLUMNA = '|'; // Para la columna tras frecuencias
		
		
	// Calcular la letra más frecuente
	
	int letra_mas_frecuente = 0; // Empezar por la primera (letra 0)
	int frecuencia_mayor = veces_letras [letra_mas_frecuente];
		
	for (int pos=1;pos<num_letras; pos++) { // Procesar las restantes
		
		// Si es más frecuente, actualizar
		if (veces_letras [pos] > frecuencia_mayor) {
			letra_mas_frecuente = pos;
			frecuencia_mayor = veces_letras [pos];
		}
	} // for pos


	// Razón (filas por cada valor)
	double razon = ((double)NUM_FILAS) / frecuencia_mayor;

	// cout << "razon =  " << setw(6) << setprecision(3) << razon << endl; 
	
	
	// 1) Inicializar tablero
	// Rellenar toda la matriz con HUECO.

	for (int f=0; f<NUM_FILAS; f++) 
		for (int c=0; c<NUM_COLS; c++) 
			histograma[f][c] = {HUECO};
	
		
	// 2) Rellenar tablero
	// Rellenar la matriz con TRAZO donde corresponda.
	
	for (int letra=0; letra<num_letras; letra++) {
	
		int num_filas_letra = (int)(veces_letras[letra]*razon);
		/*
		cout << (char) (letra+'a') << "--> " << veces_letras[letra] 
		     << "--> " << num_filas_letra << " filas" << endl; 
		*/
		for (int f=0; f<num_filas_letra; f++) 
			histograma[f][letra] = TRAZO;
	}
	
	
	// 3) Mostrar tablero.

	// 3.1. Rellenar array de etiquetas (los valores que aparecen en la 
	//      columna de frecuencias - son todos valores int)	
	
	int etiquetas[NUM_FILAS+1] = {0};

	for (int frec=0; frec<=frecuencia_mayor; frec++) 
		etiquetas[frec] = (int)(frec*razon);
	
	
	// 3.2. Mostrar matriz "histograma"
	
	cout << endl;
	cout << "Histograma" << endl;
	cout << endl;
	
	int frecuencia_a_mostrar = frecuencia_mayor;
		
	for (int f=NUM_FILAS; f>0; f--) {
	
		if (f == etiquetas[frecuencia_a_mostrar]) {
			cout <<setw (5)<< frecuencia_a_mostrar << " " << CARACTER_COLUMNA; 	
		    frecuencia_a_mostrar--; 
		}
		else {
			cout << "      " << CARACTER_COLUMNA;
		}

		// Contenido de la fila "f" 		
		for (int c=0; c<num_letras; c++) 				
			cout << setw(ANCHO) << histograma[f-1][c];
	
		cout << endl; 	
	}
	
	// 3.3. Linea de separacion

	string parte_linea; 
	for (int i=0; i<ANCHO; i++) parte_linea += CARACTER_LINEA;
	
	string linea = "      ";
	linea += CARACTER_LINEA; 

	for (int i=0; i<num_letras; i++) 
		linea += parte_linea;
	
	cout << linea << endl; 
	
	// 3.4. Linea de letras
	
	cout << "       ";
	for (int i=0; i<num_letras; i++) {
		cout << setw(ANCHO) << las_letras[i];
	}
	cout << endl; 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
