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
    static int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    MenuGlowne menuGlowne;
    MenuUzytkownika menuUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void wyswietlMenuGlowne();
    char wybierzOpcjeZMenuGlownego();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void logowanieUzytkownika();
    void wyswietlKomunikatBrakOpcji();

    void wyswietlMenuUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int wylogowanieUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int aktualneIdZalogowanegoUzytkownika);
};

#endif
