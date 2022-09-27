#include <iostream>

uint16_t Familienmitglieder;
uint16_t Jahre;
uint16_t Rabatt;
float Gebühren = 40.0f;

int main()
{
    std::cout << "Geben sie die anzahl an Familienmitgliedern an:\n";
    std::cin >> Familienmitglieder;

    std::cout << "Geben sie die Dauer ihrer Mitgleidschaft in Jahren an:\n";
    std::cin >> Jahre;

    std::cout << "\n";

    if (Familienmitglieder == 2)
        Rabatt = 5;

    else if (Familienmitglieder == 3)
        Rabatt = 15;

    else if (Familienmitglieder >= 4)
        Rabatt = 20;

    Gebühren = Gebühren / 100.f * (100.f - Rabatt);

    if (Jahre >= 5) {
        Gebühren = Gebühren / 100 * 95;
        std::cout << "Langzeitrabatt: 5%\n";
    }
        
    std::cout << "Familienrabatt: " << Rabatt << "%\n";
    std::cout << "Mitgliedsbeitrag: " << Gebühren << " Eugen\n";
    std::cout << "Mitgliedsbeitrag fuer die ganze Familie: " << Gebühren * Familienmitglieder << " Eugen";

    exit(0);
}