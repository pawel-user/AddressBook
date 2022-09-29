#ifndef MENUGLOWNE_H
#define MENUGLOWNE_H

#include <iostream>

#include "MetodyPomocnicze.h"

using namespace std;

class MenuGlowne
{
    char wybor;

public:
    void wyswietlMenuGlowne();
    char dokonajWyboru();

    void ustawWybor(char aktualnyWybor);
};

#endif
