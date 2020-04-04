#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"

UzytkownikManager uzytkownikManager;

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
