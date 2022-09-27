#include <iostream>
#include <Windows.h>

using namespace std;

uint32_t number1, number2;
char opperation;

void Rechner1(uint32_t number1, uint32_t number2, char opperant);
void Rechner2(uint32_t number1, uint32_t number2, char opperant);
void Rechner3(uint32_t number1, uint32_t number2, char opperant);

int main() {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13);
    SetConsoleTitleA("Taschenrechner V1.0");

    cout << "Bitte geben Sie die erste Nummer ein:\n";
    cin >> number1;

    cout << "Bitte geben Sie den Rechen-Opperator ein:\n";
    cin >> opperation;

    cout << "Bitte geben Sie die zweite Nummer ein:\n";
    cin >> number2;

    //Rechner1(number1, number2, opperation);
    //Rechner2(number1, number2, opperation);
    Rechner3(number1, number2, opperation);

    system("pause");
    exit(0);
}

void Rechner1(uint32_t number1, uint32_t number2, char opperant) {

    float result = 0;

    if (opperant == '+')
        result = number1 + number2;

    else if (opperant == '-')
        result = number1 - number2;

    else if (opperant == '/')
        result = (float)number1 / (float)number2;

    else if (opperant == '*')
        result = number1 * number2;

    cout << number1 << " " << opperant << " " << number2 << " = " << result << "\n";
}

void Rechner2(uint32_t number1, uint32_t number2, char opperant) {

    float result = 0;

    switch (opperant) {

    case '+':
        result = number1 + number2;
        break;

    case '-':
        result = number1 - number2;
        break;

    case '/':
        result = (float)number1 / (float)number2;
        break;

    case '*':
        result = number1 * number2;
        break;

    default:
        result = 0;
        break;
    }

    cout << number1 << " " << opperant << " " << number2 << " = " << result << "\n";
}

void Rechner3(uint32_t number1, uint32_t number2, char opperant) {

    float result = 0;

    result = opperant == '+' ? number1 + number2 : result;
    result = opperant == '-' ? number1 - number2 : result;
    result = opperant == '/' ? (float)number1 / (float)number2 : result;
    result = opperant == '*' ? number1 * number2 : result;

    cout << number1 << " " << opperant << " " << number2 << " = " << result << "\n";
}