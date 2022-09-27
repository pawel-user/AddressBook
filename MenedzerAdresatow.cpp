#include "MenedzerAdresatow.h"

int MenedzerAdresatow::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

int MenedzerAdresatow::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

int MenedzerAdresatow::pobierzIdUsunietegoAdresata()
{
    return idUsunietegoAdresata;
}

/*Adresat MenedzerAdresatow::pobierzAdresata()
{
    return adresat;
}*/

void MenedzerAdresatow::ustawIdZalogowanegoUzytkownika(int aktualneIdZalogowanegoUzytkownika)
{
    if(aktualneIdZalogowanegoUzytkownika >= 0)
    {
        idZalogowanegoUzytkownika = aktualneIdZalogowanegoUzytkownika;
        cout << "idZalogowanegoUzytkownika = " << idZalogowanegoUzytkownika << endl;
    }
}

void MenedzerAdresatow::ustawIdOstatniegoAdresata(int aktualneIdOstatniegoAdresata)
{
    if(aktualneIdOstatniegoAdresata >= 0)
    {
        idOstatniegoAdresata = aktualneIdOstatniegoAdresata;
        cout << "idOstatniegoAdresata = " << idOstatniegoAdresata << endl;
        system("pause");
    }
}

void MenedzerAdresatow::ustawIdUsunietegoAdresata(int aktualneIdUsunietegoAdresata)
{
    if(aktualneIdUsunietegoAdresata >= 0)
    {
        idUsunietegoAdresata = aktualneIdUsunietegoAdresata;
        cout << "idUsunietegoAdresata = " << idUsunietegoAdresata << endl;
    }
}

int MenedzerAdresatow::dodajAdresata()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat MenedzerAdresatow::podajDaneNowegoAdresata()
{
    Adresat adresat;
    adresat.ustawId(++idOstatniegoAdresata);
    cout << "Test: " << pobierzIdOstatniegoAdresata() << endl;
    system("pause");
    adresat.ustawIdUzytkownika(pobierzIdZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

string MenedzerAdresatow::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

/*void MenedzerAdresatow::dopiszAdresataDoPliku()
{
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}*/

void MenedzerAdresatow::wypiszAdresatowZalogowanegoUzytkownika()
{
    for (int i = 0; i < (int) adresaci.size(); i++)
    {
        cout << adresaci[i].pobierzId() << adresaci[i].pobierzId() << endl;
        cout << adresaci[i].pobierzIdUzytkownika() << adresaci[i].pobierzIdUzytkownika() << endl;
        cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
        cout << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << adresaci[i].pobierzEmail() << endl;
        cout << adresaci[i].pobierzAdres() << endl;
    }
}

void MenedzerAdresatow::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    ustawIdOstatniegoAdresata(plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, pobierzIdZalogowanegoUzytkownika()));
}
