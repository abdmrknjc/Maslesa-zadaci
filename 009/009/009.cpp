/*
Napisati program koji će omogućiti unos cjelobrojnih parnih vrijednosti sa neparnim brojem cifara
u jednodimenzionalni niz od 20 elemenata a zatim napraviti funkciju koja ce primati kao argument taj niz.
Funkcija treba da izbaci iz niza sve brojeve koji su djeljivi sa 6 a da ostavi u nizu sve ostale brojeve.
Izbacivanje brojeva se treba napraviti tako da se ostatak niza pomjeri u lijevo da ne bi bilo praznih elemenata.
To pomjeranje je potrebno uraditi prilikom izbacivanja svakog elementa a ne na kraju pošto su svi elementi djeljivi sa 6.
*/

#include <iostream>
using namespace std;
const int vel = 20;

void unos(int niz[], int vel) {
	int broj=0;
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite " << i+1 << ". paran broj sa neparnim brojem cifara : " << endl;
		cin >> broj;
		int pomocnazabroj = broj;
		int brojacCifara = 0;
		while (broj>0){
			broj /= 10;
			brojacCifara++;
		}
		if (pomocnazabroj%2!=0||brojacCifara%2==0) {
			cout << "Unesite broj ponovo, uslovi nisu ispunjeni. " << endl;
			i--;
		}
		else
			niz[i] = pomocnazabroj;
	}
}

void uklanjanjeElemenata(int niz[], int& stvarnaVel) {
	int indeks = 0;
	for (int i = 0; i < vel; i++)
	{
		if (niz[i]%6!=0){
			niz[indeks++] = niz[i];
		}
	}
	stvarnaVel = indeks;
}

int main() {
	int niz[vel];
	int stvarnaVel = 0;
	unos(niz, vel);
	uklanjanjeElemenata(niz, stvarnaVel);
	cout << "ISPIS: " << endl;
	for (int i = 0; i < stvarnaVel; i++)
		cout << niz[i]<<endl;
}