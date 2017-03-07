#include "Pila.h"
#include "Excepciones.h"

#include <iostream>
#include <Windows.h>

int main() {
	PilaLE<int> pila = PilaLE<int>();
	for (int i=0; i<4; i++)
		pila.apila(4-i);
	cout << pila<< endl;
	pila.revolver();
	cout << pila<< endl;


	char fin;
	cin.get(fin);
	return 0;
}