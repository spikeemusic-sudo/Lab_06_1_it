// Lab_06_1_іт.cpp
// Фащевський Богдан
// Лабораторна робота № 6.1
// Варіант 28
// Пошук елементів одновимірного масиву ітераційним способом

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція формування масиву за допомогою генератора випадкових чисел
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція форматного виведення масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

// Функція обчислення кількості елементів, що задовольняють критерію
int Count(const int* a, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

// Функція обчислення суми елементів, що задовольняють критерію
int Sum(const int* a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            sum += a[i];
        }
    }
    return sum;
}

// Функція заміни елементів, що задовольняють критерію, нулями
void ZeroElements(int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            a[i] = 0;
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 24;
    int a[n];
    const int Low = -50;
    const int High = 15;

    // 1. Формування та виведення початкового масиву
    Create(a, n, Low, High);
    cout << "Initial array:" << endl;
    Print(a, n);

    // 2. Обчислення кількості та суми
    int count = Count(a, n);
    int sum = Sum(a, n);

    cout << "\nResults:" << endl;
    cout << "Count of elements (negative or odd) = " << count << endl;
    cout << "Sum of elements (negative or odd)   = " << sum << endl;

    // 3. Заміна елементів нулями та виведення модифікованого масиву
    ZeroElements(a, n);
    cout << "\nModified array:" << endl;
    Print(a, n);

    return 0;
}