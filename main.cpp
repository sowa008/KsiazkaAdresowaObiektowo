#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"
#include "AdresatManager.h"
#include "Uzytkownik.h"
#include "Adresat.h"

using namespace std;

int main()
{
    int idZalogowanegoUzytkownika = 0;
    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt", "Adresaci-plik_tymczasowy");

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            char wybor=ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                idZalogowanegoUzytkownika=ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char wybor;
            if (true)

                wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
              case '2':
                  ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                  break;
              case '3':
                  ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                  break;
              case '4':
                  ksiazkaAdresowa.wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
                  break;
              case '5':
                  idUsunietegoAdresata = ksiazkaAdresowa.usunAdresata();
                  idOstatniegoAdresata = ksiazkaAdresowa.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                  break;
           /*   case '6':
                  edytujAdresata(adresaci);
                  break; */
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                idZalogowanegoUzytkownika=ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
                break;
            }
        }
    }

    return 0;
}
