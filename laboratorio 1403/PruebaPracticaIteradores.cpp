//============================================================================
// Name        : Lineales.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <cassert>
#include <string>

#include "Lista.h"


int ej25(const Lista<char> &l) {
	int count = 0;
	Lista<char>::Iterador ini = l.principio();
	Lista<char>::Iterador fin = l.final();
	char c;
	const char CHAR = 'a';

	while (ini != fin) {
		c = ini.elem();
		if (c == CHAR)
			count++;
		ini.avanza();
	}
	return count;
}

bool ej29(const Lista<char> &l) {
	Lista<char>::Iterador ini = l.principio();
	Lista<char>::IteradorInverso fin = l.principioInverso();
	bool pal = true;
	char ci, cf;

	while (ini != fin && pal) {
		ci =ini.elem();
		cf = fin.elem();
		pal = (ci == cf);
		ini.avanza();
		if (ini != fin)
			fin.avanza();
	}
	return pal;
}

int main() {
	

    // Prueba ejercicio 25
    Lista<char> l;
    l.ponDr('a'); l.ponDr('b'); l.ponDr('a'); l.ponDr('b'); l.ponDr('a');
    cout << "Lista : " << l;
    cout << "El numero de a de la lista es : " << ej25(l) << "\n";
    // Lista vacia
    Lista<char> l1;
    cout << "El numero de a de la lista vacia es : " << ej25(l1) << "\n";
    // Lista con un elemento
    l1.ponDr('a');
    cout << "Lista : " << l1;
    cout << "El numero de a de la lista es : " << ej25(l1) << "\n";
    // Todos los elementos son a
    l1.ponDr('a'); l1.ponDr('a'); l1.ponDr('a'); l1.ponDr('a'); l1.ponDr('a');
    cout << "Lista : " << l1;
    cout << "El numero de a de la lista es : " << ej25(l1) << "\n";
    // Ningun elemento es a
    Lista<char> l2;
    l2.ponDr('b');
    cout << "Lista : " << l2;
    cout << "El numero de a de la lista es : " << ej25(l2) << "\n";
    l2.ponDr('b'); l2.ponDr('b'); l2.ponDr('b'); l2.ponDr('b'); l2.ponDr('b');
    cout << "Lista : " << l2;
    cout << "El numero de a de la lista es : " << ej25(l2) << "\n";
    
   

	// prueba ejercicio 29
	// palabra con numero impar de letras
	Lista<char> lc1;
	lc1.ponDr('a'); lc1.ponDr('b'); lc1.ponDr('a'); lc1.ponDr('b'); lc1.ponDr('a');
	if (ej29(lc1)) cout << "La palabra " << lc1 <<  "es palindroma \n";
	else cout << "La palabra " << lc1 <<  " no es palindroma \n";
    
	// palabra con numero par de letras
	Lista<char> lc2;
	lc2.ponDr('a'); lc2.ponDr('b'); lc2.ponDr('c'); lc2.ponDr('c'); lc2.ponDr('b'); lc2.ponDr('a');
	if (ej29(lc2)) cout << "La palabra " << lc2 <<  " es palindroma \n";
	else cout << "La palabra " << lc2 <<  " no es palindroma \n";
    
	Lista<char> lc3;
	if (ej29(lc3)) cout << "La palabra " << lc3 <<  " es palindroma \n";
	else cout << "La palabra " << lc3 <<  " no es palindroma \n";
    
	lc3.ponDr('a'); lc3.ponDr('b'); lc3.ponDr('c'); lc3.ponDr('d'); lc3.ponDr('a');
	if (ej29(lc3)) cout << "La palabra " << lc3 <<  " es palindroma \n";
	else cout << "La palabra " << lc3 <<  " no es palindroma \n";

   
    Lista<char> lista;
	for (int i=0; i<20; i++)
		lista.ponDr('a'+ i);
	cout << lista << endl;
	Lista<char>::IteradorMutable it = lista.buscar('b');
	char = r;
	it.modifica(lista.elem(0));
	cout << lista << endl;


	cout << "Fin de las pruebas\n";
	char fin;
	cin.get(fin);
	return 0;
}
