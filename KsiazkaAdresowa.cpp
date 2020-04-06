#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"

UzytkownikManager uzytkownikManager;

KsiazkaAdresowa :: KsiazkaAdresowa()
{
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
