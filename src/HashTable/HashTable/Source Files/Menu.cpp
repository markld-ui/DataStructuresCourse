#include "Menu.h"

using namespace std;

void MenuController()
{
    string menuGeneral = "�������� ��������� ������:\n1 - �� '�������'\
        \n2 - �� '���-�������'\nq - �����\n��� �����: ";

    char modeGeneral = '\0';

    string enterMessageGeneral = "�������� ��: ";
    string failMessageGeneral = "����� �� ���!\n";

    while (modeGeneral != 'q')
    {
        cout << menuGeneral;
        modeGeneral = ValidInput<char>();
        ClearTerminal();
        switch (modeGeneral)
        {
            case '1':
            {
                MenuDictionaryCase();
            }
            case '2':
            {
                MenuHashTableCase();
            }
            default:
            {
                break;
            }
        }
    }
}

void ShowHashTable(Dictionary* dictionary)
{
    const HashTable* hashTable = dictionary->GetHashTable();
    int length = hashTable->GetLenght();
    int capacity = hashTable->GetCapacity();
    HashTableItem** data = hashTable->GetData();
    const int* pearsonTable = hashTable->GetPearsonTable();
    cout << "������� �������: ";

    for (int i = 0; i < capacity; i++)
    {
        cout << pearsonTable[i] << " ";
    }

    cout << endl;
    cout << "����� = " << length << "  �������� = " << capacity << endl;

    for (int i = 0; i < capacity; i++)
    {
        cout << "ID " << i << ": " << endl;

        if (data[i])
        {
            HashTableItem* temp = data[i];
            while (temp)
            {
                cout << "\t" << temp->Key << " : " << temp->Value << endl;
                temp = temp->Next;
            }
        }
        else
        {
            cout << "\t***\n";
        }
    }
}

void ShowHashTable(HashTable* hashTable)
{
    int length = hashTable->GetLenght();
    int capacity = hashTable->GetCapacity();
    HashTableItem** data = hashTable->GetData();
    const int* pearsonTable = hashTable->GetPearsonTable();
    cout << "������� �������: ";

    for (int i = 0; i < capacity; i++)
    {
        cout << pearsonTable[i] << " ";
    }

    cout << endl;
    cout << "����� = " << length << "  �������� = " << capacity << endl;

    for (int i = 0; i < capacity; i++)
    {
        cout << "ID " << i << ": " << endl;

        if (data[i])
        {
            HashTableItem* temp = data[i];
            while (temp)
            {
                cout << "\t" << temp->Key << " : " << temp->Value << endl;
                temp = temp->Next;
            }
        }
        else
        {
            cout << "\t***\n";
        }
    }
}

void ShowDictionary(Dictionary* dictionary)
{
    const HashTable* hashTable = dictionary->GetHashTable();
    int length = hashTable->GetLenght();

    if (length == 0)
    {
        cout << "������� ����\n";
        return;
    }

    HashTableItem** data = hashTable->GetData();
    int capacity = hashTable->GetCapacity();
    int counter = 0;

    cout << "�������:\t{ ";
    for (int i = 0; i < capacity; i++)
    {
        HashTableItem* temp = data[i];
        string keyStorage = "";

        while (temp)
        {
            if (keyStorage != temp->Key)
            {
                keyStorage = temp->Key;
                counter++;
                if (counter % 3 == 0)
                {
                    cout << "\n->\t\t  ";
                }

                cout << "\"" << temp->Key << "\" : \"" << temp->Value << "\", ";
            }

            temp = temp->Next;
        }
    }

    cout << "\b\b }\n";
}

string GetTypeName(const char* letter)
{
    switch (*letter)
    {
        case 'c':
        {
            return "char";
        }
        case 'i':
        {
            return "integer";
        }
        case 'f':
        {
            return "float";
        }
        case 'd':
        {
            return "double";
        }
        case 'N':
        {
            return "string";
        }
        default:
        {
            return string("UNKNOWN_TYPE (") + letter + string(")");
        }
    }
}

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;

    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������� ���������� " << GetTypeName(typeid(variable).name()) << " ��������: ";
        cin >> variable;
    }

    return variable;
}

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}

void MenuDictionaryCase()
{
    string menu = "�������� ���� �� ��������:\n1 - ��������\n2 - �����\
                    \n3 - �������\n4 - �������� ���-�������\nq - �����\n��� �����: ";

    Dictionary* dictionary = new Dictionary;
    char mode = '\0';

    string enterMessage = "������� ���� ";
    string failMessage = "����� ��� � �������!\n";

    while (mode != 'q')
    {
        ShowDictionary(dictionary);
        ShowHashTable(dictionary);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        string key;
        string value;

        switch (mode)
        {
        case '1':
        {
            cout << enterMessage << "��������: ";
            key = ValidInput<string>();
            cout << "������� ��������: ";
            value = ValidInput<string>();
            dictionary->Add(key, value);
            break;
        }
        case '2':
        {
            cout << enterMessage << "�����: ";
            key = ValidInput<string>();
            value = dictionary->Search(key);

            if (value != "")
            {
                cout << "���� \"" << key << "\" �������� �������� \"" << value << "\"\n";
            }
            else
            {
                cout << failMessage;
            }

            break;
        }
        case '3':
        {
            cout << enterMessage << "�������: ";
            key = ValidInput<string>();
            dictionary->Delete(key);
            break;
        }
        case '4':
        {
            ShowHashTable(dictionary);
            break;
        }
        default:
        {
            break;
        }
        }
    }

    delete dictionary;
}

void MenuHashTableCase()
{
    string menu = "�������� ���� �� ��������:\n1 - ��������\n2 - �����\
                    \n3 - �������\n4 - ���������� ���-���\nq - �����\n��� �����: ";

    HashTable* hashTable = new HashTable;
    char mode = '\0';

    string enterMessage = "������� ���� ";
    string failMessage = "����� ��� � ���-�������!\n";

    while (mode != 'q')
    {
        ShowHashTable(hashTable);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        string key;
        string value;

        switch (mode)
        {
        case '1':
        {
            cout << enterMessage << "��������: ";
            key = ValidInput<string>();
            cout << "������� ��������: ";
            value = ValidInput<string>();
            hashTable->Add(key, value);
            break;
        }
        case '2':
        {
            cout << enterMessage << "�����: ";
            key = ValidInput<string>();
            HashTableItem* value = hashTable->Search(key);

            if (value->Value != "")
            {
                cout << "���� \"" << key << "\" �������� �������� \"" << value->Value << "\"\n";
            }
            else
            {
                cout << failMessage;
            }

            break;
        }
        case '3':
        {
            cout << enterMessage << "�������: ";
            key = ValidInput<string>();
            hashTable->Delete(key);
            break;
        }
        case '4':
        {
            cout << "������� ���� ��� ������� ���-����: ";
            key = ValidInput<string>();
            cout << "����: \"" << key << "\" � ���� ��� ����: \"" << hashTable->PublicGetHashCode(key) << "\"\n";
            break;
        }
        default:
        {
            break;
        }
        }
    }

    delete hashTable;
}