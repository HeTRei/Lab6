#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>

int m, k, n;
time_t seed_n;

int Random_m() // Функція, що повертає випадкове число, яке відповідає умовам пункту А
{
    std::random_device rd; // Призначення змінній rd значення random_device, а саме ID випадкового пристрою з комп'ютера
    std::mt19937 generate_m(rd()); // Функція випадкового числа з сідом rd
    std::uniform_int_distribution<> distribution_m(13, 399); // Визначення лімітів можливих чисел
    return distribution_m(generate_m);
}
double Random_n() // Функція, що повертає випадкове число, яке відповідає умовам пункту Б
{
    std::mt19937 generate_n(seed_n); // Функція випадкового числа з сідом, що дорівнює кількості секунд з 1 січня 1970 року +10 після кожної ітерації
    std::uniform_real_distribution<double> distribution_n(-2.0, 2.0); // Визначення лімітів
    seed_n += 10;
    return distribution_n(generate_n);
}

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
        for (column = 0; column < k; column++)
            std::cout << Random_m() << " ";
        std::cout << "\n";

    }
}
void printRandom_n() // Функція, що виводить випадкові значення 'n' чисел в проміжку від -2 до 2 включно
{
    for (int total = 0, column = 0; total < n; total += column)
    {
        for (column = 0; column < k; column++)
            std::cout << std::fixed << std::setprecision(1) << Random_n() << " ";
        std::cout << "\n";
    }
}

int main()
{
    std::time(&seed_n); // Призначення змінній seed_n значення секунд з 1 січня 1970 року
    std::setlocale (LC_CTYPE, "ua");
    promptVariables();
    printRandom_m();
    printRandom_n();
    return 0;
}