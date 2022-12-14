#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

//Function declaration since no header files are allowed
std::string ConvertNumberToBase(uint64_t number, uint8_t base);
int ConvertInputStringToNumber(std::string input, int base);

void PrintFirstMenu();
void PrintSecondMenu();

void ExecuteFirstMenuOption();
void ExecuteSecondMenuOption();

bool MenuNavigation(int& MenuIndex, int PressedKey, int min, int max);

void SetConsoleColor(int color);
void ClearConsole(bool pause = false);
void SetCursorVisibility(bool visible);

//Symbol array, can be extended to support more number systems
char symbols[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

//Global variables
std::string InputString = "";
int InputNumber = 0;
int FirstMenuIndex = 0;
int SecondMenuIndex = 0;

int main() {

    //Set Console Title accordingly
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("Zahlensystem-Umrechner V1.0");

    //Clears the console and print the heading
    ClearConsole();

    //Infinite loop to enable repetition of the program
    while (true) {

        //Display first menu to select the system for the input number
        while (true) {

            //Prints out the first menu
            PrintFirstMenu();

            //Break out of the loop if an option is pressed
            if (MenuNavigation(FirstMenuIndex, _getch(), 0, 3)) break;
        }

        //Asks for the input number in the selected system
        ExecuteFirstMenuOption();

        //Display second menu to select the system for the output number
        while (true) {

            //Prints out the second menu
            PrintSecondMenu();

            //Break out of the loop if an option is pressed
            if (MenuNavigation(SecondMenuIndex, _getch(), 0, 2)) break;
        }

        //Prints the input number and the output number in the correct number system
        ExecuteSecondMenuOption();
    }
}

//Navigates through an menu by increasing or decreasing of the Index. Returns true if the return key (13) is pressed
bool MenuNavigation(int& MenuIndex, int PressedKey, int min, int max) {

    //Increase or decrease the menu index if up or down arrow is pressed
    if (PressedKey == 80) MenuIndex++;
    if (PressedKey == 72) MenuIndex--;

    //Set the menu index back into its range if its to high or to low
    if (MenuIndex < min) MenuIndex = min;
    if (MenuIndex > max) MenuIndex = max;

    //Clears the console and print the heading
    ClearConsole();

    //Return true if the return key is pressed
    return PressedKey == 13 ? true : false;
}

//Asks for a number in the selected number system
void ExecuteFirstMenuOption() {

    //Set cursor visible since user input is required
    SetCursorVisibility(true);

    switch (FirstMenuIndex) {

    case 0:
        //Ask for a dec number and convert it to an integer
        std::cout << "   Please enter a Decimal-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 10);
        break;

    case 1:
        //Ask for a bin number and convert it to an integer
        std::cout << "   Please enter a Binary-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 2);
        break;

    case 2:
        //Ask for a hex number and convert it to an integer
        std::cout << "   Please enter a Hexadecimal-Number: ";
        SetConsoleColor(12);
        std::cin >> InputString;
        InputNumber = ConvertInputStringToNumber(InputString, 16);
        break;

    case 3:
        //Exit the program if exit is selected
        exit(0);
        break;
    }

    ClearConsole();
}

//Outputs the input number and the converted number
void ExecuteSecondMenuOption() {

    //Display the number system of the input number
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

    //Display input number
    std::cout << InputString << "\n   ";

    SetConsoleColor(10);

    //Display the converted number
    switch (SecondMenuIndex) {

    case 0:
        //Display the number in decimal
        std::cout << "Decimal-Number: ";
        SetConsoleColor(12);
        std::cout << InputNumber;
        break;

    case 1:
        //Display the number in binary
        std::cout << "Binary-Number: ";
        SetConsoleColor(12);
        std::cout << ConvertNumberToBase(InputNumber, 2);
        break;

    case 2:
        //Display the number in hexadecimal
        std::cout << "Hexadecimal-Number: ";
        SetConsoleColor(12);
        std::cout << ConvertNumberToBase(InputNumber, 16);
        break;
    }

    std::cout << "\n\n   ";

    ClearConsole(true);
}

//Prints the first menu
void PrintFirstMenu() {

    std::cout << (FirstMenuIndex == 0 ? " > " : "   ") << "Input Decimal-Number\n";
    std::cout << (FirstMenuIndex == 1 ? " > " : "   ") << "Input Binary-Number\n";
    std::cout << (FirstMenuIndex == 2 ? " > " : "   ") << "Input Hexadecimal-Number\n";
    std::cout << (FirstMenuIndex == 3 ? " > " : "   ") << "Exit Program\n";
}

//Prints the second menu
void PrintSecondMenu() {

    std::cout << "   Input: ";

    SetConsoleColor(12);

    std::cout << InputString << "\n\n";

    SetConsoleColor(10);

    std::cout << (SecondMenuIndex == 0 ? " > " : "   ") << "Convert Number to Decimal\n";
    std::cout << (SecondMenuIndex == 1 ? " > " : "   ") << "Convert Number to Binary\n";
    std::cout << (SecondMenuIndex == 2 ? " > " : "   ") << "Convert Number to Hexadecimal\n";
}

//Converts a number to a different base and returns the number as a string
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

    for (auto symbol : vec)
        result = symbols[symbol] + result;

    return result;
}

//Converts a given string to an integer with the corresponding base, similar to stoi()
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

//Clears the console, pauses if enabled and prints the heading
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

//Sets the color of the console to the given color index
void SetConsoleColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//Sets the visibility of the cursor
void SetCursorVisibility(bool visible) {

    CONSOLE_CURSOR_INFO info;
    info.dwSize = 20;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}