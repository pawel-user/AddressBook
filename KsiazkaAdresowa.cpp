#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    menedzerAdresatow.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    menedzerAdresatow.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    menedzerAdresatow.wylogowanieUzytkownika();
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    menedzerAdresatow.ustawIdOstatniegoAdresata(menedzerAdresatow.pobierzIdOstatniegoAdresata());
    menedzerAdresatow.dodajAdresata();
}

void KsiazkaAdresowa::wypiszAdresatowZalogowanegoUzytkownika()
{
    menedzerAdresatow.wypiszAdresatowZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    menedzerAdresatow.wyswietlWszystkichAdresatow();
}
