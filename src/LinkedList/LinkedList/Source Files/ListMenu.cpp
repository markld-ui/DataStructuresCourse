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
		cout << "\n��������� �������� ��� ����� ���������� �������:\n";
		cout << "1. �������� �������\n";
		cout << "2. ������� �������\n";
		cout << "3. ������� �������� � ������ ������\n";
		cout << "4. ������� �������� � ����� ������\n";
		cout << "5. ������� �������� ����� ������������� ��������\n";
		cout << "6. ������� �������� ����� ������������ ���������\n";
		cout << "7. ���������� ������\n";
		cout << "8. �������� ����� �������� � ������\n";
		cout << "0. ��������� ������ ���������\n";

		cout << "�������� ��������: ";
		cin >> choice;

		switch (choice)
		{
			case (1):
			{
				cout << "������� �������� ��� ����������: ";
				cin >> value;
				list->add(value);
				cout << "������� " << value << " �������� � ������.\n";
				list->printList();
				break;
			}
			case (2):
			{
				cout << "������� �������� ��� ��������: ";
				cin >> value;
				list->remove(value);
				cout << "������� " << value << " ��� ������ �� ������.\n";
				list->printList();
				break;
			}
			case (3):
			{
				cout << "������� �������� ��� ���������� � ������ ������: ";
				cin >> value;
				list->insertAtBeginning(value);
				cout << "������� " << value << " ��� �������� � ������ ������.\n";
				list->printList();
				break;
			}
			case (4):
			{
				cout << "������� �������� ��� ���������� � ����� ������: ";
				cin >> value;
				list->insertAtEnd(value);
				cout << "������� " << value << " ��� �������� � ����� ������.\n";
				list->printList();
				break;
			}
			case (5):
			{
				cout << "������� �������� ��� ����������: ";
				cin >> value;
				cout << "������� ��������, ����� �������� ������ �������� " << value << " : ";
				cin >> afterValue;
				list->insertAfter(afterValue, value);
				cout << "������� " << value << " ��� �������� � ������ ����� " << afterValue << "\n";
				list->printList();
				break;
			}
			case (6):
			{
				cout << "������� �������� ��� ����������: ";
				cin >> value;
				cout << "������� ��������, ����� ������� ������ �������� " << value << " : ";
				cin >> beforeValue;
				list->insertBefore(beforeValue, value);
				cout << "������� " << value << " ��� �������� � ������ ����� " << beforeValue << "\n";
				list->printList();
				break;
			}
			case (7):
			{
				cout << "��� ����������������� ������: ";
				list->printList();
				cout << "��� ��������������� ������: ";
				list->sort();
				list->printList();
				cout << endl;
				break;
			}
			case (8):
			{
				Node* searchedValue;
				cout << "������� ������� ������� ������ ����� � ������: ";
				cin >> value;
				searchedValue = list->linearSearch(value);
				cout << "������� " << value << " ��������� �����: " << searchedValue;
				cout << endl;
				break;
			}
			case (0):
			{
				cout << "����� �� ���������\n";
				break;
			}
			default:
			{
				cout << "������� ������� �����, ����������, ���������� �����!\n";
				break;
			}
		}

	} while (choice != 0);
}