
#include <iostream>
using namespace std;

//Ejercicio 12
bool palindroma(string word, int ini, int fin)
{
	bool is_pal;

	if (ini>=fin) //Caso base: El array tiene 0 o 1 elementos
		is_pal = true;
	else //Caso recursivo: 2 o más elementos
		is_pal = (word[ini]==word[fin]) && palindroma(word, ini+1, fin-1);

	return is_pal;
}

int main() {
	string word;
	bool is_pal;
	int contador;

	cout << "Intoduzca una palabra: ";
	cin >> word;
	contador = word.length();

	is_pal = palindroma(word, 0, contador-1);
	if (is_pal) cout << "Palindroma";
	else cout << "NO palíndroma";

	return 0;
}

