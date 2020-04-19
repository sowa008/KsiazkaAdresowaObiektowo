#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;
    MetodyPomocnicze metodaPomocnicza;
    int noweIdZalogowanegoUzytkownika;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami),
    adresatManager(nazwaPlikuZAdresatami, noweIdZalogowanegoUzytkownika )
    {
    uzytkownikManager.wczytajUzytkownikowZPliku();
    };

  /*  KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami){
    uzytkownikManager.wczytajUzytkownikowZPliku();
    };
*/
    void dodajAdresata();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();


};

#endif
