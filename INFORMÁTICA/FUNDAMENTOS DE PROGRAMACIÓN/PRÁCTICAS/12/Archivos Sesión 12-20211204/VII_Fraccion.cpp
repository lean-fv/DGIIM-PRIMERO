/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 7
//
/*	
	Se muestra el uso de una clase "Fraccion" que resulta �til para 
	representar y operar fracciones (ver transparencias de teor�a). 
	
	La clase proporciona un m�todo p�blico para simplificar la fracci�n   
	(devuelve la fracci�n irreducible equivalente). Para ello, divide 
	el numerador y denominador por su m�ximo com�n divisor. 	
	El c�lculo del MCD se realiza con el m�todo privado "MCD".

    NOTA: Posiblemente, el c�mputo del MCD de dos enteros es algo que 
	queramos realizar en otros programas de Matem�ticas. No obstante, al 
	ser un m�todo privado NO est� disponible fuera de la clase. 
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Fraccion 
{
private:

    int numerador;

	// PRE: denominador != 0
    int denominador;

public:

	/***********************************************************************/
 	// Constructor sin argumentos 
    // Crea la fracci�n: 0/1
    
	Fraccion (void) 
	{	
    	numerador = 0; 
		denominador = 1;	
	}

	/***********************************************************************/
    // Constructor con un argumento 
    // Crea la fracci�n: "valor"/1
    
	Fraccion (int valor) 
	{	
    	numerador = valor; 
		denominador = 1;	
	}

	/***********************************************************************/
	// Constructor con dos argumentos
	// Crea la fracci�n: "el_numerador"/"el_denominador"
	//
	// PRE: denominador != 0
	
	Fraccion  (int el_numerador, int el_denominador)
	{
	    numerador = el_numerador; 
		denominador = el_denominador;	
	}
	
	/***********************************************************************/
    // Metodos de Lectura
    
    int GetNumerador (void)
	{
		return (numerador);
	}
	
	int GetDenominador (void) 
	{
		return (denominador);		
	}

	/***********************************************************************/
	// M�todos de c�lculo: Suma, Resta, Multiplica y Divide.
	// Todos tienen un esquema similar: se aplican sobre el objeto impl�cito 
	// y reciben como argumento el otro operando ("otra_fraccion"), efect�an 
	// el c�lculo y devuelven como resultado un dato "Fraccion" simplificado.    
	// 
	// NOTA: ni el objeto impl�cito ni el argumento (objeto expl�cito) se 
	//		 modifican. El resultado es una NUEVA fracci�n.
	 	
	Fraccion Suma (Fraccion otra_fraccion)
	{
	    Fraccion tmp;
	    tmp.denominador = denominador*otra_fraccion.denominador;
	    tmp.numerador = (numerador*otra_fraccion.denominador) +
	                    (otra_fraccion.numerador*denominador);
	    return (tmp.Simplifica());		
	}
	
	/***********************************************************************/
		
	Fraccion Resta (Fraccion otra_fraccion)
	{
	    Fraccion tmp;
	    tmp.denominador = denominador*otra_fraccion.denominador;
	    tmp.numerador = (numerador*otra_fraccion.denominador) -
	                    (otra_fraccion.numerador*denominador);
	    return (tmp.Simplifica());		
	}

	/***********************************************************************/
	
	Fraccion Multiplica (Fraccion otra_fraccion)
	{
	    Fraccion tmp;
   		tmp.numerador = numerador*otra_fraccion.numerador;
    	tmp.denominador = denominador*otra_fraccion.denominador;
	    return (tmp.Simplifica());		
	}
	
	/***********************************************************************/
	
	Fraccion Divide (Fraccion otra_fraccion)
	{
		Fraccion tmp;
   		tmp.numerador = numerador*otra_fraccion.denominador;
    	tmp.denominador = denominador*otra_fraccion.numerador;
	    return (tmp.Simplifica());		
	}
	
	/***********************************************************************/
	// Calcula si dos fracciones son iguales 
	
	bool EsIgualA (Fraccion otra_fraccion)
	{
		return (numerador*otra_fraccion.denominador == 
			    denominador*otra_fraccion.numerador);
	}


	/***********************************************************************/
	// Simplifica una fracci�n.
	// 
	// Devuelve una NUEVA fracci�n, resultado se simplificar la fracci�n 
	// reprsentada en el objeto impl�cito. 
		
	Fraccion Simplifica (void)
	{
		
		Fraccion tmp;
		int mcd;

		mcd = MCD (numerador, denominador); 
		if (mcd !=0) {
			tmp.numerador = numerador/mcd;
			tmp.denominador = denominador/mcd;      
		}
		else {
			tmp.numerador = 0;
			tmp.denominador = 1;      
		}
			
		return (tmp);
	}
	
	/***********************************************************************/ 
	// Devuelve una fracci�n en forma de cadena.
	// Recibe:  r, la fracci�n a mostrar.
	
	string ToString ()
	{
		string cad;
		
		if (numerador % denominador == 0)	// El racional es un entero
		    cad = cad + "[" + to_string(numerador/denominador) + "]";	
		else 
			if (numerador == 0) // Simplificamos la presentaci�n --> 0
		    	cad = "[0]";
			else 
	    		cad = cad + "[" + to_string(numerador)
	         		 + "/" + to_string(denominador) + "]";
		return (cad);
	}
	
	/***********************************************************************/ 
	
