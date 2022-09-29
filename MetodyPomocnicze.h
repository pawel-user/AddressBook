#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();
};

#endif
