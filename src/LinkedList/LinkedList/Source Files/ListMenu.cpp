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
        cout << "\n��������� �������� ��� ����� ���������� �������:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� �������\n";
        cout << "3. ������� �������� � ������ ������\n";
        cout << "4. ������� �������� � ����� ������\n";
        cout << "5. ������� �������� ����� ������������� ��������\n";
        cout << "6. ������� �������� ����� ������������ ���������\n";
        cout << "7. ���������� ������\n";
        cout << "8. �������� ����� �������� � ������\n";
        cout << "9. ��������� ����� ������������������\n";
        cout << "0. ��������� ������ ���������\n";

        cout << "�������� ��������: ";
        while (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����. ����������, ������� �����: ";
        }

        switch (choice)
        {
        case (1):
        {
            cout << "������� �������� ��� ����������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->Add(value);
            cout << "������� " << value << " �������� � ������.\n";
            PrintList(*list);
            break;
        }
        case (2):
        {
            cout << "������� �������� ��� ��������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->Remove(value);
            cout << "������� " << value << " ��� ������ �� ������.\n";
            PrintList(*list);
            break;
        }
        case (3):
        {
            cout << "������� �������� ��� ���������� � ������ ������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->InsertAtBeginning(value);
            cout << "������� " << value << " ��� �������� � ������ ������.\n";
            PrintList(*list);
            break;
        }
        case (4):
        {
            cout << "������� �������� ��� ���������� � ����� ������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->InsertAtEnd(value);
            cout << "������� " << value << " ��� �������� � ����� ������.\n";
            PrintList(*list);
            break;
        }
        case (5):
        {
            cout << "������� �������� ��� ����������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            cout << "������� ��������, ����� �������� ������ �������� " << value << " : ";
            while (!(cin >> afterValue))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->InsertAfter(afterValue, value);
            cout << "������� " << value << " ��� �������� � ������ ����� " << afterValue << "\n";
            PrintList(*list);
            break;
        }
        case (6):
        {
            cout << "������� �������� ��� ����������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            cout << "������� ��������, ����� ������� ������ �������� " << value << " : ";
            while (!(cin >> beforeValue))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            list->InsertBefore(beforeValue, value);
            cout << "������� " << value << " ��� �������� � ������ ����� " << beforeValue << "\n";
            PrintList(*list);
            break;
        }
        case (7):
        {
            cout << "��� ����������������� ������: ";
            PrintList(*list);
            cout << "��� ��������������� ������: ";
            list->Sort();
            PrintList(*list);
            cout << endl;
            break;
        }
        case (8):
        {
            int searchedValue;
            cout << "������� ������� ������� ������ ����� � ������: ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            searchedValue = list->LinearSearch(value);
            if (searchedValue >= 0)
            {
                cout << "������� " << value << " ��������� ��� ��������: " << searchedValue << endl;
            }
            else
            {
                cout << "������� " << value << " �� ������" << endl;
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

            cout << "������� �����: ";
            while (!(cin >> choice2))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����. ����������, ������� �����: ";
            }

            switch (choice2)
            {
            case 1:
                cout << "������ ����� �������...\n";
                Testing::testInsertion(*list, maxElements, step);
                cout << "���� ������� ��������.\n";
                break;

            case 2:
                cout << "������ ����� ��������...\n";
                Testing::testDeletion(*list, maxElements, step);
                cout << "���� �������� ��������.\n";
                break;

            case 3:
                cout << "�����...\n";
                break;

            default:
                cout << "�������� �����, ���������� �����.\n";
            }
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
