#include "UzytkownikManager.h"
#include "PlikZUzytkownikami.h"

void UzytkownikManager :: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager :: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login, haslo;
   // MetodyPomocnicze metodaPomocnicza;

    do
    {
        cout << "Podaj login: ";
        //uzytkownik.login = metodaPomocnicza.wczytajLinie();
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    //uzytkownik.haslo = metodaPomocnicza.wczytajLinie();
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager :: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager :: czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    } return false;
}

void UzytkownikManager :: wypiszWszystkichUzytkownikow()
{
for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikManager :: logowanieUzytkownika()
{
   // Uzytkownik uzytkownik;
   // uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
   // MetodyPomocnicze metodaPomocnicza;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze :: wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze :: wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie. Twoj numer id wynosi " <<  idZalogowanegoUzytkownika << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikManager :: zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    MetodyPomocnicze metodaPomocnicza;
   // PlikZUzytkownikami plikZUzytkownikami(nazwaPlikuZUzytkownikami);
    noweHaslo = metodaPomocnicza.wczytajLinie();
   // Uzytkownik uzytkownicy;
    vector <Uzytkownik> uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();

    //cout << "Id zalogowanego uzytkownika: " << idZalogowanegoUzytkownika << endl;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        //cout << itr -> id << " " << itr -> haslo << endl;
        if (itr -> id == idZalogowanegoUzytkownika)
        {
            itr -> haslo = noweHaslo;
            cout << "Haslo zostalo zmienione." <<endl << endl;
           // system("pause");
        }
    } system("pause");
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UzytkownikManager :: czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
    {
        return true;
    }
    else return false;
}

int UzytkownikManager :: pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
