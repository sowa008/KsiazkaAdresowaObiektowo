#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>

using namespace std;

class Adresat
{

public:
    int idAdresata;
    int idZalogowanegoUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

    Adresat(int idAdresata=0, int idZalogowanegoUzytkownika=0, string imie="", string nazwisko="", string numerTelefonu="", string email="", string adres="")
    {}

    void ustawIdAdresata(int idOstatniegoAdresata);
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzIdAdresata();
    int pobierzIdZalogowanegoUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif
