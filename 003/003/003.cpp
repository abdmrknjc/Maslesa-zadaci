/*Data su dva prirodna broja X i Y iz intervala od 10 do 5000. Postujuci sve faze procesa programiranja, kreirati program koji ce prebrojati
i ispisati koliko brojeva od X do Y (ukljucujuci granicne vrijednosti) zadovoljava uslov da im je suma svih cifara djeljiva sa brojem koji se
dobije kada se saberu prva i zadnja cifra. U rjesenju koristiti najmanje jednu funkciju.
Npr. Za broj 162 vrijedi da mu je suma cifara 9, a suma prve i zadnje cifre je 1+2=3. Broj 9 je djeljiv brojem 3.
(Pojasnjenje: 1+6+2=9 -> 1+2=3 -> 9%3==0
Definisite vrijednosti intervala [X,Y]: 10 499
Dati uslov ispunjava: 184 broja
*/

#include <iostream>
using namespace std;

/*int unosxy() {
	int x, y;
	do {
		cout << "Unesite x i y, ne manje od 10 i ne vece od 5000: " << endl;
		cin >> x, y;
	} while (x < 10 || x > 5000 || y < 10 || y > 5000);
	return x, y;
}*/

int prvacifra(int n) {
	int pcifra = 0;
	while (n>=10) {
		n /= 10;
	}
	pcifra = n % 10;
	return pcifra;
}

int zadnjacifra(int n) {
	int zcifra = n % 10;
	return zcifra;
}

int suma(int n) {
	int sumacifara = 0;
	int pomocna = 0;
	while (n>0) {
		pomocna = n % 10;
		n /= 10;
		sumacifara += pomocna;
	}
	return sumacifara;
}

int zbirPiZcifara(int n) {
	int suma = prvacifra(n) + zadnjacifra(n);
	return suma;
}

/*bool sumajednakazbiru(int suma1, int zbircifara1) {
	
}*/
int main() {
	int x = 0;
	int y = 0;
	int brojac = 0;
	do {
		cout << "Unesite x i y, ne manje od 10 i ne vece od 5000: " << endl;
		cin >> x;
		cin >> y;
	} while (x < 10 || x > 5000 || y < 10 || y > 5000);
	if (x>y) {
		int temp = x;
		x = y;
		y = temp;
	}
	for (int i = x; i < y; i++){
		if (suma(i) % zbirPiZcifara(i) == 0){
			brojac++;
		}
	}
	cout << "Dati uslov ispunjava: " << brojac << " broja." << endl;
}