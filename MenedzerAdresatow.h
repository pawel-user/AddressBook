#ifndef MENEDZERADRESATOW_H
#define MENEDZERADRESATOW_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class MenedzerAdresatow
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idUsuwanegoAdresata;
    char wybor;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();


public:
    MenedzerAdresatow(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), plikZAdresatami(nazwaPlikuZAdresatami)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        idUsuwanegoAdresata = 0;
    };
    char wybierzOpcjeZMenuUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
};

#endif
