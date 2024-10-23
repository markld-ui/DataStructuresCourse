#include <iostream>
#include "List.h"
#include "ListMenu.h"
#include "Testing.h"

using namespace std;

void PrintList(const DoublyLinkedList& list)
{
    Node* current = list.getHead();
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void ShowMenu(DoublyLinkedList* list)
{
    int choice;
    int value, afterValue, beforeValue;

    do
    {
        cout << "\nДоступные операции над Вашим двусвязным списком:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Вставка элемента в начало списка\n";
        cout << "4. Вставка элемента в конец списка\n";
        cout << "5. Вставка элемента после определенного элемента\n";
        cout << "6. Вставка элемента перед определенным элементом\n";
        cout << "7. Сортировка списка\n";
        cout << "8. Линейный поиск элемента в списке\n";
        cout << "9. Запустить тесты производительности\n";
        cout << "0. Закончить работу программы\n";

        cout << "Выберите операцию: ";
        while (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите число: ";
        }

        switch (choice)
        {
        case (1):
        {
            cout << "Введите значение для добавления: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->Add(value);
            cout << "Элемент " << value << " добавлен в список.\n";
            PrintList(*list);
            break;
        }
        case (2):
        {
            cout << "Введите значение для удаления: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->Remove(value);
            cout << "Элемент " << value << " был удален из списка.\n";
            PrintList(*list);
            break;
        }
        case (3):
        {
            cout << "Введите значение для добавление в начало списка: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->InsertAtBeginning(value);
            cout << "Элемент " << value << " был вставлен в начало списка.\n";
            PrintList(*list);
            break;
        }
        case (4):
        {
            cout << "Введите значение для добавления в конец списка: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->InsertAtEnd(value);
            cout << "Элемент " << value << " был вставлен в конец списка.\n";
            PrintList(*list);
            break;
        }
        case (5):
        {
            cout << "Введите значение для добавления: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            cout << "Введите значение, после которого хотите вставить " << value << " : ";
            while (!(cin >> afterValue))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->InsertAfter(afterValue, value);
            cout << "Элемент " << value << " был добавлен в список после " << afterValue << "\n";
            PrintList(*list);
            break;
        }
        case (6):
        {
            cout << "Введите значение для добавления: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            cout << "Введите значение, перед которым хотите вставить " << value << " : ";
            while (!(cin >> beforeValue))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            list->InsertBefore(beforeValue, value);
            cout << "Элемент " << value << " был добавлен в список перед " << beforeValue << "\n";
            PrintList(*list);
            break;
        }
        case (7):
        {
            cout << "Ваш неотсортированный список: ";
            PrintList(*list);
            cout << "Ваш отсортированный список: ";
            list->Sort();
            PrintList(*list);
            cout << endl;
            break;
        }
        case (8):
        {
            int searchedValue;
            cout << "Введите элемент который хотите найти в списке: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            searchedValue = list->LinearSearch(value);
            if (searchedValue >= 0)
            {
                cout << "Элемент " << value << " находится под индексом: " << searchedValue << endl;
            }
            else
            {
                cout << "Элемент " << value << " не найден" << endl;
            }

            break;
        }
        case (9):
        {
            int choice2;
            int maxElements = 2000;
            int step = 10;
            std::cout << "========================\n";
            std::cout << "1. Test Insertion Performance\n";
            std::cout << "2. Test Deletion Performance\n";
            std::cout << "3. Exit\n";
            std::cout << "========================\n";

            cout << "Введите выбор: ";
            while (!(cin >> choice2))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод. Пожалуйста, введите число: ";
            }

            switch (choice2)
            {
            case 1:
                cout << "Запуск теста вставки...\n";
                Testing::testInsertion(*list, maxElements, step);
                cout << "Тест вставки завершен.\n";
                break;

            case 2:
                cout << "Запуск теста удаления...\n";
                Testing::testDeletion(*list, maxElements, step);
                cout << "Тест удаления завершен.\n";
                break;

            case 3:
                cout << "Выход...\n";
                break;

            default:
                cout << "Неверный выбор, попробуйте снова.\n";
            }
            break;
        }
        case (0):
        {
            cout << "Выход из программы\n";
            break;
        }
        default:
        {
            cout << "Неверно выбрана опция, пожалуйста, попробуйте снова!\n";
            break;
        }
        }

    } while (choice != 0);
}
