#include "Header1.h"
#include <string>
using namespace std;
// ���������� ���������� n
bool factorial(int n, int result[], int& size) {
    result[0] = 1; // ��������� �������� 1
    size = 1;

    for (int i = 2; i <= n; ++i) {
        int carry = 0; // �������
        for (int j = 0; j < size; ++j) {
            int product = result[j] * i + carry; // �������� ������� ����� �� i
            result[j] = product % 10;           // ��������� ��������� �����
            carry = product / 10;               // ������� ���������
        }

        // ��������� ���������� �������
        while (carry > 0) {
            if (size >= MAX_SIZE) return false; // ������������
            result[size++] = carry % 10;
            carry /= 10;
        }
    }

    return true;
}

// ���������� �������� ���������� (n!)!
bool doubleFactorial(int n, int result[], int& size) {
    int factN[MAX_SIZE] = { 0 }; // ������ ��� �������� n!
    int factSize = 0;

    // ������� ��������� n!
    if (!factorial(n, factN, factSize)) {
        return false; // ������������ ��� ���������� n!
    }

    // ����������� n! � �����
    int factValue = 0;
    for (int i = factSize - 1; i >= 0; --i) {
        factValue = factValue * 10 + factN[i];
        if (factValue > MAX_SIZE) return false; // ������������
    }

    // ������ ��������� (n!)!
    result[0] = 1;
    size = 1;

    for (int i = 2; i <= factValue; ++i) {
        int carry = 0; // �������
        for (int j = 0; j < size; ++j) {
            int product = result[j] * i + carry; // �������� ������� �����
            result[j] = product % 10;           // ��������� �����
            carry = product / 10;               // �������
        }

        // ������������ ���������� �������
        while (carry > 0) {
            if (size >= MAX_SIZE) return false; // ������������
            result[size++] = carry % 10;
            carry /= 10;
        }
    }

    return true;
}

// ����� �������� �����
void printNumber(const int result[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        cout << result[i];
    }
}
//�������� �������� �� ������ ����� ������
bool isInteger(const std::string& input) {
    if (input.empty()) return false;
    for (char ch : input) {
        if (!isdigit(ch)) return false; // ���� ������ �� �����, ��� �� ����� �����
    }
    return true;
}
// �������������� ������ � ����� �����
bool stringToInt(const std::string& input, int& number) {
    if (!isInteger(input)) return false; // ���������, �������� �� ������ ������

    number = 0;
    for (char ch : input) {
        number = number * 10 + (ch - '0'); // ����������� ������ � ����� � ���������
        if (number < 0) return false;     // ��������� �� ������������
    }
    return true;
}