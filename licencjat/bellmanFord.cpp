#include "bellmanFord.h"
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

void bellmanFordNaLiscie(list<Krawedz> graf, int wierzcholki) {
	int* d = new int[wierzcholki];
	for (int i = 0; i < wierzcholki; i++) {
		d[i] = INT_MAX;
	}
	d[0] = 0;
	for (int i = 0; i < wierzcholki - 1; i++) {
		for (list<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); iter++) {
			if ((d[iter->b] > d[iter->a] + iter->waga)) {
				d[iter->b] = d[iter->a] + iter->waga;
			}
		}
	}
	for (list<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); iter++) {
		if ((d[iter->b] > d[iter->a] + iter->waga)) {
			cout << "Ujemny cykl" << endl;
			return;
		}
	}
}

void bellmanFordNaVektorze(vector<Krawedz> graf, int wierzcholki) {
	int* d = new int[wierzcholki];
	for (int i = 0; i < wierzcholki; i++) {
		d[i] = INT_MAX;
	}
	d[0] = 0;
	for (int i = 0; i < wierzcholki - 1; i++) {
		for (vector<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); ++iter) {
			if ((d[iter->b] > d[iter->a] + iter->waga)) {
				d[iter->b] = d[iter->a] + iter->waga;
			}
		}
	}
	for (vector<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); ++iter) {
		if ((d[iter->b] > d[iter->a] + iter->waga)) {
			cout << "Ujemny cykl" << endl;
			return;
		}
	}
}

list<Krawedz> tworzenieGrafuLista(int krawedzie, int wierzcholki) {
	srand(time(nullptr));
	list<Krawedz> graf;
	Krawedz pom;
	int maxWaga = 100;
	for (int i = 0; i < krawedzie; i++) {
		int a = 1 + rand() % wierzcholki;
		int b = 1 + rand() % wierzcholki;
		int waga = rand() % (2 * maxWaga + 1) - maxWaga;
		pom.a = a;
		pom.b = b;
		pom.waga = waga;
		graf.push_back(pom);
	}
	return graf;
}

vector<Krawedz> tworzenieGrafuVector(int krawedzie, int wierzcholki) {
	srand(time(nullptr));
	vector<Krawedz>graf;
	Krawedz pom;
	int maxWaga = 100;
	for (int i = 0; i < krawedzie; i++) {
		int a = 1 + rand() % wierzcholki;
		int b = 1 + rand() % wierzcholki;
		int waga = rand() % (2* maxWaga +1) - maxWaga;
		pom.a = a;
		pom.b = b;
		pom.waga = waga;
		graf.push_back(pom);
	}
	return graf;
}

void printGrafList(list<Krawedz>graf) {
	for (list<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); iter++) {
		cout << iter->a << " " << iter->b << " " << iter->waga << endl;
	}
}
void printGrafVector(vector<Krawedz> graf) {
	for (vector<Krawedz>::iterator iter = graf.begin(); iter != graf.end(); iter++) {
		cout << iter->a << " " << iter->b << " " << iter->waga << endl;
	}
}
