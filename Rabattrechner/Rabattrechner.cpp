#include <iostream>

uint32_t Kategorie;
float WarenWert;
float Rabatt;

int main() {

    while(true) {
    
        Kategorie = 0;
        WarenWert = 0;
        Rabatt = 0;

        std::cout << "Geben sie die Kategorie ein: ";
        std::cin >> Kategorie;

        std::cout << "Geben sie den Warenwert ein (netto): ";
        std::cin >> WarenWert;

        switch (Kategorie) {

        case 1:
            Rabatt = 0.1f;
            break;
        case 2:
            Rabatt = 0.12f;
            break;
        case 3:
            Rabatt = 0.15f;
            break;
        case 4:
            Rabatt = 0.2f;
            break;
        case 5:
            Rabatt = 0.3f;
            break;
        default:
            Rabatt = .0f;
            break;
        }

        std::cout << "\n\n----------------Rechnung------------------\n";
        std::cout << "Netto: " << WarenWert << "\n";
        std::cout << "Rabatt: " << WarenWert * Rabatt << "\n";

        WarenWert -= Rabatt * WarenWert;

        std::cout << "Mwst: " << WarenWert * 0.19f << "\n";

        WarenWert += WarenWert * 0.19f;

        std::cout << "Butto: " << WarenWert << "\n";
        std::cout << "\nVielen Dank f\x81r ihren Einkauf!\n\n";

        std::cout << "Wollen sie das Programm wiederholen? [J]a | [N]ein\n";

        char Antwort;
        std::cin >> Antwort;

        if (Antwort != 'J' && Antwort != 'j') {
            break;
        }

        system("cls");
    }    
}