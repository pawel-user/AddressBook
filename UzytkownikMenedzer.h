#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "Adresat.h"
#include "MenuGlowne.h"
#include "MenuUzytkownika.h"
#include "PlikZUzytkownikami.h"
#include "MenedzerAdresatow.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    char wybor;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();

    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();

    int pobierzIdZalogowanegoUzytkownika();
};

#endif
