#include "MenedzerAdresatow.h"

MenedzerAdresatow::MenedzerAdresatow()
{
    idOstatniegoAdresata = 0;
    idUsunietegoAdresata = 0;
}

int MenedzerAdresatow::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    //dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat MenedzerAdresatow::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawId(UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    adresat.pobierzImie() = MetodyPomocnicze::wczytajLinie();
    adresat.pobierzImie() = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie());

    cout << "Podaj nazwisko: ";
    adresat.pobierzNazwisko() = MetodyPomocnicze::wczytajLinie();
    adresat.pobierzNazwisko() = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko());

    cout << "Podaj numer telefonu: ";
    adresat.pobierzNumerTelefonu() = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    adresat.pobierzEmail() = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adresat.pobierzAdres() = MetodyPomocnicze::wczytajLinie();

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
