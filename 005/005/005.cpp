/* Svaki paran broj se moze prikazati kao suma dvaju prostih brojeva (tkzv. Goldbachovo pravilo).
Razraditi logiku programa koji ce najprije ucitati dva prirodna broja n1 i n2.
Ako je n1<n2 zamijeniti n1 sa n2.
Prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dvaju prostih brojeva.
U glavnom programu samo unijeti navedena dva broja i pozvati funkciju koja obavlja zadani posao.
*/

#include <iostream>
using namespace std;

void goldbach(int, int);

int main() {
	int n1, n2, temp;
	do {
		cout << "Unesite prirodan broj n1 i n2: " << endl;
		cin >> n1;
		cin >> n2;
	} while (n1 < 1 || n2 < 1);
	if (n1 > n2) {
		temp = n1;
		n2 = n1;
		n2 = temp;
	}
	goldbach(n1, n2);
}

bool prost(int broj) {
	if (broj == 1) {
		return false;
	}
	for (int i = 2; i < broj; i++) {
		if (broj%i==0) {
			return false;
		}
	}
	return true;
}

void goldbach(int n1,int n2) {
	if (n1<4) {
		n1 = 4;
	}
	if (n1%2!=0) {
		n1++;
	}
	for (int i = 2; i < n2; i++) {
		for (int j = 2; j < n2; j++) {
			if (prost(i) && prost(j)) {
				if (i+j==n1) {
					cout << n1 << " = " << i << " + " << j << endl;
					n1 += 2;
				}
			}
		}
		if (n1 > n2) {
			return;
		}
	}
	
}





