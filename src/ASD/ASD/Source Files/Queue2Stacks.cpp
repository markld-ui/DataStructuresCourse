#include <iostream>
#include "Queue2Stacks.h"
#include "Stack.h"

void InitQueue2Stacks(Queue2Stacks* queue, int size) 
{
    Initialize(&(queue->stack1), size);
    Initialize(&(queue->stack2), size);
}

void FreeQueue2Stacks(Queue2Stacks* queue) 
{
    Delete(&(queue->stack1));
    Delete(&(queue->stack2));
}

void Enqueue2Stacks(Queue2Stacks* queue, int item) 
{
    Push(&(queue->stack1), item);
}

int Dequeue2Stacks(Queue2Stacks* queue) 
{
    if (IsEmpty(&(queue->stack2))) 
    {
        while (!IsEmpty(&(queue->stack1))) 
        {
            Push(&(queue->stack2), Pop(&(queue->stack1)));
        }
    }

    return Pop(&(queue->stack2));
}

bool IsQueue2StacksEmpty(const Queue2Stacks* queue) 
{
    return IsEmpty(&(queue->stack1)) && IsEmpty(&(queue->stack2));
}
