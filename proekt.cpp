#include <iostream>
#include "Header1.h"
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Ru");
    string input;
    cout << "Введите число n (n >= 3): ";
    cin >> input;

    int n;
    // Проверяем, что введённое значение — целое число, и преобразуем его
    if (!stringToInt(input, n)) {
        cerr << "Ошибка: введено не правильное число" << endl;
        return 1;
    }
    if (n < 3) {
        cerr << "Ошибка: n должно быть >= 3." << endl;
        return 1;
    }

    int result[MAX_SIZE] = { 0 }; // Массив для хранения результата
    int size = 0;              // Размер числа в массиве

    if (doubleFactorial(n, result, size)) {
        cout << "(" << n << "!)! = ";
        printNumber(result, size);
        cout << endl;
    }
    else {
        cerr << "Ошибка: переполнение." << endl;
    }

    return 0;
}
