#include "MenuGlowne.h"

void MenuGlowne::wyswietlMenuGlowne()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
}

char MenuGlowne::wybierzOpcjeZMenuGlownego()
{
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

char MenuGlowne::pobierzWyborOpcjiZMenuGlownego()
{
    return wybor;
}

void MenuGlowne::ustawWybor(char aktualnyWybor)
{
    wybor = aktualnyWybor;
}

