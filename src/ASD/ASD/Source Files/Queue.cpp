#include <iostream>
#include "Queue.h"
#include "RingBuffer.h"

void InitQueue(Queue* queue, size_t size) 
{
    InitBuffer(&(queue->buffer), size);
}

void FreeQueue(Queue* queue) 
{
    FreeBuffer(&(queue->buffer));
}

void Enqueue(Queue* queue, int item) 
{
    Add(&(queue->buffer), item);
}

int Dequeue(Queue* queue) 
{
    return Remove(&(queue->buffer));
}

bool IsQueueEmpty(const Queue* queue) 
{
    return queue->buffer.currentSize == 0;
}

size_t QueueFreeSpace(const Queue* queue)
{
    return FreeSpace(&(queue->buffer));
}

size_t QueueOccupiedSpace(const Queue* queue) 
{
    return OccupiedSpace(&(queue->buffer));
}
