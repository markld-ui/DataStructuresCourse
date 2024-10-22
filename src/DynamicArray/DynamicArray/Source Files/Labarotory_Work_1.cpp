#include "DynamicArray.h"
#include <iostream>

using namespace std;

void PrintMenu()
{
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент по индексу\n";
    cout << "3. Удалить элемент по значению\n";
    cout << "4. Получить элемент по индексу\n";
    cout << "5. Сортировать массив\n";
    cout << "6. Сортировать массив выбором\n";
    cout << "7. Линейный поиск элемента\n";
    cout << "8. Бинарный поиск элемента\n";
    cout << "9. Показать массив\n";
    cout << "10. Выйти\n";
}

void PrintArray(DynamicArray& array)
{
    for (int i = 0; i < array.GetSize(); ++i)
    {
        cout << array.GetElemnt(i) << " ";
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    DynamicArray array;
    int choice, value, index;

    while (true)
    {
        PrintMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите индекс и значение для добавления: ";
            cin >> index >> value;
            array.AddElement(index, value);
            break;
        case 2:
            cout << "Введите индекс для удаления: ";
            cin >> index;
            array.RemoveByIndex(index);
            break;
        case 3:
            cout << "Введите значение для удаления: ";
            cin >> value;
            array.RemoveByValue(value);
            break;
        case 4:
            cout << "Введите индекс элемента: ";
            cin >> index;
            cout << "Элемент: " << array.GetElemnt(index) << "\n";
            break;
        case 5:
            array.SortArray();
            cout << "Массив отсортирован\n";
            break;
        case 6:
            array.SelectionSort();
            cout << "Массив отсортирован вставкой\n";
            break;
        case 7:
            cout << "Введите значение для поиска: ";
            cin >> value;
            array.LinerSearch(value);
            break;
        case 8:
            cout << "Введите значение для бинарного поиска: ";
            cin >> value;
            array.BinarySearch(value);
            break;
        case 9:
            PrintArray(array);
            break;
        case 10:
            return 0;
        default:
            cout << "Неверный ввод\n";
        }
    }
}