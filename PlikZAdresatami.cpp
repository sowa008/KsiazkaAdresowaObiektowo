#include "PlikZAdresatami.h"
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <vector>

string PlikZAdresatami :: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.idAdresata) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.idZalogowanegoUzytkownika) + '|';
    liniaZDanymiAdresata += adresat.imie + '|';
    liniaZDanymiAdresata += adresat.nazwisko + '|';
    liniaZDanymiAdresata += adresat.numerTelefonu + '|';
    liniaZDanymiAdresata += adresat.email + '|';
    liniaZDanymiAdresata += adresat.adres + '|';

    return liniaZDanymiAdresata;
}

string PlikZAdresatami :: pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.idAdresata = atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 2:
                adresat.idZalogowanegoUzytkownika = atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 3:
                adresat.imie = pojedynczaDanaAdresata;
                break;
            case 4:
                adresat.nazwisko = pojedynczaDanaAdresata;
                break;
            case 5:
                adresat.numerTelefonu = pojedynczaDanaAdresata;
                break;
            case 6:
                adresat.email = pojedynczaDanaAdresata;
                break;
            case 7:
                adresat.adres = pojedynczaDanaAdresata;
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocnicze metodaPomocnicza;
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodaPomocnicza.konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze :: konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

bool PlikZAdresatami :: dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (MetodyPomocnicze::czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }

        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

vector<Adresat> PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(ID_ZALOGOWANEGO_UZYTKOWNIKA == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;

    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();
    return adresaci;
}

vector<Adresat> PlikZAdresatami :: wczytajWszystkichAdresatowZPliku()
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);

        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;

    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();
    return adresaci;
}

int PlikZAdresatami :: pobierzIdOstatniegoAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(ID_ZALOGOWANEGO_UZYTKOWNIKA == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

void PlikZAdresatami :: usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami :: zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami :: przepiszPlikUsuwajacAdresata(int idUsuwanegoAdresata, int idUzytkownika)
{
    vector <Adresat> wektorAdresatowZalogowanegoUzytkownika = wczytajAdresatowZalogowanegoUzytkownikaZPliku(idUzytkownika);
    vector <Adresat> wektorWszystkichAdresatow = wczytajWszystkichAdresatowZPliku();
    vector <Adresat> wektorWynikowy;

    for (int i=0; i<wektorWszystkichAdresatow.size(); i++)
    {
        if (wektorWszystkichAdresatow[i].idZalogowanegoUzytkownika != idUzytkownika)
        {
            wektorWynikowy.push_back(wektorWszystkichAdresatow[i]);
        }
        else
        {
            for (int j=0; j<wektorAdresatowZalogowanegoUzytkownika.size(); j++)
            {
                if (wektorAdresatowZalogowanegoUzytkownika[j].idAdresata == wektorWszystkichAdresatow[i].idAdresata)
                {
                    wektorWynikowy.push_back(wektorAdresatowZalogowanegoUzytkownika[j]);
                }
            }
        }
    }

    fstream tymczasowyPlikTekstowy;
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out);

    for (int i=0; i<wektorWynikowy.size(); i++)
    {
        Adresat dane_adresata = wektorWynikowy[i];

            if (dane_adresata.idAdresata != idUsuwanegoAdresata)
            {
                    tymczasowyPlikTekstowy << dane_adresata.idAdresata << "|";
                    tymczasowyPlikTekstowy << dane_adresata.idZalogowanegoUzytkownika << "|";
                    tymczasowyPlikTekstowy << dane_adresata.imie << "|";
                    tymczasowyPlikTekstowy << dane_adresata.nazwisko << "|";
                    tymczasowyPlikTekstowy << dane_adresata.numerTelefonu << "|";
                    tymczasowyPlikTekstowy << dane_adresata.email << "|";
                    tymczasowyPlikTekstowy << dane_adresata.adres << "|";

                    if (i<(wektorWynikowy.size()-1)) {tymczasowyPlikTekstowy << endl;}
            }
    }
        tymczasowyPlikTekstowy.close();
        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);

}
