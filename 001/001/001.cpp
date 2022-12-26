/* a) Omoguciti korisniku unos prirodnog broja i nakon toga napraviti funkciju koja ce prebrojati koliko taj broj ima cifara
   b) Za taj broj pronaci i ispisati prvu, srednju i zadnju cifru (koristiti zasebne funkcije)
   c) Obrnuti cifre tom broju (npr. ako je broj bio 12345 treba biti 54321) */
#include <iostream>
using namespace std;

int unosn() {
	int n;
	do
	{
		cout << "Unesite prirodan broj n: " << endl;
		cin >> n;
	} while (n<0);
	return n;
}

int brojaccifara(int n) {
	int brojac=0;
	while (n>0)
	{
		n /= 10;
		brojac++;
	}
	return brojac;
}

int prvacifra(int n) {
	int prva = 0;
	while (n > 0)
	{
		
		if (n<10)
		{
			prva = n % 10;
		}
		n /= 10;
	}
	return prva;
}

int srednjacifra(int n) {
	int pomocna = brojaccifara(n) / 2;
	n = n / pow(10, pomocna);
	return n % 10;
}

int zadnjacifra(int n) {
	int posljednja = n % 10;
	return posljednja;
}

int obrni(int n) {
	int obrnuta = 0;
	int cifra = 0;
	while (n>0){
		cifra = n % 10;
		obrnuta = obrnuta * 10 + cifra;
		n /= 10;
	}
	return obrnuta;
}

int main() {
	int n = unosn();
	cout << "Uneseni broj je: " << n << endl;
	cout << "Uneseni broj ima: " << brojaccifara(n) << " cifara." << endl;
	cout << "Prva cifra broja je: " << prvacifra(n) << endl;
	cout << "Srednja cifra broja je: " << srednjacifra(n) << endl;
	cout << "Zadnja cifra broja je: " << zadnjacifra(n) << endl;
	cout << "Obrnut broj od unesenog je: " << obrni(n) << endl;
	system("pause>0");
	return 0;
}