#include "miniTesty.h"
#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

void laczeniePetli(long long n) {
	long long suma = 0;
	long long sumaDrugaPetla = 0;
	long long sumaTrzeciaPetla = 0;
	long long sumaCzwartaPetla = 0;
	long long sumaPiataPetla = 0;

	for (long long i = 0; i < n; i++) {
		suma += i;
	}
	for (long long i = 0; i < n; i++) {
		sumaDrugaPetla += i + i;
	}
	for (long long i = 0; i < n; i++) {
		sumaTrzeciaPetla += i + i;
	}
	for (long long i = 0; i < n; i++) {
		sumaCzwartaPetla += i + i;
	}
	for (long long i = 0; i < n; i++) {
		sumaPiataPetla += i + i;
	}
}

void laczeniePetliOptymalizacja(long long n) {
	long long suma = 0;
	long long sumaDrugaPetla = 0;
	long long sumaTrzeciaPetla = 0;
	long long sumaCzwartaPetla = 0;
	long long sumaPiataPetla = 0;

	for (long long i = 0; i < n; i++) {
		suma += i;
		sumaDrugaPetla += i + i;
		sumaTrzeciaPetla += i + i;
		sumaCzwartaPetla += i + i;
		sumaPiataPetla += i + i;
	}
}


void rozwijaniePetli(long long n) {
	long long suma = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j <= 10; j++) {
			suma += j;
		}
	}
}

void rozwijaniePetliOptymalizacja(long long n) {
	long long suma = 0;
	for (long long i = 0; i < n; i++) {
		suma += 0;
		suma += 1;
		suma += 2;
		suma += 3;
		suma += 4;
		suma += 5;
		suma += 6;
		suma += 7;
		suma += 8;
		suma += 9;
		suma += 10;
	}
}


void zliczaniePetli(long long n) {
	long long suma = 0;
	for (long long i = 0; i < n; ++i) {
		suma += i;
	}
}



void zliczaniePetliOptymalizacja(long long n) {
	long long suma = 0;
	for (long long i = n-1; i >= 0; --i) {
		suma += i;
	}
}


// iterator petli
void iteratorPetli(long long n) {
	vector<long long> pom;
	long long suma = 0;
	for (long long i = 0; i < n; ++i) {
		pom.push_back(i);
	}

	for (vector<long long>::iterator iter = pom.begin(); iter != pom.end(); ++iter) {
		suma += *iter;
	}
}

void iteratorPetliOptymalizacja(long long n) {
	vector<long long> pom;
	long long suma = 0;
	for (long long i = 0; i < n; ++i) {
		pom.push_back(i);
	}

	for (vector<long long>::iterator iter = pom.begin(); iter != pom.end(); ++iter) {
		suma += *iter;
	}
}

void uproszczenieOperacjiAlgebraicznych(long long n) {
	long long y = 0, x = 2, a = 10, b = 12, c = 4, d = 9;
	for (long long i = 0; i < n; ++i) {
		y = a * x * x * x + b * x * x + c * x + d;
	}
}

void uproszczenieOperacjiAlgebraicznychOptymalizacja(long long n) {
	long long y = 0, x = 2, a = 10, b = 12, c = 4, d = 9;
	for (long long i = 0; i < n; ++i) {
		y = (((a * x + b) * x) + c) * x + d;
	}
}


// calkowanie
float funFloat(float x) {
	return (x * x - 2 * x + 3);
}
void calkaFloat(float b) {
	float pom = 0;
	for (double i = 0; i < b; ++i) {
		pom += funFloat(i) * 0.1;
	}
	/*return pom;*/
}

double funDouble(double x) {
	return (x * x - 2 * x + 3);
}
void calkaDouble(double b) {
	double pom = 0;
	for (double i = 0; i < b; ++i) {
		pom += funDouble(i) * 0.1;
	}
	//return pom;
}

void usuniecieZbednychWywolanFunkcji(long long n) {
	string generowanyNapis;
	generowanyNapis.reserve(n);
	for (long long i = 0; i < n; ++i) {
		if (i % 3 == 0) {
			generowanyNapis.push_back(' ');
		}
		else {
			generowanyNapis.push_back('a' + (i % 26));
		}
	}

	for (long long i = 0; i < generowanyNapis.length(); ++i) {
		if (generowanyNapis[i] == ' ') {
			generowanyNapis[i] = '_';
		}
	}
}

void usuniecieZbednychWywolanFunkcjiOptymalizacja(long long n) {
	string generowanyNapis;
	generowanyNapis.reserve(n);
	for (long long i = 0; i < n; ++i) {
		if (i % 3 == 0) {
			generowanyNapis.push_back(' ');
		}
		else {
			generowanyNapis.push_back('a' + (i % 26));
		}
	}
	auto szukanyNapis = ' ';
	long long pom = generowanyNapis.length();
	for (long long i = 0; i < pom; i++) {
		if (generowanyNapis[i] == szukanyNapis) {
			generowanyNapis[i] = '_';
		}
	}
}

long long dodawanie(long long a, long long b) {
	return a + b;
}

inline long long dodawanieOptymalizacja(long long a, long long b) {
	return a + b;
}


void testFunkcjiDodawania(long long n) {
	long long suma = 0;
	for (int i = 0; i < n; i++) {
		suma += dodawanie(i, i);
	}
}

void testFunkcjiInline(long long n) {
	long long suma = 0;
	for (long long i = 0; i < n; i++) {
		suma += dodawanieOptymalizacja(i, i);
	}
}

void odczytywanieZapisywanieZeStandardowegoWejsciaWyjscia(long long n) {
	for (long long i = 0; i < n; i++) {
		long long pom = rand();
		cout << pom << endl;
	}
}

void odczytywanieZapisywanieZeStandardowegoWejsciaWyjsciaOptymalizacja(long long n) {
	ios_base::sync_with_stdio(false);
	for (long long i = 0; i < n; i++) {
		long long pom = rand();
		cout << pom << endl;

	}
}


// struktury danych
void testowanieVectorow(long long n) {
	vector<long long> dane;
	long long pom;
	for (long long i = 0; i < n; i++) {
		pom = rand() % n;
		dane.push_back(pom);
	}
	dane.clear();
}

void testowanieListy(long long n) {
	list<long long> lista;
	long long pom;
	for (long long i = 0; i < n; i++) {
		pom = rand() % n;
		lista.push_back(pom);
	}
	lista.clear();
}
