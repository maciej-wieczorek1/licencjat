#include "generatorPowtorzen.h"
#include "json-develop/single_include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
using json = nlohmann::json;

void generator() {
	generatorTestowMaleLiczby(100000);
	generatorTestowDuzeLiczby(1000000000);
	generatorTestowCalkowanie(100000000); 
	generatorTestowStrukturyDanych(10000000);
	nowyGraf(1000);
}

void generatorTestowMaleLiczby(long long zakresKoncowy) {
	json plikJson;
	auto pom = 0;
	plikJson["powtorzenia"].push_back(0);
	plikJson["powtorzenia"].push_back(100);
	plikJson["powtorzenia"].push_back(1000);
	for (int i = 10000; i < zakresKoncowy; i *= 10) {
		for (int j = 1; j < 10; j++) {
			pom = j * i;
			plikJson["powtorzenia"].push_back(pom);
		}
	}
	plikJson["powtorzenia"].push_back(zakresKoncowy);
	ofstream plik("mniejsze testy.json");
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikJson << "\n";
	plik.close();
}

void generatorTestowDuzeLiczby(long long zakresKoncowy) {
	json plikJson;
	long long pom = 0;
	plikJson["powtorzenia"].push_back(0);
	plikJson["powtorzenia"].push_back(10000);
	plikJson["powtorzenia"].push_back(100000);
	for (long long i = 1000000; i < zakresKoncowy; i *= 10) {
		for (int j = 1; j < 10; j++) {
			pom = j * i;
			plikJson["powtorzenia"].push_back(pom);
		}
	}
	plikJson["powtorzenia"].push_back(zakresKoncowy);
	ofstream plik("tests.json");
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikJson << "\n";
	plik.close();
}


void generatorTestowCalkowanie(long long zakresKoncowy) {
	json plikJson;
	double pom = 0;
	plikJson["powtorzenia"].push_back(0.0);
	plikJson["powtorzenia"].push_back(100.0);
	plikJson["powtorzenia"].push_back(1000.0);
	plikJson["powtorzenia"].push_back(10000.0);
	plikJson["powtorzenia"].push_back(100000.0);
	for (long long i = 1000000; i < zakresKoncowy; i *= 10) {
		for (int j = 1; j < 10; j++) {
			pom = j * i;
			plikJson["powtorzenia"].push_back(pom);
		}
	}
	plikJson["powtorzenia"].push_back(zakresKoncowy);
	ofstream plik("testsFloat.json");
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikJson << "\n";
	plik.close();
}

void generatorTestowStrukturyDanych(int zakresKoncowy) {
	json plikJson;
	auto pom = 0;
	plikJson["powtorzenia"].push_back(0);
	plikJson["powtorzenia"].push_back(100);
	plikJson["powtorzenia"].push_back(1000);
	for (int i = 10000; i < zakresKoncowy; i *= 10) {
		for (int j = 1; j < 10; j++) {
			pom = j * i;
			plikJson["powtorzenia"].push_back(pom);
		}
	}
	plikJson["powtorzenia"].push_back(zakresKoncowy);
	ofstream plik("struktury danych.json");
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << plikJson << "\n";
	plik.close();

}

// graf x wierzcholkow i 2x krawedzi
void nowyGraf(int wierzcholki) {

	auto pom = 0;;
	json dane;
	ofstream plik("nowyGraf.json");
	dane["wierzcholki"].push_back(0);
	dane["krawedzie"].push_back(0);
	for (int i = 100; i <= wierzcholki; i *= 10) {
		for (int j = 1; j < 10; j++) {
			pom = j * i;
			dane["wierzcholki"].push_back(pom);
			dane["krawedzie"].push_back(pom * 2);
		}
	}
	if (!plik.is_open()) {
		cerr << "Blad przy otwieraniu pliku do zapisu." << endl;
		return;
	}
	plik << setw(4) << dane << endl;
	plik.close();
}


