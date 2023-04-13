#include <iostream>
#include <random>

int m, k, n;

std::default_random_engine Random_m(time(nullptr));
std::default_random_engine Random_n(time(nullptr));
void promptVariables() // Функція, що отримує від користувача значення змінних m, k, n
{
    std::cout << "Введіть значення 'k': ";
    std::cin >> k;
    if (std::cin.fail() || k < 3 || k > 10)
    {
        std::cout << "Неправильне значення! Повинно бути цілим числом від 3 до 10 включно. Завершення роботи...";
        std::exit(1);
    }
    std::cout << "Введіть значення 'm': ";
    std::cin >> m;
    if (std::cin.fail() || m % k != 0)
    {
        std::cout << "Неправильне значення! Повинно бути цілочисленним та ділитися на k без залишку. Завершення роботи...";
        std::exit(2);
    }

    std::cout << "Введіть значення 'n': ";
    std::cin >> n;
    if (std::cin.fail() || n % k != 0)
    {
        std::cout << "Неправильне значення! Повинно бути цілочисленним та ділитися на k без залишку. Завершення роботи...";
        std::exit (3);
    }

}
void printRandom_m() // Функція, що виводить рандомні значення 'm' цілих чисел в проміжку від 13 до 399 включно
{
    for (int total = 0, column = 0; total < m; total += column)
    {
        for (column = 0; column <= k; column++)
            std::cout << Random_m();

    }
}
void printRandom_n() // Функція, що виводить випадкові значення 'n' чисел в проміжку від 13 до 399 включно
{
    for (int total = 0, column = 0; total < n; total += column)
    {
        for (column = 0; column <= k; column++)
            std::cout << Random_n();
    }
}

int main()
{
    std::setlocale (LC_CTYPE, "ua");
    promptVariables();
    return 0;
}