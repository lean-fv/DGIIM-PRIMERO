/*
4. Declare una variable v como un array de 1000 enteros. Escriba un trozo de
c´odigo que recorra el array y modique todos los enteros negativos cambi´andolos
de signo. No se permite usar el operador [], es decir, el recorrido se efectuara
usando aritm´etica de punteros y el bucle se controlar´a mediante un contador
entero.

5. Modifique el c´odigo del problema anterior para controlar el final del bucle
con un puntero a la posici´on siguiente a la ´ultima.
*/

#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

	srand(time(NULL));

	const int TAM=1000;
	int v[TAM];
	int *p=v;

	for (; p<v+TAM; p++) {

		*p= - 5 + rand() % (5 + 1 - (- 5)) ;
		cout << *p << " ";
	}

	p=v;

	cout <<endl<<endl;

	for (; p<v+TAM; p++){
		if (*p<0) *p=abs(*p);
	}


	p=v;

	for (; p<v+TAM; p++) {
		cout << *p << " ";
	}

	return 0;
}
