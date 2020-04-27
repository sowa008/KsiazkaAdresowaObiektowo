#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa
{
    const string NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    MetodyPomocnicze metodaPomocnicza;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego)
    : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI (nazwaPlikuTymczasowego)
    {
    adresatManager=NULL;
    };

    ~KsiazkaAdresowa()
    {
    delete adresatManager;
    adresatManager=NULL;
    }

    void dodajAdresata();
    void usunAdresata();
    void rejestracjaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();

};

#endif
