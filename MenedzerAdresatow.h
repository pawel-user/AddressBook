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

    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    Adresat podajDaneNowegoAdresata(UzytkownikMenedzer uzytkownikMenedzer);

public:

};

#endif
