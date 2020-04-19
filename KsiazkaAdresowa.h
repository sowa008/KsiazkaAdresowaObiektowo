#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    MetodyPomocnicze metodaPomocnicza;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
    adresatManager=NULL;
    };

    ~KsiazkaAdresowa()
    {
    delete adresatManager;
    adresatManager=NULL;
    }

    void dodajAdresata();
    void rejestracjaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();

};

#endif
