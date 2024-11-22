#include "Menu.h"

using namespace std;

void MenuController()
{
    string menuGeneral = "Выберите структуру данных:\n1 - СД 'Словарь'\
        \n2 - СД 'Хеш-Таблица'\nq - Выйти\nВаш Выбор: ";

    char modeGeneral = '\0';

    string enterMessageGeneral = "Выберите СД: ";
    string failMessageGeneral = "Такой СД нет!\n";

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
    cout << "Таблица Пирсона: ";

    for (int i = 0; i < capacity; i++)
    {
        cout << pearsonTable[i] << " ";
    }

    cout << endl;
    cout << "Длина = " << length << "  Мощность = " << capacity << endl;

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
    cout << "Таблица Пирсона: ";

    for (int i = 0; i < capacity; i++)
    {
        cout << pearsonTable[i] << " ";
    }

    cout << endl;
    cout << "Длина = " << length << "  Мощность = " << capacity << endl;

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
        cout << "Словарь пуст\n";
        return;
    }

    HashTableItem** data = hashTable->GetData();
    int capacity = hashTable->GetCapacity();
    int counter = 0;

    cout << "Словарь:\t{ ";
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
        cout << "Введите корректное " << GetTypeName(typeid(variable).name()) << " значение: ";
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
    string menu = "Выберите одно из действий:\n1 - Добавить\n2 - Найти\
                    \n3 - Удалить\n4 - Показать Хеш-таблицу\nq - Выйти\nВаш выбор: ";

    Dictionary* dictionary = new Dictionary;
    char mode = '\0';

    string enterMessage = "Введите ключ ";
    string failMessage = "Ключа нет в словаре!\n";

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
            cout << enterMessage << "Добавить: ";
            key = ValidInput<string>();
            cout << "Введите значение: ";
            value = ValidInput<string>();
            dictionary->Add(key, value);
            break;
        }
        case '2':
        {
            cout << enterMessage << "Поиск: ";
            key = ValidInput<string>();
            value = dictionary->Search(key);

            if (value != "")
            {
                cout << "Ключ \"" << key << "\" содержит значение \"" << value << "\"\n";
            }
            else
            {
                cout << failMessage;
            }

            break;
        }
        case '3':
        {
            cout << enterMessage << "Удалить: ";
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
    string menu = "Выберите одно из действий:\n1 - Добавить\n2 - Найти\
                    \n3 - Удалить\n4 - Рассчитать хеш-код\nq - Выйти\nВаш выбор: ";

    HashTable* hashTable = new HashTable;
    char mode = '\0';

    string enterMessage = "Введите ключ ";
    string failMessage = "Ключа нет в хеш-таблице!\n";

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
            cout << enterMessage << "Добавить: ";
            key = ValidInput<string>();
            cout << "Введите значение: ";
            value = ValidInput<string>();
            hashTable->Add(key, value);
            break;
        }
        case '2':
        {
            cout << enterMessage << "Поиск: ";
            key = ValidInput<string>();
            HashTableItem* value = hashTable->Search(key);

            if (value->Value != "")
            {
                cout << "Ключ \"" << key << "\" содержит значение \"" << value->Value << "\"\n";
            }
            else
            {
                cout << failMessage;
            }

            break;
        }
        case '3':
        {
            cout << enterMessage << "Удалить: ";
            key = ValidInput<string>();
            hashTable->Delete(key);
            break;
        }
        case '4':
        {
            cout << "Введите ключ для расчёта хеш-кода: ";
            key = ValidInput<string>();
            cout << "Ключ: \"" << key << "\" в виде хеш кода: \"" << hashTable->PublicGetHashCode(key) << "\"\n";
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