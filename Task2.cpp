#include <iostream>
#include <random>
#include <chrono>

int a, b, numberOfElements;

void promptValues()
{
    std::cout << "Введіть значення а: ";
    std::cin >> a;
    if (std::cin.fail())
    {
        std::cout << "Неправильне значення!";
        exit (1);
    }

    std::cout << "Введіть значення b: ";
    std::cin >> b;
    if (std::cin.fail() || a > b)
    {
        std::cout << "Неправильне значення!";
        exit (2);
    }
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> numberOfElements;
    if (std::cin.fail() || numberOfElements < 1)
    {
        std::cout << "Неправильне значення!";
        exit (3);
    }
}
int randomNumbersGenerator()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distribution(a, b);
    return distribution(gen);
}
void arrayOperations()
{
    // Ініціалізація масиву, змінної суми, додавання результатів спрацьовування рандомайзера до масиву та їх виведення
    int sumOfPositiveElements = 0;
    int randomNumbersArray[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        randomNumbersArray[i] = randomNumbersGenerator();
        std::cout << randomNumbersArray[i] << " ";
        if (randomNumbersArray[i] > 0)
            sumOfPositiveElements += randomNumbersArray[i];
    }
    std::cout << "\nСума додатних елементів дорівнює " << sumOfPositiveElements << std::endl;
    // Знаходження максимального та мінімального за модулем елементів
    int maxByModuleValue = std::abs(randomNumbersArray[0]);
    int minByModuleValue = std::abs(randomNumbersArray[0]);
    int maxByModuleIndex = 0;
    int minByModuleIndex = 0;
    for (int i = 1; i < numberOfElements; i++)
    {
        if (std::abs(randomNumbersArray[i]) > maxByModuleValue)
        {
            maxByModuleValue = std::abs(randomNumbersArray[i]);
            maxByModuleIndex = i;
        }
        else if (std::abs(randomNumbersArray[i]) < minByModuleValue)
        {
            minByModuleValue = std::abs(randomNumbersArray[i]);
            minByModuleIndex = i;
        }
    }
    if (minByModuleIndex == maxByModuleIndex + 1 || maxByModuleIndex == minByModuleIndex + 1)
    {
        std::cout << "Між елементами з найбільшим та найменшим модулем нема елементів";
    }
    else if (minByModuleIndex < maxByModuleIndex)
    {
        int product = 1;
        for (int i = minByModuleIndex + 1; i < maxByModuleIndex; i++)
        {
            product *= randomNumbersArray[i];
        }
        std::cout << "Добуток елементів, що знаходяться між найменшим та найбільшим за модулем елементами дорівнює " << product;
    }
    else if (minByModuleIndex > maxByModuleIndex)
    {
        int product = 1;
        for (int i = maxByModuleIndex + 1; i < minByModuleIndex; i++)
        {
            product *= randomNumbersArray[i];
        }
        std::cout << "Добуток елементів, що знаходяться між найменшим та найбільшим за модулем елементами дорівнює " << product;
    }
    else
    {
        std::cout << "Всі елементи масиву мають однаковий модуль";
    }
}

int main()
{
    std::setlocale(LC_ALL, "ua");

    promptValues();
    arrayOperations();

    return 0;
}