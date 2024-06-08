#include "wszystkieTesty.h"
#include "pliki.h"
#include "generatorPowtorzen.h"
#include "miniTesty.h"
#include "bellmanFord.h"

void wszystkieTesty() {
	//laczenie petli
	testowanieMetody(wczytaniePlikuJson("tests.json"), laczeniePetli, "Wyniki testow/laczenie petli.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), laczeniePetliOptymalizacja, "Wyniki testow/laczenie petli optymalizacja.json");
	cout << "laczenie petli" << endl;

	//rozwijanie petli
	testowanieMetody(wczytaniePlikuJson("tests.json"), rozwijaniePetli, "Wyniki testow/rozwijanie petli.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), rozwijaniePetliOptymalizacja, "Wyniki testow/rozwijanie petli optymalizacja.json");
	cout << "rozwijanie petli" << endl;

	//zliczanie petli w dol
	testowanieMetody(wczytaniePlikuJson("tests.json"), zliczaniePetli, "Wyniki testow/zliczanie petli.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), zliczaniePetliOptymalizacja, "Wyniki testow/zliczanie petli optymalizacja.json");
	cout << "zliczanie petli w dol" << endl;

	// petla ++i
	testowanieMetody(wczytaniePlikuJson("tests.json"), iteratorPetli, "Wyniki testow/iterator ++i.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), iteratorPetliOptymalizacja, "Wyniki testow/iterator ++i optymalizacja.json");
	cout << "petla ++i" << endl;

	// uproszczenie operacji algebraicznych
	testowanieMetody(wczytaniePlikuJson("tests.json"), uproszczenieOperacjiAlgebraicznych, "Wyniki testow/uproszczenie operacji algebraicznych.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), uproszczenieOperacjiAlgebraicznychOptymalizacja, "Wyniki testow/uproszczenie operacji algebraicznych optymalizacja.json");
	cout << "uproszczenie operacji algebraicznych" << endl;

	// test funkcji inline
	testowanieMetody(wczytaniePlikuJson("tests.json"), testFunkcjiDodawania, "Wyniki testow/test funkcji inline.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), testFunkcjiInline, "Wyniki testow/test funkcji inline optymalizacja.json");
	cout << "test funkcji inline" << endl;

	// usuniecie zbednych wywolan funkcji 
	testowanieMetody(wczytaniePlikuJson("tests.json"), usuniecieZbednychWywolanFunkcji, "Wyniki testow/usuniecie zbednych wywolan z funkcji.json");
	testowanieMetody(wczytaniePlikuJson("tests.json"), usuniecieZbednychWywolanFunkcjiOptymalizacja, "Wyniki testow/usuniecie zbednych wywolan z funkcji optymalizacja.json");
	cout << "Usuniecie zbednych wywolan funckji z petli" << endl;

	// test calkowania
	testowanieCalkowania(wczytaniePlikuJson("testsFloat.json"), calkaFloat, "Wyniki testow/calkowanie.json");
	testowanieCalkowaniaDouble(wczytaniePlikuJson("testsFloat.json"), calkaDouble, "Wyniki testow/calkowanie optymalizacja.json");
	cout << "calkowanie" << endl;

	//testowanie struktur danych
	testowanieMetody(wczytaniePlikuJson("struktury danych.json"), testowanieListy, "Wyniki testow/struktury danych.json");
	testowanieMetody(wczytaniePlikuJson("struktury danych.json"), testowanieVectorow, "Wyniki testow/struktury danych optymalizacja.json");
	cout << "struktury danych" << endl;

	//odczytywanie i zapisywanie ze standardowego wej�cia/wyj�cia
	testowanieMetody(wczytaniePlikuJson("mniejsze testy.json"), odczytywanieZapisywanieZeStandardowegoWejsciaWyjscia, "Wyniki testow/odczytywanie i zapisywanie ze standardowego wejscia wyjscia.json");
	testowanieMetody(wczytaniePlikuJson("mniejsze testy.json"), odczytywanieZapisywanieZeStandardowegoWejsciaWyjsciaOptymalizacja, "Wyniki testow/odczytywanie i zapisywanie ze standardowego wejscia wyjscia optymalizacja.json");
	cout << "Odczytywanie i zapisywanie ze standardowego wejscia.wyjscia" << endl;

	//bellman ford
	testowanieBellmanaFordaNaLiscie(wczytaniePlikuJson("nowyGraf.json"), bellmanFordNaLiscie, "Wyniki testow/bellman ford lista.json");
	testowanieBellmanaFordaNaVectorze(wczytaniePlikuJson("nowyGraf.json"), bellmanFordNaVektorze, "Wyniki testow/bellman ford vector.json");
	cout << "bellman ford" << endl;



}