#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"
#include "AdresatManager.h"

void KsiazkaAdresowa :: dodajAdresata()
{
    adresatManager->dodajAdresata();
}

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa :: wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager = NULL;
}

int KsiazkaAdresowa :: pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: usunAdresata()
{
    adresatManager->usunAdresata();
}

void KsiazkaAdresowa :: edytujAdresata()
{
    adresatManager->edytujAdresata();
}

int KsiazkaAdresowa :: podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
{
    return adresatManager->podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata, idOstatniegoAdresata);
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatowZalogowanegoUzytkownika()
{
    adresatManager->wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wyszukajAdresatowPoImieniu()
{
    adresatManager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa :: wyszukajAdresatowPoNazwisku()
{
    adresatManager->wyszukajAdresatowPoNazwisku();
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodaPomocnicza.wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodaPomocnicza.wczytajZnak();

    return wybor;
}
