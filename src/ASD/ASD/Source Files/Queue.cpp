#include <iostream>
#include "Queue.h"
#include "RingBuffer.h"

void InitQueue(Queue* queue, size_t size) 
{
    InitBuffer(queue->Buffer, size);
}

void FreeQueue(Queue* queue) 
{
    FreeBuffer(queue->Buffer);
}

void Enqueue(Queue* queue, int item) 
{
    if (queue->Buffer != nullptr && (queue->Buffer->CurrentSize == queue->Buffer->MaxSize))
    {
        ResizeBuffer(queue->Buffer, static_cast<size_t>(queue->Buffer->MaxSize * queue->GrowthFactor));
    }
    Add(queue->Buffer, item);
}

int Dequeue(Queue* queue) 
{
    return Remove(queue->Buffer);
}

bool IsQueueEmpty(const Queue* queue) 
{
    return queue->Buffer->CurrentSize == 0;
}

size_t QueueFreeSpace(const Queue* queue)
{
    return FreeSpace(queue->Buffer);
}

size_t QueueOccupiedSpace(const Queue* queue) 
{
    return OccupiedSpace(queue->Buffer);
}
