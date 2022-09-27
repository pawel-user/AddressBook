#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //cout << endl << "Rejestracja uzytkownika:" << endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //cin.sync();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    cout << endl << "Logowanie uzytkownika:" << endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    cin.sync();
    //cout << endl << "Zmiana hasla uzytkownika:" << endl;
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //cin.sync();
    //system("pause");
    cout << endl << "Dodawanie nowego adresata:" << endl;
    system("pause");
    ksiazkaAdresowa.dodajAdresata();
    cin.sync();
    system("pause");
    ksiazkaAdresowa.wypiszAdresatowZalogowanegoUzytkownika();
    cin.sync();
    system("pause");
    cout << endl << "Wylogowanie uzytkownika:" << endl;
    system("pause");
    ksiazkaAdresowa.wylogowanieUzytkownika();


    return 0;
}
