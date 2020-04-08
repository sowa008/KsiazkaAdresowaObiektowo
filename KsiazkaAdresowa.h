#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    MetodyPomocnicze metodaPomocnicza;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami){
    uzytkownikManager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();

};

#endif
