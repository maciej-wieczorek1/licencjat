#ifndef miniTesty_h
#define miniTesty_h

void laczeniePetli(long long n);
void laczeniePetliOptymalizacja(long long n);
void rozwijaniePetli(long long n);
void rozwijaniePetliOptymalizacja(long long n);
void zliczaniePetli(long long n);
void zliczaniePetliOptymalizacja(long long n);
void uproszczenieOperacjiAlgebraicznych(long long n);
void uproszczenieOperacjiAlgebraicznychOptymalizacja(long long n);

// funkcje inline
long long dodawanie(long long a, long long b);
inline long long dodawanieOptymalizacja(long long a, long long b);
void testFunkcjiDodawania(long long n);
void testFunkcjiInline(long long n);
//calkowanie
float funFloat(float x);
double funDouble(double x);
void calkaFloat(float b);
void calkaDouble(double b);

// iterowanie petli
void iteratorPetli(long long n);
void iteratorPetliOptymalizacja(long long n);

// usuniecie zbednych wywolan funckji z petli
void usuniecieZbednychWywolanFunkcji(long long n);
void usuniecieZbednychWywolanFunkcjiOptymalizacja(long long n);

// Odczytywanie/zapisywanie ze standardowego wej�cia/wyj�cia
void odczytywanieZapisywanieZeStandardowegoWejsciaWyjscia(long long n);
void odczytywanieZapisywanieZeStandardowegoWejsciaWyjsciaOptymalizacja(long long n);

//struktury danych
void testowanieVectorow(long long n);
void testowanieListy(long long n);


#endif