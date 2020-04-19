#include "AdresatManager.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

Adresat AdresatManager :: podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

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

void AdresatManager :: wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.idAdresata << endl;
    cout << "Imie:               " << adresat.imie << endl;
    cout << "Nazwisko:           " << adresat.nazwisko << endl;
    cout << "Numer telefonu:     " << adresat.numerTelefonu << endl;
    cout << "Email:              " << adresat.email << endl;
    cout << "Adres:              " << adresat.adres << endl;
}

void AdresatManager :: wyswietlWszystkichAdresatowZalogowanegoUzytkownika()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
