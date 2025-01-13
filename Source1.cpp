#include "Header1.h"
#include <string>
using namespace std;
// Вычисление факториала n
bool factorial(int n, int result[], int& size) {
    result[0] = 1; // Начальное значение 1
    size = 1;

    for (int i = 2; i <= n; ++i) {
        int carry = 0; // Перенос
        for (int j = 0; j < size; ++j) {
            int product = result[j] * i + carry; // Умножаем текущую цифру на i
            result[j] = product % 10;           // Сохраняем последнюю цифру
            carry = product / 10;               // Остаток переносим
        }

        // Добавляем оставшийся перенос
        while (carry > 0) {
            if (size >= MAX_SIZE) return false; // Переполнение
            result[size++] = carry % 10;
            carry /= 10;
        }
    }

    return true;
}

// Вычисление двойного факториала (n!)!
bool doubleFactorial(int n, int result[], int& size) {
    int factN[MAX_SIZE] = { 0 }; // Массив для хранения n!
    int factSize = 0;

    // Сначала вычисляем n!
    if (!factorial(n, factN, factSize)) {
        return false; // Переполнение при вычислении n!
    }

    // Преобразуем n! в число
    int factValue = 0;
    for (int i = factSize - 1; i >= 0; --i) {
        factValue = factValue * 10 + factN[i];
        if (factValue > MAX_SIZE) return false; // Переполнение
    }

    // Теперь вычисляем (n!)!
    result[0] = 1;
    size = 1;

    for (int i = 2; i <= factValue; ++i) {
        int carry = 0; // Перенос
        for (int j = 0; j < size; ++j) {
            int product = result[j] * i + carry; // Умножаем текущую цифру
            result[j] = product % 10;           // Последняя цифра
            carry = product / 10;               // Перенос
        }

        // Обрабатываем оставшийся перенос
        while (carry > 0) {
            if (size >= MAX_SIZE) return false; // Переполнение
            result[size++] = carry % 10;
            carry /= 10;
        }
    }

    return true;
}

// Вывод большого числа
void printNumber(const int result[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        cout << result[i];
    }
}
//Проверка является ли строка целым числом
bool isInteger(const std::string& input) {
    if (input.empty()) return false;
    for (char ch : input) {
        if (!isdigit(ch)) return false; // Если символ не цифра, это не целое число
    }
    return true;
}
// Преобразование строки в целое число
bool stringToInt(const std::string& input, int& number) {
    if (!isInteger(input)) return false; // Проверяем, является ли строка числом

    number = 0;
    for (char ch : input) {
        number = number * 10 + (ch - '0'); // Преобразуем символ в цифру и добавляем
        if (number < 0) return false;     // Проверяем на переполнение
    }
    return true;
}