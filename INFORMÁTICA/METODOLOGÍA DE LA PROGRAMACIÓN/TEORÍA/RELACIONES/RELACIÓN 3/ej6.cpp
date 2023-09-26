/*
6. Dado un array de 10 elementos, haz un bucle que busque el m´aximo y el
m´ınimo (sin usar el operador[]).
Al acabar el bucle tendremos un puntero apuntando a cada uno de ellos.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

	srand(time(NULL));

	const int TAM=10;
	int v[TAM];
	int *p=v;

	for (; p<v+TAM; p++) {

		*p= - 5 + rand() % 10 ;
		cout << *p << " ";
	}

	p=v;

	cout <<endl<<endl;


	int *min=v;
	int *max=v;

	for (; p<v+TAM; p++){
		if (*p<*min){
			min=p;
		}
		if (*p>*max){
			max=p;
		}
	}


	cout << "Maximo= " << *max << endl << "Minimo= " << *min << endl;

	return 0;
}
