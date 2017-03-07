
#include <iostream>
using namespace std;


int numSumSimet(int v[], int i, int& l, int& r)
{
	int num;
	if (i==0)
		num = 0;
	else if (i==1) {
		if (l==r)
			num = 1;
		else
			num = 0;
	}
	else /*i>1*/ {
		if (l==r) {
			l = l - v[i-2];
			r = r + v[i-1];
			num = 1 + numSumSimet(v, i-1, l, r);
		}
		else {
			l = l - v[i-2];
			r = r + v[i-1];
			num = numSumSimet(v, i-1, l, r);
		}
	}
	return num;
}


int main() {
	int v[] = {0, 2, 0, 1, 0,    5, 25, 5, 0, 1,    0, 2, 0}; //Vector
	int n = 13; //num elementos del vector

	int l = 0; //Suma del vector excepto el ultimo elemento
	for (int i=0; i<n-1; i++)
		l += v[i];

	int r = 0;

	cout << "Resultado: "<< numSumSimet(v, n, l, r) << endl;
	return 0;
}
