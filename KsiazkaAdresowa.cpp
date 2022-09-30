#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::zarzadzajMenuGlowne()
{
    while (true)
    {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            uzytkownikMenedzer.wyswietlMenuGlowne();
            //uzytkownikMenedzer.dokonajWyboruOpcjiZMenuGlownego();

            switch (uzytkownikMenedzer.wybierzOpcjeZMenuGlownego())
            {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownikMenedzer.logowanieUzytkownika();
                menedzerAdresatow.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
                menedzerAdresatow.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                break;
            case '9':
                exit(0);
                break;
            default:
                uzytkownikMenedzer.wyswietlKomunikatBrakOpcji();
                break;
            }
        }
        else
        {
            zarzadzajMenuUzytkownika();
        }
    }
}

void KsiazkaAdresowa::zarzadzajMenuUzytkownika()
{
    uzytkownikMenedzer.wyswietlMenuUzytkownika();

    switch (uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika())
    {
    case '1':
        menedzerAdresatow.ustawIdOstatniegoAdresata(menedzerAdresatow.pobierzIdOstatniegoAdresata());
        menedzerAdresatow.dodajAdresata();
        break;
    case '4':
        menedzerAdresatow.wypiszAdresatowZalogowanegoUzytkownika();
        break;
    case '7':
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
        break;
    case '8':
        menedzerAdresatow.wylogowanieUzytkownika();
        uzytkownikMenedzer.wylogowanieUzytkownika();
        break;
    default:
        uzytkownikMenedzer.wyswietlKomunikatBrakOpcji();
        break;
    }
}
