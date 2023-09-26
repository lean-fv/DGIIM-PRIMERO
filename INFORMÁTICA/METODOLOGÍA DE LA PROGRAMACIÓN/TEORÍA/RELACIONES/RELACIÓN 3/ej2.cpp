/*

2. Implementa una funcion que reciba un puntero a entero y que:
(a) Eleve al cuadrado el dato apuntado.
(b) Ponga a cero el puntero.
Tal funci´on podr´ıa usarse de la siguiente forma:
int a=6;
int *q;
q = &a;
elevarAlCuadrado(q);
cout << a << q; // Deberıa salir 36 0

*/

#include <iostream>
#include <string>

using namespace std;

void elevarAlCuadrado (int *&ptr){

	*ptr= (*ptr)*(*ptr);
	ptr=nullptr;

}

int main() {

	int a=6;
	int *q;
	q = &a;
	elevarAlCuadrado(q);

	cout << a << endl << q << endl; // Deberıa salir 36 0

	return 0;
}
