#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 10;
    float a[n];

    srand(time(NULL));
    //���������� ����� ����� ����� �������� n �������� ���������� �� -9 �� 9
    for (int i = 0; i < n; i++) a[i] = rand() % 19 - 9;




}