private: 

	/***********************************************************************/
	// Calcula el M�ximo Com�n divisor de a y b
	// Recibe: a y b, valores para calcular el MCD(a,b)
	// Devuelve: MCD(a,b)
	
	int MCD (int a, int b)
	{	
		// Tomamos valores absolutos (positivos) 
		a = abs(a);
		b = abs(b);
		
		int mcd; // resultado
		
		if (a == 0 && b == 0) mcd = 0; // por convenio
		else if (a == 0)  mcd = b; 
		else if (b == 0)  mcd = a; 
		
		else { // a != 0 && b != 0

			/*
			Vamos dividiendo los dos enteros por todos los enteros  
			menores que el menor de ellos hasta que:
				- ambos sean divisibles por el mismo valor
				- o hasta que lleguemos al 1
			*/
			
			int divisor;
			bool hay_mcd = false;

			if (a > b) divisor = b;
			else divisor = a;
			// int divisor = (a > b) ? b : a; // De manera resumida 
		
			while (!hay_mcd) {
		
				if (a % divisor == 0 && b % divisor == 0) hay_mcd = true;
				else divisor--;
			}
		
			mcd = divisor;
		}
		
		return mcd;
	}	
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/    
/***************************************************************************/    
    
int main (void) 
{
	// Lectura de datos
	
	int num, den;

	cout << "Introduce el numerador -> ";
	cin  >> num;
   
	do {
		cout << "Introduce el denominador -> ";
		cin  >> den;
 	} while (den == 0);
 	

	// Constructor con dos argumentos (los dos valores leidos) 
	
	Fraccion mi_fraccion (num, den);

	// Presentaci�n de la fracci�n leida 
	
	cout << endl;
	cout << "Fracci�n original: ";
	cout << mi_fraccion.ToString();
	cout << endl;
	
	// Act�a el constructor de copia para crear una nueva matriz.
	// La instrucci�n siguiente equivale a escribir: 
	// Fraccion mi_fraccion_simplificada  (mi_fraccion.Simplifica());
	
	Fraccion mi_fraccion_simplificada = mi_fraccion.Simplifica();

	// Presentar resultado usando los m�todos de acceso a los componentes 
	// y prueba del m�todo "EsIgualA"
	
	cout << endl;
	cout << "Fraccion simplificada:" << endl;
	cout << "\tNumerador:   " 
		 << mi_fraccion_simplificada.GetNumerador() << endl;
	cout << "\tDenominador: " 
		 << mi_fraccion_simplificada.GetDenominador() << endl;
	cout << endl;

	if (mi_fraccion_simplificada.EsIgualA(mi_fraccion)) 
		cout << "Las dos fracciones son iguales."; 
	else 	
		cout << "Las fracciones son diferentes."; 		
	cout << endl;

	// Pruebas de operaciones
	
	Fraccion TresCuartos (3,4);
	Fraccion suma  = TresCuartos.Suma (mi_fraccion_simplificada);
	Fraccion resta = TresCuartos.Resta(mi_fraccion_simplificada);
	Fraccion mult  = TresCuartos.Multiplica(mi_fraccion_simplificada);
	Fraccion div   = TresCuartos.Divide(mi_fraccion_simplificada);
		
	cout << endl;
	cout << "3/4 + simplificada = ";
	cout << suma.ToString();

	cout << endl;
	cout << "3/4 - simplificada = ";
	cout << resta.ToString();
	
	cout << endl;
	cout << "3/4 * simplificada = ";
	cout << mult.ToString();
	
	cout << endl;
	cout << "3/4 : simplificada = ";
	cout << div.ToString();
	cout << endl;
    
	cout << endl;
	cout << "---------------------" << endl;

	Fraccion suma2  = mi_fraccion_simplificada.Suma(TresCuartos);
	
	cout << endl;
	cout << "simplificada + 3/4 = ";
	cout << suma2.ToString();
	cout << endl;

    if (suma.EsIgualA (suma2)) 
    	cout << "La propiedad conmutativa funciona correctamente en la suma."; 
	else 
    	cout << "Problemas con la propuedad conmutativa en la suma."; 
	cout << endl << endl; 

    cout << "Confirmacion de la propiedad conmutativa: " << endl;
	if (TresCuartos.Suma (mi_fraccion_simplificada).EsIgualA (
		mi_fraccion_simplificada.Suma (TresCuartos))) 
    	cout << "La propiedad conmutativa funciona correctamente en la suma."; 
	else 
    	cout << "Problemas con la propiedad conmutativa en la suma."; 
	cout << endl; 
	
		
	return 0;
}

/***************************************************************************/    
/***************************************************************************/    

