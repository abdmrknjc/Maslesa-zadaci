/* Napisati program koji izracunava aritmeticku sredinu svih savrsenih brojeva iz zadatog intervala.
   Za neki broj se kaze da je savrsen ukoliko je jednak sumi svih svojih djelilaca (ne ukljucujuci njega samog).
   Na primjer, 28 je savrsen broj: njegovi djelioci su: 1, 2, 4, 7 i 14, a 1+2+4+7+14=28. Jedini savrseni brojevi u opsegu od 1 do 100
   su brojevi 6 i 28. U rjesenju koristiti funkciju sljedeceg prototipa: bool IsSavrsen(int).
   Primjer:
   Unesite granice intervala: 1 -> 500
   Aritmeticka sredina savrsenih brojeva iz zadatog intervala je: 176.667
*/

#include <iostream>
using namespace std;

bool isSavrsen(int br) {
	int suma = 0;
	for (int i = 1; i < br; i++) {
		if (br%i==0) {
			suma += i;
		}
	}
	if (suma == br) {
		return true;
	}
	else 
		return false;
}



int main() {
	int x, y;
	double suma = 0;
	int brojacSavrsenih = 0;
	do {
		cout << "Unesite granice intervala x -> y: " << endl;
		cin >> x;
		cin >> y;
	} while (x < 0 || y < 0);
	for (int i = x; i <= y; i++) {
		if (isSavrsen(i)) {
			suma += i;
			brojacSavrsenih++;
		}
	}
	cout << "Aritmeticka sredina savrsenih brojeva iz zadatog intervala je: " << suma / brojacSavrsenih << endl;
}