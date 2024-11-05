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
    cout << "������������ ����. ����������, ���������� �����.\n";
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
        cout << "\n������ �� ������:\n";
        cout << "1. �������� ������� (Push)\n";
        cout << "2. ������� ������� (Pop)\n";
        cout << "3. ���������, ���� �� ����\n";
        cout << "4. �������� ������ �����\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";

        choice = GetIntegerInput();

        switch (choice) 
        {
            case 1:
                {
                    cout << "������� �������� ��� ���������� � ����: ";

                    value = GetIntegerInput();

                    Push(stack, value);
                    cout << "������� " << value << " �������� � ����.\n";
                    break;
                }
            case 2:
                {
                    if (!IsEmpty(stack))
                    {
                        value = Pop(stack);
                        cout << "�������� �������: " << value << endl;
                    }
                    else
                    {
                        cout << "���� ����.\n";
                    }

                    break;
                }
            case 3:
                {
                    cout << (IsEmpty(stack) ? "���� ����." : "���� �� ����.") << endl;
                    break;
                }
            case 4:
                {
                    cout << "������� ����� ������ �����: ";

                    newSize = GetIntegerInput();

                    Resize(stack, newSize);
                    cout << "������ ����� ������� �� " << newSize << ".\n";
                    break;
                }
            case 0:
                {
                    cout << "������� � �������� ����...\n";
                    break;
                }
            default:
                cout << "������������ �����, ���������� �����.\n";
        }

    } while (choice != 0);
}

void ShowRingBufferMenu(RingBuffer* rb) 
{
    int choice, value, newSize;

    do {
        cout << "\n������ � ��������� �������:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� �������\n";
        cout << "3. �������� ��������� �����\n";
        cout << "4. �������� ������� �����\n";
        cout << "5. �������� ������ ������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        
        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
                {
                    cout << "������� �������� ��� ���������� � �����: ";

                    value = GetIntegerInput();

                    try
                    {
                        Add(rb, value);
                        cout << "������� " << value << " �������� � �����.\n";
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
                        cout << "�������� �������: " << value << endl;
                    }
                    catch (const underflow_error& e)
                    {
                        cout << e.what() << endl;
                    }

                    break;
                }
            case 3:
                {
                    cout << "��������� �����: " << FreeSpace(rb) << endl;
                    break;
                }
            case 4:
                {
                    cout << "������� �����: " << OccupiedSpace(rb) << endl;
                    break;
                }
            case 5:
                {
                    cout << "������� ����� ������ ������: ";

                    newSize = GetIntegerInput();

                    ResizeBuffer(rb, newSize);
                    cout << "������ ������ ������� �� " << newSize << ".\n";
                    break;
                }
            case 0:
                {
                    cout << "������� � �������� ����...\n";
                    break;
                }
            default:
                {
                    cout << "������������ �����, ���������� �����.\n";
                }
        }

    } while (choice != 0);
}

void ShowQueueMenu(Queue* queue) 
{
    int choice, value, newSize;

    do {
        cout << "\n������ � �������� �� ������ ���������� ������:\n";
        cout << "1. �������� ������� (Enqueue)\n";
        cout << "2. ������� ������� (Dequeue)\n";
        cout << "3. ���������, ����� �� �������\n";
        cout << "4. �������� ������ �������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        
        choice = GetIntegerInput();

        switch (choice) 
        {
        case 1:
            {
                cout << "������� �������� ��� ���������� � �������: ";

                value = GetIntegerInput();

                try 
                {
                    Enqueue(queue, value);
                    cout << "������� " << value << " �������� � �������.\n";
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
                    cout << "�������� �������: " << value << endl;
                }
                catch (const underflow_error& e)
                {
                    cout << e.what() << endl;
                }

                break;
            }
        case 3:
            {
                cout << (IsQueueEmpty(queue) ? "������� �����." : "������� �� �����.") << endl;
                break;
            }
        case 4:
            {
                cout << "������� ����� ������ �������: ";

                newSize = GetIntegerInput();

                ResizeBuffer(&queue->buffer, newSize);
                cout << "������ ������� ������� �� " << newSize << ".\n";
                break;
            }
        case 0:
            {
                cout << "������� � �������� ����...\n";
                break;
            }
        default:
            {
                cout << "������������ �����, ���������� �����.\n";
            }
        }

    } while (choice != 0);
}

void ShowQueue2StacksMenu(Queue2Stacks* queue) 
{
    int choice, value, newSize;

    do {
        cout << "\n������ � �������� �� ������ ���� ������:\n";
        cout << "1. �������� ������� (Enqueue)\n";
        cout << "2. ������� ������� (Dequeue)\n";
        cout << "3. ���������, ����� �� �������\n";
        cout << "4. �������� ������ �������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";

        choice = GetIntegerInput();

        switch (choice)
        {
        case 1:
            {
                cout << "������� �������� ��� ���������� � �������: ";

                value = GetIntegerInput();

                Enqueue2Stacks(queue, value);
                cout << "������� " << value << " �������� � �������.\n";
                break;
            }
        case 2:
            {
                if (!IsQueue2StacksEmpty(queue)) {
                    value = Dequeue2Stacks(queue);
                    cout << "�������� �������: " << value << endl;
                }
                else
                {
                    cout << "������� �����.\n";
                }

                break;
            }
        case 3:
            {
                cout << (IsQueue2StacksEmpty(queue) ? "������� �����." : "������� �� �����.") << endl;
                break;
            }
        case 4:
            {
                cout << "������� ����� ������ �������: ";

                newSize = GetIntegerInput();

                Resize(&queue->stack1, newSize);
                Resize(&queue->stack2, newSize);
                cout << "������ ������� ������� �� " << newSize << ".\n";
                break;
            }
        case 0:
            {
                cout << "������� � �������� ����...\n";
                break;
            }
        default:
            {
                cout << "������������ �����, ���������� �����.\n";
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
        cout << "\n�������� ����:\n";
        cout << "1. ������ �� ������\n";
        cout << "2. ������ � ��������� �������\n";
        cout << "3. ������ � �������� (�� ���� ���������� ������)\n";
        cout << "4. ������ � �������� (�� ���� ���� ������)\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        
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
                cout << "����� �� ���������.\n";
                break;
            }
        default:
            {
                cout << "������������ �����, ���������� �����.\n";
            }
        }

    } while (choice != 0);

    Delete(&stack);
    FreeBuffer(&ringBuffer);
    FreeQueue(&queue);
    FreeQueue2Stacks(&queue2Stacks);
}
