#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>
#include <vector>

using namespace std;

class Uzytkownik
{
public:
    int id;
    string login;
    string haslo;
    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
