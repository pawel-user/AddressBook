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
    char wybierzOpcjeZMenuGlownego();

    char pobierzWyborOpcjiZMenuGlownego();
    void ustawWybor(char aktualnyWybor);
};

#endif
