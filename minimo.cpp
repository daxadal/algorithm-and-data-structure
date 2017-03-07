
#include <iostream>
using namespace std;


int minimo(int v[], int p, int f)
{
	if (f-p == 0) //1 elemento
		return v[p];

	else if (f-p == 1) { //2 elementos
		if (v[p] < v[f])
			return v[p];
		else /*v[p] > v[f]*/
			return v[f];
	}
	else { //3 o más elementos
		int c = (p+f)/2;
		if ( v[c-1] > v[c] && v[c] < v[c+1])
			return v[c];
		else if ( v[c-1] < v[c] && v[c] < v[c+1])
			return minimo(v, p, c-1);
		else /* v[c-1] > v[c] && v[c] > v[c+1]*/
			return minimo(v, c+1, f);
	}
}

int main() {

	int v[] = {30, 22, 12, 9, 8, 7, 6, 3, 4, 5}; //Vector
	int n = 10; //Longitud del vector
	int m; //Mínimo

	if (n==0)
		cout << "El vector debe ser no vacío" << endl;
	else {
		m = minimo(v, 0, n-1);
		cout << "Minimo: " << m << endl;
	}
	return 0;
}
