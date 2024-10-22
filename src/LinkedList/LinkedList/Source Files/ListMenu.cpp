#include <iostream>
#include "List.h"
#include "ListMenu.h"

using namespace std;

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
		cout << "0. Закончить работу программы\n";

		cout << "Выберите операцию: ";
		cin >> choice;

		switch (choice)
		{
			case (1):
			{
				cout << "Введите значение для добавления: ";
				cin >> value;
				list->add(value);
				cout << "Элемент " << value << " добавлен в список.\n";
				list->printList();
				break;
			}
			case (2):
			{
				cout << "Введите значение для удаления: ";
				cin >> value;
				list->remove(value);
				cout << "Элемент " << value << " был удален из списка.\n";
				list->printList();
				break;
			}
			case (3):
			{
				cout << "Введите значение для добавление в начало списка: ";
				cin >> value;
				list->insertAtBeginning(value);
				cout << "Элемент " << value << " был вставлен в начало списка.\n";
				list->printList();
				break;
			}
			case (4):
			{
				cout << "Введите значение для добавления в конец списка: ";
				cin >> value;
				list->insertAtEnd(value);
				cout << "Элемент " << value << " был вставлен в конец списка.\n";
				list->printList();
				break;
			}
			case (5):
			{
				cout << "Введите значение для добавления: ";
				cin >> value;
				cout << "Введите значение, после которого хотите вставить " << value << " : ";
				cin >> afterValue;
				list->insertAfter(afterValue, value);
				cout << "Элемент " << value << " был добавлен в список после " << afterValue << "\n";
				list->printList();
				break;
			}
			case (6):
			{
				cout << "Введите значение для добавления: ";
				cin >> value;
				cout << "Введите значение, перед которым хотите вставить " << value << " : ";
				cin >> beforeValue;
				list->insertBefore(beforeValue, value);
				cout << "Элемент " << value << " был добавлен в список перед " << beforeValue << "\n";
				list->printList();
				break;
			}
			case (7):
			{
				cout << "Ваш неотсортированный список: ";
				list->printList();
				cout << "Ваш отсортированный список: ";
				list->sort();
				list->printList();
				cout << endl;
				break;
			}
			case (8):
			{
				Node* searchedValue;
				cout << "Введите элемент который хотите найти в списке: ";
				cin >> value;
				searchedValue = list->linearSearch(value);
				cout << "Элемент " << value << " находится здесь: " << searchedValue;
				cout << endl;
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