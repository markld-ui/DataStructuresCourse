#include <iostream>
#include "RingBuffer.h"

void InitBuffer(RingBuffer* rb, size_t size) 
{
    if (size <= 0) 
    {
        throw std::invalid_argument("Размер должен быть больше нуля.");
    }

    rb->Buffer = new int[size];
    rb->MaxSize = size;
    rb->Head = 0;
    rb->Tail = 0;
    rb->CurrentSize = 0;
}

void FreeBuffer(RingBuffer* rb) 
{
    delete[] rb->Buffer;
}

size_t FreeSpace(const RingBuffer* rb) 
{
    return rb->MaxSize - rb->CurrentSize;
}

size_t OccupiedSpace(const RingBuffer* rb) 
{
    return rb->CurrentSize;
}

void Add(RingBuffer* rb, int item) 
{
    if (rb->CurrentSize == rb->MaxSize) 
    {
        throw std::overflow_error("Буффер полон.");
    }

    rb->Buffer[rb->Tail] = item;
    rb->Tail = (rb->Tail + 1) % rb->MaxSize; 
    rb->CurrentSize++;
}

int Remove(RingBuffer* rb) 
{
    if (rb->CurrentSize == 0) 
    {
        throw std::underflow_error("Буффер пуст.");
    }

    int item = rb->Buffer[rb->Head];
    rb->Head = (rb->Head + 1) % rb->MaxSize;
    rb->CurrentSize--;
    return item;
}

void ResizeBuffer(RingBuffer* rb, size_t newSize)
{
    int* newBuffer = new int[newSize];
    for (size_t i = 0; i < rb->CurrentSize; ++i)
    {
        newBuffer[i] = rb->Buffer[(rb->Head + i) % rb->MaxSize];
    }

    delete[] rb->Buffer;
    rb->Buffer = newBuffer;
    rb->MaxSize = newSize;
    rb->Head = 0;
    rb->Tail = rb->CurrentSize;
}