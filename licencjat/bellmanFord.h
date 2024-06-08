#ifndef bellmanFord_h
#define bellmanFord_h
#include <list>
#include <vector>

using namespace std;

struct Krawedz {
	int a;
	int b;
	int waga;
};

void bellmanFordNaLiscie(list<Krawedz> graf, int wierzcholki);
void bellmanFordNaVektorze(vector<Krawedz> graf, int wierzcholki);

list<Krawedz> tworzenieGrafuLista(int krawedzie, int wierzcholki);
vector<Krawedz> tworzenieGrafuVector(int krawedzie, int wierzcholki);
//wyswietleniegrafu
void printGrafList(list<Krawedz> graf);
void printGrafVector(vector<Krawedz> graf);

#endif
