

#include <iostream>
#include <string>

const int MAX_SIZE = 100000; // Максимальный размер массива для хранения числа

// Вычисление факториала n и сохранение результата в массив
bool factorial(int n, int result[], int& size);

// Вычисление двойного факториала (n!)! и сохранение результата в массив
bool doubleFactorial(int n, int result[], int& size);

// Вывод большого числа из массива
void printNumber(const int result[], int size);

//Проверка является ли вводимая строка целым числом 
bool isInteger(const std::string& input);

// Преобразование строки в целое число
bool stringToInt(const std::string& input, int& number);