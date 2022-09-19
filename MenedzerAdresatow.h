#ifndef MENEDZERADRESATOW_H
#define MENEDZERADRESATOW_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

class MenedzerAdresatow
{
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

public:
    MenedzerAdresatow();
    int dodajAdresata();
};

#endif
