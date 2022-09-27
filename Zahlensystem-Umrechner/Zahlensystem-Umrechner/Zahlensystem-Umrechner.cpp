#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

std::string ConvertNumberToBase(uint64_t number, uint8_t base);
std::string ToSymbolString(std::vector<uint8_t> vec);
int ConvertInputStringToNumber(std::string input, int base);

void PrintFirstMenu();
void PrintSecondMenu();

void ExecuteFirstMenuOption();
void ExecuteSecondMenuOption();

bool MenuNavigation(int& MenuIndex, int PressedKey, int min, int max);

void SetConsoleColor(int color);
void ClearConsole(bool pause = false);
void SetCursorVisibility(bool visible);

char symbols[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

std::string InputString = "";

int InputNumber = 0;
int FirstMenuIndex = 0;
int SecondMenuIndex = 0;

int main() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("Zahlensystem-Umrechner V1.0");

    ClearConsole();

    while (true) {

        while (true) {

            PrintFirstMenu();
            if (MenuNavigation(FirstMenuIndex, _getch(), 0, 3)) break;
        }

        ExecuteFirstMenuOption();

        while (true) {

            PrintSecondMenu();
            if (MenuNavigation(SecondMenuIndex, _getch(), 0, 2)) break;
        }

        ExecuteSecondMenuOption();
    }
}

bool MenuNavigation(int& MenuIndex, int PressedKey, int min, int max) {

    if (PressedKey == 80) MenuIndex++;
    if (PressedKey == 72) MenuIndex--;

    if (MenuIndex < min) MenuIndex = min;
    if (MenuIndex > max) MenuIndex = max;

    ClearConsole();

    return PressedKey == 13 ? true : false;
}

void ExecuteFirstMenuOption() {

    SetCursorVisibility(true);

    switch (FirstMenuIndex) {

    case 0:
        std::cout << "   Please enter a Decimal-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 10);
        break;

    case 1:
        std::cout << "   Please enter a Binary-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 2);
        break;

    case 2:
        std::cout << "   Please enter a Hexadecimal-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 16);
        break;

    case 3:
        exit(0);
        break;
    }

    ClearConsole();
}

void ExecuteSecondMenuOption() {

    switch (FirstMenuIndex) {

    case 0:
        std::cout << "   Decimal-Input: ";
        break;

    case 1:
        std::cout << "   Binary-Input: ";
        break;

    case 2:
        std::cout << "   Hexadecimal-Input: ";
        break;
    }

    SetConsoleColor(12);

    std::cout << InputString << "\n   ";

    SetConsoleColor(10);

    switch (SecondMenuIndex) {

    case 0:
        std::cout << "Decimal-Number: ";
        SetConsoleColor(12);
        std::cout << InputNumber;
        break;

    case 1:
        std::cout << "Binary-Number: ";
        SetConsoleColor(12);
        std::cout << ConvertNumberToBase(InputNumber, 2);
        break;

    case 2:
        std::cout << "Hexadecimal-Number: ";
        SetConsoleColor(12);
        std::cout << ConvertNumberToBase(InputNumber, 16);
        break;
    }

    std::cout << "\n\n   ";

    ClearConsole(true);
}

void PrintFirstMenu() {

    std::cout << (FirstMenuIndex == 0 ? " > " : "   ") << "Input Decimal-Number\n";
    std::cout << (FirstMenuIndex == 1 ? " > " : "   ") << "Input Binary-Number\n";
    std::cout << (FirstMenuIndex == 2 ? " > " : "   ") << "Input Hexadecimal-Number\n";
    std::cout << (FirstMenuIndex == 3 ? " > " : "   ") << "Exit Program\n";
}

void PrintSecondMenu() {

    std::cout << "   Input: ";

    SetConsoleColor(12);

    std::cout << InputString << "\n\n";

    SetConsoleColor(10);

    std::cout << (SecondMenuIndex == 0 ? " > " : "   ") << "Convert Number to Decimal\n";
    std::cout << (SecondMenuIndex == 1 ? " > " : "   ") << "Convert Number to Binary\n";
    std::cout << (SecondMenuIndex == 2 ? " > " : "   ") << "Convert Number to Hexadecimal\n";
}

std::string ConvertNumberToBase(uint64_t number, uint8_t base) {

    std::vector<uint8_t> vec;
    uint64_t rest;
    std::string result;

    while (true) {

        rest = number % base;
        number = number / base;
        vec.push_back(rest);

        if (number <= 0) break;
    }

    return ToSymbolString(vec);
}

std::string ToSymbolString(std::vector<uint8_t> vec) {

    std::string SymbolString;

    for (auto symbol : vec)
        SymbolString = symbols[symbol] + SymbolString;

    return SymbolString;
}

int ConvertInputStringToNumber(std::string input, int base) {

    int number = 0;
    std::vector<uint8_t> vec;

    for (int inputIterator = input.length() - 1; inputIterator >= 0; inputIterator--)
        for (int symbolIterator = 0; symbolIterator < sizeof(symbols); symbolIterator++)
            if (toupper(input[inputIterator]) == symbols[symbolIterator])
                vec.push_back(symbolIterator);

    for (int i = 0; i < vec.size(); i++)
        number += (vec[i] * pow(base, i));

    return number;
}

void ClearConsole(bool pause) {

    SetConsoleColor(10);
    SetCursorVisibility(false);

    if (pause) system("pause");

    system("cls");

    SetConsoleColor(11);

    std::cout << "\n   *******************************************\n";
    std::cout << "   ******* Zahlensystem-Umrechner V1.0 *******\n";
    std::cout << "   *******************************************\n\n";

    SetConsoleColor(10);
}

void SetConsoleColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void SetCursorVisibility(bool visible) {

    CONSOLE_CURSOR_INFO info;
    info.dwSize = 20;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}