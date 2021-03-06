#include "MetodyPomocnicze.h"
#include "UzytkownikManager.h"

bool MetodyPomocnicze :: czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

int MetodyPomocnicze :: konwersjaStringNaInt(string tekst)
{
    int liczbaInt;
    istringstream iss(tekst);
    iss >> liczbaInt;
    return liczbaInt;
}

string MetodyPomocnicze :: konwersjaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

char MetodyPomocnicze :: wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string MetodyPomocnicze :: wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

