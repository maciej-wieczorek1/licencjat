#include "bellmanFord.h"
#include "generatorPowtorzen.h"
#include "pliki.h"
#include "miniTesty.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

#include "json-develop/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

json wczytaniePlikuJson(string nazwaPliku) {
	ifstream plik(nazwaPliku);
	json j;
	plik >> j;
	return j;
}

//zapis testownia liczb calkowitych
json zapisDoPlikuJson(json plikTestowy, long long n, double czas) {
	plikTestowy["powtorzenia"].push_back(n);
	plikTestowy["czas"].push_back(czas);

	return plikTestowy;
}

//zapis calkowania float
json zapisTestowaniaCalkowania(json plikTestowy, float powtorzenia, double czas) {
	plikTestowy["powtorzenia"].push_back(powtorzenia);
	plikTestowy["czas"].push_back(czas);
	return plikTestowy;
}
// zapis testowania calkowania double
json zapisTestowaniaCalkowaniaDouble(json plikTestowy, double powtorzenia, double czas) {
	plikTestowy["powtorzenia"].push_back(powtorzenia);
	plikTestowy["czas"].push_back(czas);
	return plikTestowy;
}

void testowanieMetody(json plikTestowy, void(func(long long zmienna)), string nazwaPliku) {
	long long pom = 0;
	json plikTestowyWyniki;

	for (json::iterator it = plikTestowy.begin(); it != plikTestowy.end(); ++it) {
		auto n = it.value().size(); // zliczenie ilosci powtorzen
		for (long long i = 0; i < n; ++i) {
			pom = it.value()[i];
			auto start = chrono::high_resolution_clock::now();
			func(pom);
			auto koniec = chrono::high_resolution_clock::now();
			auto wynik = chrono::duration_cast<chrono::milliseconds>(koniec - start);
			plikTestowyWyniki = zapisDoPlikuJson(plikTestowyWyniki, pom, wynik.count());
		}
	}
	ofstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikTestowyWyniki << endl;
	plik.close();

}

void testowanieCalkowania(json plikTestowy, void(func(float b)), string nazwaPliku) {
	float zakresKoncowy = 0; // zakres ko�cowy ca�kowania
	json plikTestowyWyniki;

	for (json::iterator it = plikTestowy.begin(); it != plikTestowy.end(); ++it) {
		auto n = it.value().size(); // zliczenie ilosci powtorzen
		for (int i = 0; i < n; ++i) {
			zakresKoncowy = it.value()[i];
			auto start = chrono::high_resolution_clock::now();
			func(zakresKoncowy);
			auto koniec = chrono::high_resolution_clock::now();
			auto wynik = chrono::duration_cast<chrono::milliseconds>(koniec - start);
			plikTestowyWyniki = zapisTestowaniaCalkowania(plikTestowyWyniki, zakresKoncowy, wynik.count());
		}
	}
	ofstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikTestowyWyniki << endl;
	plik.close();
}
void testowanieCalkowaniaDouble(json plikTestowy, void(func(double b)), string nazwaPliku) {
	double zakresKoncowy = 0; // zakres ko�cowy ca�kowania
	json plikTestowyWyniki;

	for (json::iterator it = plikTestowy.begin(); it != plikTestowy.end(); ++it) {
		auto n = it.value().size(); // zliczenie ilosci powtorzen
		for (int i = 0; i < n; ++i) {
			zakresKoncowy = it.value()[i];
			auto start = chrono::high_resolution_clock::now();
			func(zakresKoncowy);
			auto koniec = chrono::high_resolution_clock::now();
			auto wynik = chrono::duration_cast<chrono::milliseconds>(koniec - start);
			plikTestowyWyniki = zapisTestowaniaCalkowaniaDouble(plikTestowyWyniki, zakresKoncowy, wynik.count());
		}
	}
	ofstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikTestowyWyniki << endl;
	plik.close();
}

/// graf
json zapisTestowanieGrafu(json plikTestowy, int powtorzenia, double czas) {
	plikTestowy["powtorzenia"].push_back(powtorzenia);
	plikTestowy["czas"].push_back(czas);
	return plikTestowy;
}

//testowanie grafu

void testowanieBellmanaFordaNaLiscie(json plikTestowy, void(func(list<Krawedz> graf, int wierzcholki)), string nazwaPliku) {
	list<Krawedz> tworzenieGrafu;
	auto n = 0;
	json plikTestowyWyniki;
	int* wierzcholki = new int[plikTestowy["wierzcholki"].size()];
	int *krawedzie= new int[plikTestowy["krawedzie"].size()];
	for (json::iterator it = plikTestowy.begin(); it != plikTestowy.end(); it++) {
		n = it.value().size(); 
		if (it.key() == "wierzcholki") {
			for (int i = 0; i < n; i++) {
				wierzcholki[i] = it.value()[i];
			}
		}
		if (it.key() == "krawedzie") {
			for (int i = 0; i < n; i++){
				krawedzie[i] = it.value()[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		tworzenieGrafu = tworzenieGrafuLista(krawedzie[i], wierzcholki[i]);
		auto start = chrono::high_resolution_clock::now();
		bellmanFordNaLiscie(tworzenieGrafu, wierzcholki[i]);
		auto koniec = chrono::high_resolution_clock::now();
		auto wynik = chrono::duration_cast<chrono::milliseconds>(koniec - start);
		plikTestowyWyniki = zapisTestowanieGrafu(plikTestowyWyniki, krawedzie[i] * wierzcholki[i], wynik.count());
	}
	delete[] wierzcholki;
	delete[] krawedzie;
	ofstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikTestowyWyniki << endl;
	plik.close();
}

void testowanieBellmanaFordaNaVectorze(json plikTestowy, void(func(vector<Krawedz> graf, int wierzcholki)), string nazwaPliku) {
	vector<Krawedz> tworzenieGrafu;
	auto n = 0;
	json plikTestowyWyniki;
	int* wierzcholki = new int[plikTestowy["wierzcholki"].size()];
	int* krawedzie = new int[plikTestowy["krawedzie"].size()];
	for (json::iterator it = plikTestowy.begin(); it != plikTestowy.end(); it++) {
		n = it.value().size(); // zliczenie ilosci powtorzen
		if (it.key() == "wierzcholki") {
			for (int i = 0; i < n; i++) {
				wierzcholki[i] = it.value()[i];
			}
		}
		if (it.key() == "krawedzie") {
			for (int i = 0; i < n; i++) {
				krawedzie[i] = it.value()[i];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		tworzenieGrafu = tworzenieGrafuVector(krawedzie[i], wierzcholki[i]);
		auto start = chrono::high_resolution_clock::now();
		bellmanFordNaVektorze(tworzenieGrafu, wierzcholki[i]);
		auto koniec = chrono::high_resolution_clock::now();
		auto wynik = chrono::duration_cast<chrono::milliseconds>(koniec - start);
		plikTestowyWyniki = zapisTestowanieGrafu(plikTestowyWyniki, wierzcholki[i] * krawedzie[i], wynik.count());
	}
	delete[] wierzcholki;
	delete[] krawedzie;
	ofstream plik(nazwaPliku);
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikTestowyWyniki << endl;
	plik.close();
}
