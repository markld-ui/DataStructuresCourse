#include <iostream>
#include "Queue2Stacks.h"
#include "Stack.h"

void InitQueue2Stacks(Queue2Stacks* queue, int size) 
{
    Initialize(&(queue->Stack1), size);
    Initialize(&(queue->Stack2), size);
}

void FreeQueue2Stacks(Queue2Stacks* queue) 
{
    Delete(&(queue->Stack1));
    Delete(&(queue->Stack2));
}

void Enqueue2Stacks(Queue2Stacks* queue, int item) 
{
    Push(&(queue->Stack1), item);
}

int Dequeue2Stacks(Queue2Stacks* queue) 
{
    if (IsEmpty(&(queue->Stack2))) 
    {
        while (!IsEmpty(&(queue->Stack1))) 
        {
            Push(&(queue->Stack2), Pop(&(queue->Stack1)));
        }
    }

    return Pop(&(queue->Stack2));
}

bool IsQueue2StacksEmpty(const Queue2Stacks* queue) 
{
    return IsEmpty(&(queue->Stack1)) && IsEmpty(&(queue->Stack2));
}
