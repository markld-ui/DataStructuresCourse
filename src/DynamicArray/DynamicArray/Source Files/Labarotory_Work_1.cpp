#include "DynamicArray.h"
#include <iostream>

using namespace std;

void PrintMenu()
{
    cout << "1. �������� �������\n";
    cout << "2. ������� ������� �� �������\n";
    cout << "3. ������� ������� �� ��������\n";
    cout << "4. �������� ������� �� �������\n";
    cout << "5. ����������� ������\n";
    cout << "6. ����������� ������ �������\n";
    cout << "7. �������� ����� ��������\n";
    cout << "8. �������� ����� ��������\n";
    cout << "9. �������� ������\n";
    cout << "10. �����\n";
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
            cout << "������� ������ � �������� ��� ����������: ";
            cin >> index >> value;
            array.AddElement(index, value);
            break;
        case 2:
            cout << "������� ������ ��� ��������: ";
            cin >> index;
            array.RemoveByIndex(index);
            break;
        case 3:
            cout << "������� �������� ��� ��������: ";
            cin >> value;
            array.RemoveByValue(value);
            break;
        case 4:
            cout << "������� ������ ��������: ";
            cin >> index;
            cout << "�������: " << array.GetElemnt(index) << "\n";
            break;
        case 5:
            array.SortArray();
            cout << "������ ������������\n";
            break;
        case 6:
            array.SelectionSort();
            cout << "������ ������������ ��������\n";
            break;
        case 7:
            cout << "������� �������� ��� ������: ";
            cin >> value;
            array.LinerSearch(value);
            break;
        case 8:
            cout << "������� �������� ��� ��������� ������: ";
            cin >> value;
            array.BinarySearch(value);
            break;
        case 9:
            PrintArray(array);
            break;
        case 10:
            return 0;
        default:
            cout << "�������� ����\n";
        }
    }
}