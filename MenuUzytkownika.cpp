#include "MenuUzytkownika.h"

void MenuUzytkownika::wyswietlMenuUzytkownika()
{
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    //cout << "5. Usun adresata" << endl;
    //cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
}

char MenuUzytkownika::wybierzOpcjeZMenuUzytkownika()
{
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

char MenuUzytkownika::pobierzWyborOpcjiZMenuUzytkownika()
{
    return wybor;
}

void MenuUzytkownika::ustawWybor(char aktualnyWybor)
{
    wybor = aktualnyWybor;
}

