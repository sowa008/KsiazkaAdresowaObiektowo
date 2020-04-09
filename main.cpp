#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"

using namespace std;

int main()
{
    int idZalogowanegoUzytkownika = 0;
    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //UzytkownikManager uzytkownikManager("Uzytkownicy.txt");

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
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
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
            //if (adresaci.empty() == true)
                if (true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                //idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

           wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
           /* case '1':
                idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                wyswietlWszystkichAdresatow(adresaci);
                break;
            case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break; */
            case '7':
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
              //  adresaci.clear();
                break;
            }
        }
    }

    return 0;
}
