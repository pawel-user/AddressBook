#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            ksiazkaAdresowa.wyswietlMenuGlowne();

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuGlownego())
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                ksiazkaAdresowa.wyswietlKomunikatBrakOpcji();
                break;
            }
        }
        else
        {
            ksiazkaAdresowa.wyswietlMenuUzytkownika();

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika())
            {
            case '1':
                if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
                {
                    ksiazkaAdresowa.dodajAdresata();
                }
                else
                {
                    cout << "Aby dodac adresata nalezy najpierw sie zalogowac." << endl;
                    system("pause");
                }
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            default:
                ksiazkaAdresowa.wyswietlKomunikatBrakOpcji();
                break;
            }
        }
    }
    return 0;
}
