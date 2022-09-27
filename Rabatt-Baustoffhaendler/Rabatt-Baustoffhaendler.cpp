#include <cstdlib>
#include <iostream>
#include <windows.h>

//Bad habit
using namespace std;

float Rabattsatz = 1.0f;
double Preis, Warenwert, Netto, Rabatt, Mwst, Brutto;
uint32_t Anzahl;

void getUserInput();
void calculateInvoice();
void outputInvoice();

int main() {

    locale::global(locale("German_germany.UTF-8"));
    SetConsoleTitleA("Rabatt-Warenwert Rechner für Dachpfannen");

    getUserInput();
    calculateInvoice();
    outputInvoice();

    exit(0);
}

void getUserInput() {

    cout << "Bitte den Netto Stückpreis eingeben (in Euro): ";
    cin >> Preis;

    cout << "Bitte geben Sie die Anzahl ein: ";
    cin >> Anzahl;
}

void calculateInvoice() {

    if (Anzahl >= 500)
        Rabattsatz = 6.5f;

    Warenwert = Preis * Anzahl;
    Netto = Warenwert - (Warenwert / 100.0) * Rabattsatz;
    Rabatt = Rabattsatz == 1.0f ? 0 : Warenwert - Netto;
    Mwst = Netto * .19;
    Brutto = Netto + Mwst;
}

void outputInvoice() {

    cout << "\n\n*****************************************\n";
    cout << "******** Rechnung Baustoffzentrum *******\n";
    cout << "*****************************************\n";

    cout << "Anzahl der Dachpfannen:\t" << Anzahl << " Stück\n";

    cout << "Rabatt:\t\t\t" << Rabatt << " EURO\n";
    cout << "Nettobetrag:\t\t" << Netto << " EURO\n";

    cout << "Mehrwertsteuer:\t\t" << Mwst << " EURO\n";
    cout << "Bruttobetrag:\t\t" << Brutto << " EURO\n";
}