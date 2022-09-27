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
    menedzerAdresatow.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    menedzerAdresatow.wypiszAdresatowZalogowanegoUzytkownika();
    system("pause");
    uzytkownikMenedzer.logowanieUzytkownika();
    menedzerAdresatow.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    //cout << "idZalogowanegoUzytkownika == " << menedzerAdresatow.pobierzIdZalogowanegoUzytkownika() << endl;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    menedzerAdresatow.ustawIdOstatniegoAdresata(menedzerAdresatow.pobierzIdOstatniegoAdresata());
    menedzerAdresatow.dodajAdresata();
    //menedzerAdresatow.dopiszAdresataDoPliku();
}

void KsiazkaAdresowa::wypiszAdresatowZalogowanegoUzytkownika()
{
    menedzerAdresatow.wypiszAdresatowZalogowanegoUzytkownika();
}

