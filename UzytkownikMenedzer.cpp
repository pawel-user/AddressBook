#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::wyswietlMenuGlowne()
{
    menuGlowne.wyswietlMenuGlowne();
}

char UzytkownikMenedzer::wybierzOpcjeZMenuGlownego()
{
    return(menuGlowne.wybierzOpcjeZMenuGlownego());
}

void UzytkownikMenedzer::wyswietlMenuUzytkownika()
{
    menuUzytkownika.wyswietlMenuUzytkownika();
}

char UzytkownikMenedzer::wybierzOpcjeZMenuUzytkownika()
{
    return(menuUzytkownika.wybierzOpcjeZMenuUzytkownika());
}

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                    if (uzytkownicy[i].pobierzHaslo() == haslo)
                    {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system("pause");
                        idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                        return;
                    }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idZalogowanegoUzytkownika = 0;
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem." << endl << endl;
    system("pause");
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << endl << "Haslo zostalo zmienione." << endl;
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    cout << "Pomyslnie wylogowales sie." << endl;

    return idZalogowanegoUzytkownika;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int aktualneIdZalogowanegoUzytkownika)
{
    if(aktualneIdZalogowanegoUzytkownika >= 0)
        idZalogowanegoUzytkownika = aktualneIdZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wyswietlKomunikatBrakOpcji()
{
    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
    system("pause");
}

