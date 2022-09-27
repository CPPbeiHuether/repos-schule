#include <iostream>
#include <iomanip>

float Zins;
float CashMoney;

int main()
{

	std::cout << "Geben sie das Vermoegen ein: ";
	std::cin >> CashMoney;

	std::cout << "Geben sie den Zuwachs in Prozent ein: ";
	std::cin >> Zins;

	Zins /= 100.f;

	for (size_t i = 1; CashMoney < 1000000; i++)
	{
		CashMoney += CashMoney * Zins;
		std::cout << "Vermoegen in " << i << " Jahren\t" << std::fixed << std::setprecision(2) << CashMoney << " Euro\n";
	}
}