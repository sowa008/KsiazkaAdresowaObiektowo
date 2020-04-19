#include "AdresatManager.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

Adresat AdresatManager :: podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    // usunalem static z ID_ZALOGOWANEGO_UZYTKOWNIKA
    // teraz jest const i musi byc ustawiane poprzez konstruktor
    adresat.ustawIdAdresata(plikZAdresatami.pobierzIdOstatniegoAdresata(ID_ZALOGOWANEGO_UZYTKOWNIKA)+1);
    adresat.ustawIdZalogowanegoUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);


    cout << "Podaj imie: ";
    imie = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj e-mail: ";
    email = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze :: wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatManager :: dodajAdresata()
{
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);

    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout << "Nowy adresat zostal dodany." << endl;
    }
    else
    {
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    }
    system("pause");
}
