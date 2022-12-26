#include <iostream>
using namespace std;

/*Napisati program koji omogucava unos pozitivnog broja n te pronalazi njegove parne cifre
i formira novi broj u kojem su parne cifre zamijenjene cifrom 5.
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene cifara.*/


int unosn() {
	int n;
	do {
		cout << "Unesite pozitivan broj n: " << endl;
		cin >> n;
	} while (n<0);
	return n;
}

int promijenjeni(int n) {
	int cifra = 0;
	int novibr = 0;
	while (n>0) {
		cifra = n % 10;
		if (cifra%2==0) {
			cifra = 5;
		}
		novibr = novibr * 10 + cifra;
		n /= 10;
	}
	return novibr;
}

int obrni(int novibr) {
	int cifra = 0;
	int pravibr = 0;
	while (novibr > 0) {
		cifra = novibr % 10;
		pravibr = pravibr * 10 + cifra;
		novibr /= 10;
	}
	return pravibr;
}

int main() {
	int n = unosn();
	int novibr = promijenjeni(n);
	int pravibr = obrni(novibr);
	cout << "Prvobitno uneseni broj je: " << n << endl;
	cout << "Broj nakon operacija je: " << pravibr << endl;
	cout << "Razlika brojeva je: " << n - pravibr << endl;
}