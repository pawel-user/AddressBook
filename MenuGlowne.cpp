#include "MenuGlowne.h"

char MenuGlowne::dokonajWyboru()
{
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

void MenuGlowne::ustawWybor(char aktualnyWybor)
{
    wybor = aktualnyWybor;
}

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
