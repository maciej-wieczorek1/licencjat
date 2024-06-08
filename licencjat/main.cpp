
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>
#include <string>
#include <set>
#include <Windows.h>
#include <direct.h>


#include "generatorPowtorzen.h"
#include "miniTesty.h"
#include "bellmanFord.h"
#include "pliki.h"
#include "wszystkieTesty.h"

#include "json-develop/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;


int main() {
	string folder = "Wyniki testow";

	if (_mkdir("Wyniki testow") == -1) {
		cout << "Folder juz istnieje" << endl;
	}
	else {
		cout << "Folder utworzony" << endl;
	}
	cout << "Zakres testow skonczony" << "\n";

	generator();
	wszystkieTesty();

	cout << endl << "Koniec";
	return 0;
}

