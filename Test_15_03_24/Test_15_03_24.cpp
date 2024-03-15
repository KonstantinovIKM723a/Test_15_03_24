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
    //Ініціалізуємо масив цілих чисел довжиною n елементів значеннями від -9 до 9
    for (int i = 0; i < n; i++) a[i] = rand() % 19 - 9;




}