#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze
{

public:
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static int konwersjaStringNaInt(string tekst);
    static string konwersjaIntNaString(int liczba);
    static char wczytajZnak();
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
