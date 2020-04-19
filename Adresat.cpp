#include "Adresat.h"

void Adresat :: ustawIdAdresata(int idOstatniegoAdresata)
{
    if (idOstatniegoAdresata >= 0)
        idAdresata=idOstatniegoAdresata;
}

void Adresat :: ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    if (noweIdZalogowanegoUzytkownika >= 0)
        idZalogowanegoUzytkownika=noweIdZalogowanegoUzytkownika;
}

void Adresat :: ustawImie(string noweImie)
{
    imie=noweImie;
}

void Adresat :: ustawNazwisko(string noweNazwisko)
{
    nazwisko=noweNazwisko;
}

void Adresat :: ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu=nowyNumerTelefonu;
}

void Adresat :: ustawEmail(string nowyEmail)
{
    email=nowyEmail;
}

void Adresat :: ustawAdres(string nowyAdres)
{
    adres=nowyAdres;
}

int Adresat :: pobierzIdAdresata()
{
    return idAdresata;
}

int Adresat :: pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

string Adresat :: pobierzImie()
{
    return imie;
}

string Adresat :: pobierzNazwisko()
{
    return nazwisko;
}

string Adresat :: pobierzNumerTelefonu()
{
    return numerTelefonu;
}

string Adresat :: pobierzEmail()
{
    return email;
}

string Adresat :: pobierzAdres()
{
    return adres;
}
