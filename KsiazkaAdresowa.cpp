#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::zarzadzajMenuGlowne()
{
    while (true)
    {
        if (!uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        {
            uzytkownikMenedzer.wyswietlMenuGlowne();

            switch (uzytkownikMenedzer.wybierzOpcjeZMenuGlownego())
            {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownikMenedzer.logowanieUzytkownika();
                if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
                {
                    menedzerAdresatow = new MenedzerAdresatow(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
                }
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
        if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        {
            menedzerAdresatow->dodajAdresata();
        }
        else
        {
            cout << "Aby dodac adresata nalezy najpierw sie zalogowac." << endl;
            system("pause");
        }
        break;
    case '4':
        menedzerAdresatow->wyswietlWszystkichAdresatow();
        break;
    case '7':
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
        break;
    case '8':
        uzytkownikMenedzer.wylogowanieUzytkownika();
        delete menedzerAdresatow;
        menedzerAdresatow = NULL;
        break;
    default:
        uzytkownikMenedzer.wyswietlKomunikatBrakOpcji();
        break;
    }
}
