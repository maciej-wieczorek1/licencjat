#ifndef pliki_h
#define pliki_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>

#include "bellmanFord.h"
#include "json-develop/single_include/nlohmann/json.hpp"
using namespace std;

using json = nlohmann::json;
json wczytaniePlikuJson(string nazwaPliku);
json zapisDoPlikuJson(json plikTestowy, long long n, double czas);
void testowanieMetody(json plikTestowy, void(func(long long zmienna)), string fileName);

//zapisanie danych do pliku json testowanie calkowania
json zapisTestowaniaCalkowania(json plikTestowy, float powtorzenia, double czas);
json zapisTestowaniaCalkowaniaDouble(json plikTestowy, double powtorzenia, double czas);
void testowanieCalkowania(json plikTestowy, void(func(float b)), string nazwaPliku);
void testowanieCalkowaniaDouble(json plikTestowy, void(func(double b)), string nazwaPliku);

// graf
void testowanieBellmanaFordaNaLiscie(json plikTestowy, void(fun(list<Krawedz> graf, int wierzcholki)), string nazwaPliku);
void testowanieBellmanaFordaNaVectorze(json plikTestowy, void(fun(vector<Krawedz> graf, int wierzcholki)), string nazwaPliku);
#endif