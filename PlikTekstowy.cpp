#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty()
{
    fstream plikTekstowy;

    plikTekstowy.seekp(0, ios::end);

    if (plikTekstowy.tellp() == 0)
        return true;
    else
        return false;
}

void PlikTekstowy::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikTekstowy::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}
