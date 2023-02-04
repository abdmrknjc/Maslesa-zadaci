#include <iostream>
using namespace std;

/*napisati program koji ce ucitati prirodni broj n <= 10, a zatim n prirodnih trocifrenih brojeva spremiti 
u odgovarajuci niz. taj niz brojeva treba sortirati uzlazno po srednjoj cifri. 
nakon sortiranja treba ispisati dobiveni niz.
za sortiranje koristiti zasebnu funkciju kojoj se prosljedjuje nesortiran niz.*/

void unos(int niz[], int vel) {
	int broj;
	for (int i = 0; i < vel; i++){
		cout << "Unesite " << i + 1 << ". broj niza: (broj mora biti trocifren!) " << endl;
		cin >> broj;
		if (broj < 100 || broj>999) {
			cout << "Unijeli ste broj koji nije trocifren! " << endl;
			i--;
		}
		else 
			niz[i]=broj;
	}
}

void sortiranje(int niz[], int vel) {
	bool promjena = true;
	int pomocna = 0;
	int srednjaZaTrocifren1 = 0;
	int srednjaZaTrocifren2 = 0;
	while (promjena)
	{
		promjena = false;
		for (int i = 0; i < vel-1; i++)
		{
			srednjaZaTrocifren1 = (niz[i] / 10) % 10;
			srednjaZaTrocifren2 = (niz[i + 1] / 10) % 10;
			if (srednjaZaTrocifren1 > srednjaZaTrocifren2)
			{
				pomocna = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = pomocna;
				promjena = true;
			}
		}
	}
	
}

int main() {
	int n;
	const int vel = 10;
	int niz[vel];
	do
	{
		cout << "Unesite velicinu niza, n>1 i n<=10: " << endl;
		cin >> n;
	} while (n<1||n>10);
	unos(niz, n);
	sortiranje(niz, n);
	cout << "sortiran niz: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << endl;
	}
}