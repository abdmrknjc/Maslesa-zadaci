/* Kreirati program koji ce pronaci i ispisati sve brojeve od X do Y 
(ukljucujuci granicne vrijednosti) koji su djeljivi svim svojim ciframa.
Na primjer, broj 36 je djeljiv brojevima 3 i 6. (36/6=6 i 36/3=12).
Brojeve X i Y unosi korisnik i moraju biti u opsegu od 10 do 6000.
Obavezno koristiti bar jednu funkciju.
Primjer:
Unesite granice intervala: 32 37
Brojevi u navedenom opsegu koji zadovoljavaju uslov su: 33, 36.
*/

#include <iostream>
using namespace std;

bool djeljiv(int n) {
	int cifra = 0;
	int pomocna = n;
	while (n>0)
	{
		cifra = n % 10;
		if (cifra!=0)
		{
			if (pomocna%cifra!=0)
			{
				return false;
			}
		}
		n /= 10;
	}
	return true;
}

int main() {
	int x = 0;
	int y = 0;
	do {
		cout << "Unesite x i y u intervalu 10-6000: " << endl;
		cin >> x;
		cin >> y;
	} while (x < 10 || x > 6000 || y < 10 || y > 6000);
	cout << "Brojevi u navedenom opsegu koji zadovoljavaju uslov su: " << endl;
	for (int i = x; i <= y; i++) {
		if (djeljiv(i))
		{
			cout << i << endl;
		}
	}

}