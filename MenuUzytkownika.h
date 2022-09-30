#ifndef MENUUZYTKOWNIKA_H
#define MENUUZYTKOWNIKA_H

#include <iostream>

#include "MetodyPomocnicze.h"

using namespace std;

class MenuUzytkownika
{
    char wybor;

public:
    void wyswietlMenuUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();

    char pobierzWyborOpcjiZMenuUzytkownika();
    void ustawWybor(char aktualnyWybor);
};

#endif
