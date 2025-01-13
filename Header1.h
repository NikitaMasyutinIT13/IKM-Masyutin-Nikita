

#include <iostream>
#include <string>

const int MAX_SIZE = 100000; // ������������ ������ ������� ��� �������� �����

// ���������� ���������� n � ���������� ���������� � ������
bool factorial(int n, int result[], int& size);

// ���������� �������� ���������� (n!)! � ���������� ���������� � ������
bool doubleFactorial(int n, int result[], int& size);

// ����� �������� ����� �� �������
void printNumber(const int result[], int size);

//�������� �������� �� �������� ������ ����� ������ 
bool isInteger(const std::string& input);

// �������������� ������ � ����� �����
bool stringToInt(const std::string& input, int& number);