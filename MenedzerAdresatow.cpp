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

void MenedzerAdresatow::wylogowanieUzytkownika()
{
    adresaci.clear();
    idZalogowanegoUzytkownika = 0;
}

void MenedzerAdresatow::ustawIdZalogowanegoUzytkownika(int aktualneIdZalogowanegoUzytkownika)
{
    if(aktualneIdZalogowanegoUzytkownika >= 0)
    {
        idZalogowanegoUzytkownika = aktualneIdZalogowanegoUzytkownika;
    }
}

void MenedzerAdresatow::ustawIdOstatniegoAdresata(int aktualneIdOstatniegoAdresata)
{
    if(aktualneIdOstatniegoAdresata >= 0)
    {
        idOstatniegoAdresata = aktualneIdOstatniegoAdresata;
    }
}

void MenedzerAdresatow::ustawIdUsunietegoAdresata(int aktualneIdUsunietegoAdresata)
{
    if(aktualneIdUsunietegoAdresata >= 0)
    {
        idUsunietegoAdresata = aktualneIdUsunietegoAdresata;
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

void MenedzerAdresatow::wypiszAdresatowZalogowanegoUzytkownika()
{
    cout << endl;

    for (int i = 0; i < (int) adresaci.size(); i++)
    {
        cout << adresaci[i].pobierzId() << endl;
        cout << adresaci[i].pobierzIdUzytkownika() << endl;
        cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
        cout << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << adresaci[i].pobierzEmail() << endl;
        cout << adresaci[i].pobierzAdres() << endl << endl;
    }
    system("pause");
}

void MenedzerAdresatow::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIdZalogowanegoUzytkownika());
    idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void MenedzerAdresatow::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (int i = 0; i < (int) adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
            cout << endl;
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void MenedzerAdresatow::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
