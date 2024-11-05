#include <iostream>
#include "Menu.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "Queue.h"
#include "Queue2Stacks.h"

using namespace std;

void ClearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Некорректный ввод. Пожалуйста, попробуйте снова.\n";
}

int GetIntegerInput() 
{
    int value;
    while (true) 
    {
        if (cin >> value) 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else 
        {
            ClearInput();
        }
    }
}

void ShowStackMenu(Stack* stack) 
{
    int choice, value, newSize;

    do {
        cout << "\nРабота со стеком:\n";
        cout << "1. Добавить элемент (Push)\n";
        cout << "2. Извлечь элемент (Pop)\n";
        cout << "3. Проверить, пуст ли стек\n";
        cout << "4. Изменить размер стека\n";
        cout << "0. Назад\n";
        cout << "Выберите операцию: ";

        choice = GetIntegerInput();

        switch (choice) 
        {
            case 1:
                {
                    cout << "Введите значение для добавления в стек: ";

                    value = GetIntegerInput();

                    Push(stack, value);
                    cout << "Элемент " << value << " добавлен в стек.\n";
                    break;
                }
            case 2:
                {
                    if (!IsEmpty(stack))
                    {
                        value = Pop(stack);
                        cout << "Извлечен элемент: " << value << endl;
                    }
                    else
                    {
                        cout << "Стек пуст.\n";
                    }

                    break;
                }
            case 3:
                {
                    cout << (IsEmpty(stack) ? "Стек пуст." : "Стек не пуст.") << endl;
                    break;
                }
            case 4:
                {
                    cout << "Введите новый размер стека: ";

                    newSize = GetIntegerInput();

                    Resize(stack, newSize);
                    cout << "Размер стека изменен на " << newSize << ".\n";
                    break;
                }
            case 0:
                {
                    cout << "Возврат в основное меню...\n";
                    break;
                }
            default:
                cout << "Некорректный выбор, попробуйте снова.\n";
        }

    } while (choice != 0);
}

void ShowRingBufferMenu(RingBuffer* rb) 
{
    int choice, value, newSize;

    do {
        cout << "\nРабота с кольцевым буфером:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Извлечь элемент\n";
        cout << "3. Показать свободное место\n";
        cout << "4. Показать занятое место\n";
        cout << "5. Изменить размер буфера\n";
        cout << "0. Назад\n";
        cout << "Выберите операцию: ";
        
        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
                {
                    cout << "Введите значение для добавления в буфер: ";

                    value = GetIntegerInput();

                    try
                    {
                        Add(rb, value);
                        cout << "Элемент " << value << " добавлен в буфер.\n";
                    }
                    catch (const overflow_error& e)
                    {
                        cout << e.what() << endl;
                    }

                    break;
                }
            case 2:
                {
                    try
                    {
                        value = Remove(rb);
                        cout << "Извлечен элемент: " << value << endl;
                    }
                    catch (const underflow_error& e)
                    {
                        cout << e.what() << endl;
                    }

                    break;
                }
            case 3:
                {
                    cout << "Свободное место: " << FreeSpace(rb) << endl;
                    break;
                }
            case 4:
                {
                    cout << "Занятое место: " << OccupiedSpace(rb) << endl;
                    break;
                }
            case 5:
                {
                    cout << "Введите новый размер буфера: ";

                    newSize = GetIntegerInput();

                    ResizeBuffer(rb, newSize);
                    cout << "Размер буфера изменен на " << newSize << ".\n";
                    break;
                }
            case 0:
                {
                    cout << "Возврат в основное меню...\n";
                    break;
                }
            default:
                {
                    cout << "Некорректный выбор, попробуйте снова.\n";
                }
        }

    } while (choice != 0);
}

