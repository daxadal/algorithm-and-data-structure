
#include <iostream>
using namespace std;

void movimiento(int i, int j)
{
	cout << "Movimiento de la varilla " << i << " a la varilla " << j << endl;
}

//Procedimiento que mueve n discos de la varilla ini a la varilla fin
void hanoi(int n, int ini, int fin, int aux)
{
	if (n==1)
		movimiento(ini, fin);
	else {/*n>1*/
		hanoi(n-1, ini, aux, fin);
		movimiento(ini, fin);
		hanoi(n-1, aux, fin, ini);
	}

}

int main() {
	int n_discos;

	cout << "Intoduzca el num de discos: ";
	cin >> n_discos;
	cout << "Varilla inicial: 1" << endl
		 << "Varilla auxiliar: 2" << endl
		 << "Varilla final: 3" << endl;
	hanoi(n_discos, 1, 3, 2);

	return 0;
}

