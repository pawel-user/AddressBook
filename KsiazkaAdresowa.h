#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "MenedzerAdresatow.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    MenedzerAdresatow *menedzerAdresatow;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        menedzerAdresatow = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete menedzerAdresatow;
        menedzerAdresatow = NULL;
    };
    bool czyUzytkownikJestZalogowany();

    void wyswietlMenuGlowne();
    char wybierzOpcjeZMenuGlownego();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wyswietlKomunikatBrakOpcji();

    void wyswietlMenuUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edytujAdresata();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
};

#endif