void ShowQueueMenu(Queue* queue) 
{
    int choice, value, newSize;

    do {
        cout << "\nРабота с очередью на основе кольцевого буфера:\n";
        cout << "1. Добавить элемент (Enqueue)\n";
        cout << "2. Извлечь элемент (Dequeue)\n";
        cout << "3. Проверить, пуста ли очередь\n";
        cout << "4. Изменить размер очереди\n";
        cout << "0. Назад\n";
        cout << "Выберите операцию: ";
        
        choice = GetIntegerInput();

        switch (choice) 
        {
        case 1:
            {
                cout << "Введите значение для добавления в очередь: ";

                value = GetIntegerInput();

                try 
                {
                    Enqueue(queue, value);
                    cout << "Элемент " << value << " добавлен в очередь.\n";
                }
                catch (const overflow_error& e) 
                {
                    cout << e.what() << endl;
                }

                break;
            }
        case 2:
            {
                try
                {
                    value = Dequeue(queue);
                    cout << "Извлечен элемент: " << value << endl;
                }
                catch (const underflow_error& e)
                {
                    cout << e.what() << endl;
                }

                break;
            }
        case 3:
            {
                cout << (IsQueueEmpty(queue) ? "Очередь пуста." : "Очередь не пуста.") << endl;
                break;
            }
        case 4:
            {
                cout << "Введите новый размер очереди: ";

                newSize = GetIntegerInput();

                ResizeBuffer(&queue->buffer, newSize);
                cout << "Размер очереди изменен на " << newSize << ".\n";
                break;
            }
        case 0:
            {
                cout << "Возврат в основное меню...\n";
                break;
            }
        default:
            {
                cout << "Некорректный выбор, попробуйте снова.\n";
            }
        }

    } while (choice != 0);
}

void ShowQueue2StacksMenu(Queue2Stacks* queue) 
{
    int choice, value, newSize;

    do {
        cout << "\nРабота с очередью на основе двух стеков:\n";
        cout << "1. Добавить элемент (Enqueue)\n";
        cout << "2. Извлечь элемент (Dequeue)\n";
        cout << "3. Проверить, пуста ли очередь\n";
        cout << "4. Изменить размер очереди\n";
        cout << "0. Назад\n";
        cout << "Выберите операцию: ";

        choice = GetIntegerInput();

        switch (choice)
        {
        case 1:
            {
                cout << "Введите значение для добавления в очередь: ";

                value = GetIntegerInput();

                Enqueue2Stacks(queue, value);
                cout << "Элемент " << value << " добавлен в очередь.\n";
                break;
            }
        case 2:
            {
                if (!IsQueue2StacksEmpty(queue)) {
                    value = Dequeue2Stacks(queue);
                    cout << "Извлечен элемент: " << value << endl;
                }
                else
                {
                    cout << "Очередь пуста.\n";
                }

                break;
            }
        case 3:
            {
                cout << (IsQueue2StacksEmpty(queue) ? "Очередь пуста." : "Очередь не пуста.") << endl;
                break;
            }
        case 4:
            {
                cout << "Введите новый размер очереди: ";

                newSize = GetIntegerInput();

                Resize(&queue->stack1, newSize);
                Resize(&queue->stack2, newSize);
                cout << "Размер очереди изменен на " << newSize << ".\n";
                break;
            }
        case 0:
            {
                cout << "Возврат в основное меню...\n";
                break;
            }
        default:
            {
                cout << "Некорректный выбор, попробуйте снова.\n";
            }
        }

    } while (choice != 0);
}

void ShowMenu() 
{
    int choice, stackSize = 10, bufferSize = 10;
    Stack stack;
    RingBuffer ringBuffer;
    Queue queue;
    Queue2Stacks queue2Stacks;

    Initialize(&stack, stackSize);
    InitBuffer(&ringBuffer, bufferSize);
    InitQueue(&queue, bufferSize);
    InitQueue2Stacks(&queue2Stacks, stackSize);

    do {
        cout << "\nОсновное меню:\n";
        cout << "1. Работа со стеком\n";
        cout << "2. Работа с кольцевым буфером\n";
        cout << "3. Работа с очередью (на базе кольцевого буфера)\n";
        cout << "4. Работа с очередью (на базе двух стеков)\n";
        cout << "0. Выход\n";
        cout << "Выберите операцию: ";
        
        choice = GetIntegerInput();

        switch (choice) 
        {
        case 1:
            {
                ShowStackMenu(&stack);
                break;
            }
        case 2:
            {
                ShowRingBufferMenu(&ringBuffer);
                break;
            }
        case 3:
            {
                ShowQueueMenu(&queue);
                break;
            }
        case 4:
            {
                ShowQueue2StacksMenu(&queue2Stacks);
                break;
            }
        case 0:
            {
                cout << "Выход из программы.\n";
                break;
            }
        default:
            {
                cout << "Некорректный выбор, попробуйте снова.\n";
            }
        }

    } while (choice != 0);

    Delete(&stack);
    FreeBuffer(&ringBuffer);
    FreeQueue(&queue);
    FreeQueue2Stacks(&queue2Stacks);
}
