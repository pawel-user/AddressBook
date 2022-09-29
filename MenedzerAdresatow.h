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
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    MenedzerAdresatow(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void wylogowanieUzytkownika();
    int dodajAdresata();
    void wypiszAdresatowZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();

    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdOstatniegoAdresata();
    int pobierzIdUsunietegoAdresata();
    void ustawIdZalogowanegoUzytkownika(int aktualneIdZalogowanegoUzytkownika);
    void ustawIdOstatniegoAdresata(int aktualneIdOstatniegoAdresata);
    void ustawIdUsunietegoAdresata(int aktualneIdUsunietegoAdresata);

};

#endif
