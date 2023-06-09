#include <iostream>
#include <random>
#include <chrono>

double a, b;
int numberOfElements;

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
double randomNumbersGenerator()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> distribution(a, b);
    return distribution(gen);
}
void arrayOperations()
{
    // Ініціалізація масиву, змінної суми, додавання результатів спрацьовування рандомайзера до масиву та їх виведення
    double sumOfPositiveElements = 0;
    double randomNumbersArray[numberOfElements];
    double* randomNumbersArrayPtr = randomNumbersArray;
    for (int i = 0; i < numberOfElements; i++, randomNumbersArrayPtr++)
    {
        *randomNumbersArrayPtr = randomNumbersGenerator();
        std::cout << *randomNumbersArrayPtr << " ";
        if (*randomNumbersArrayPtr > 0)
            sumOfPositiveElements += *randomNumbersArrayPtr;
    }
    std::cout << "\nСума додатних елементів дорівнює " << sumOfPositiveElements << std::endl;
    // Знаходження максимального та мінімального за модулем елементів
    double maxByModuleValue = std::abs(*randomNumbersArray);
    double minByModuleValue = std::abs(*randomNumbersArray);
    int maxByModuleIndex = 0;
    int minByModuleIndex = 0;
    for (double* randomNumbersArrayPtr = randomNumbersArray + 1; randomNumbersArrayPtr < randomNumbersArray + numberOfElements; randomNumbersArrayPtr++)
    {
        if (std::abs(*randomNumbersArrayPtr) > maxByModuleValue)
        {
            maxByModuleValue = std::abs(*randomNumbersArrayPtr);
            maxByModuleIndex = randomNumbersArrayPtr - randomNumbersArray;
        }
        else if (std::abs(*randomNumbersArrayPtr) < minByModuleValue)
        {
            minByModuleValue = std::abs(*randomNumbersArrayPtr);
            minByModuleIndex = randomNumbersArrayPtr - randomNumbersArray;
        }
    }
    if (minByModuleIndex == maxByModuleIndex + 1 || maxByModuleIndex == minByModuleIndex + 1)
    {
        std::cout << "Між елементами з найбільшим та найменшим модулем нема елементів";
    }
    else if (minByModuleIndex < maxByModuleIndex)
    {
        double product = 1;
        for (double* randomNumbersArrayPtr = randomNumbersArray + minByModuleIndex + 1; randomNumbersArrayPtr < randomNumbersArray + maxByModuleIndex; randomNumbersArrayPtr++)
        {
            product *= *randomNumbersArrayPtr;
        }
        std::cout << "Добуток елементів, що знаходяться між найменшим та найбільшим за модулем елементами дорівнює " << product;
    }
    else if (minByModuleIndex > maxByModuleIndex)
    {
        double product = 1;
        for (double* randomNumbersArrayPtr = randomNumbersArray + maxByModuleIndex + 1; randomNumbersArrayPtr < randomNumbersArray + minByModuleIndex; randomNumbersArrayPtr++)
        {
            product *= *randomNumbersArrayPtr;
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