#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 7;
    int a[n];

    srand(time(NULL));
    //Ініціалізуємо масив цілих чисел довжиною n елементів значеннями від -9 до 9
    cout << "Одновимірний масив: " << endl;
    for (int i = 0; i < n; i++) a[i] = rand() % 19 - 9;

    //Виводимо масив на екран
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    //Сума елементів
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << "Сума елементів: " << sum << endl;

    //Мінімальний і максимальний елементи:
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Максимальний елемент: " << max << endl;

    //Середнє значення елементів:
    float avg = (float) sum/n;
    cout << "Середнє значення елементів: " << avg << endl;

    //Пошук елемента:
    int b;
    bool isPresent = false;
    cout << "Введіть елемент для пошуку: ";
    cin >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            isPresent = true;
            break;
        }
    }

    if (isPresent) {
        cout << "Елемент " << b << " присутній в масиві" << endl;
    }
    else {
        cout << "Елемента " << b << " в масиві нема" << endl;
    }

    //Сортування елементів:

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (a[j + 1] < a[j]) {
                int c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
            }
        }
    }


    //Виводимо відсортований масив на екран
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    //Кількість парних та непарних елементів:

    int even = 0;
    for (int i = 0; i < n; i++) if (a[i] % 2 == 0) even++;
    cout << "Кількість парних елементів: " << even << endl;
    cout << "Кількість непарних елементів: " << n - even << endl;

    //Повторювальні елементи:
    cout << "Повторювальні елементи: ";
    for (int i = 0; i < n; i++) {
        int isUniq = true;
        for (int j = i + 1; j < n; j++) {
            isUniq = isUniq and (a[i] != a[j]);
        }
        if (!isUniq) cout << a[i] << " ";
    }
    cout << endl;

    //Пошук пар елементів, сума яких дорівнює числу:
    int d;
    cout << "Введіть число: ";
    cin >> d;
    cout << "Пари елементів, сума яких дорівнює числу: ";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1 + 1; j < n; j++) {
            if (a[i] + a[j] == d) cout << a[i] << ", " << a[j] << "; ";
        }
    }
    cout << endl;

    //Двовимірні масиви:

    int e[n][n];

    //Ініціалізуємо масив цілих чисел розміром n*n елементів значеннями від -9 до 9
    cout << "Двовимірний масив: " << endl;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            e[i][j] = rand() % 19 - 9;

    //Виводимо масив на екран
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << e[i][j] << "\t";
        }
        cout << endl;
    }

    //Транспонування заданий двовимірний масив.
    //Продублюємо масив
    int g[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g[i][j] = e[i][j];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int h = g[i][j];
            g[i][j] = g[j][i];
            g[j][i] = h;
        }
    }

    //Виводимо транспонуваний масив на екран
    cout << "Транспонуваний масив (створено з копії, далі в завданні використовується орігінал вище): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << "\t";
        }
        cout << endl;
    }

    //Сума елементів нва головній і побічній діагоналях:

    int sum_main = 0;
    int sum_side = 0;

    for (int i = 0; i < n; i++) {
        sum_main += e[i][i];
        sum_side += e[i][n - i - 1];

    }
    cout << "Сума елементів на головній діагоналі: " << sum_main << endl;
    cout << "Сума елементів на побічній діагоналі: " << sum_side << endl;




    //Всі елементи у двовимірному масиві, які потрапляють у заданий діапазон

    int from;
    int dest;

    cout << "Перше значення діапаозону: ";
    cin >> from;
    cout << "Друге значення діапаозону: ";
    cin >> dest;


    cout << "Всі елементи у двовимірному масиві, які потрапляють у заданий діапазон: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (from < dest) {
                if ((e[i][j] >= from) and (e[i][j] <= dest)) cout << e[i][j] << " ";
            }
            else {
                if ((e[i][j] >= dest) and (e[i][j] <= from)) cout << e[i][j] << " ";
            }
        }
    }
    cout << endl;

    //Надайте усі можливі варіанти, як змінити місцями значення двох числових змінних без використання додаткових змінних та пам'яті.
    //Використовувати спеціальні функції, або сторонні бібліотеки заборонено, у вас немає безпосереднього оператора обміну значеннями типу CHNG,
    //Зверніть увагу, що у задачі є додаткові обмеження не має бути переповнення.


    int x = 6;
    int y = 7;

    x = x + y;
    y = x - y;
    x = x - y;

    cout << x << " " << y;


    















}