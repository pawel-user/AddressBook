#include "KsiazkaAdresowa.h"

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wyswietlMenuGlowne()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        menedzerAdresatow = new MenedzerAdresatow(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wyswietlKomunikatBrakOpcji()
{
    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
    system("pause");
}

void KsiazkaAdresowa::wyswietlMenuUzytkownika()
{
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    return menedzerAdresatow->wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    menedzerAdresatow->dodajAdresata();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    menedzerAdresatow->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    menedzerAdresatow->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::usunAdresata()
{
    menedzerAdresatow->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata()
{
    menedzerAdresatow->edytujAdresata();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete menedzerAdresatow;
    menedzerAdresatow = NULL;
}
