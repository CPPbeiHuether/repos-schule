#include <iostream>
#include <Windows.h>
#include <string>

float Umsatz;
float Zuwachs;
float UmsatzZuwachs;
uint8_t Color = 1;

void RainbowConsole();
void WriteGayLine(std::string Text, bool LineBreak);

int main()
{
	std::cout.precision(420);
	
	std::cout << "Geben sie den Umsatz ein: ";
	std::cin >> Umsatz;
	UmsatzZuwachs = Umsatz;

	std::cout << "Geben sie den Zuwachs in Prozent ein: ";
	std::cin >> Zuwachs;

	Zuwachs /= 100.f;

	for (size_t i = 1; UmsatzZuwachs < (Umsatz * 2); i++)
	{
		UmsatzZuwachs += UmsatzZuwachs * Zuwachs;
		WriteGayLine("Umsatz in " + std::to_string(i) + " Jahren\t" + std::to_string(UmsatzZuwachs) + " Euro", true);
	}
}

void WriteGayLine(std::string Text, bool LineBreak = true) {

	for (auto ch : Text) {
		std::cout << ch;
		RainbowConsole();
	}

	if (LineBreak)
		std::cout << "\n";

}

void RainbowConsole() {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, Color);
	Color++;

	if (Color >= 16)
		Color = 1;
}