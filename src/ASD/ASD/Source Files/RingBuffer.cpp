#include <iostream>
#include "RingBuffer.h"

void InitBuffer(RingBuffer* rb, size_t size) 
{
    if (size <= 0) 
    {
        throw std::invalid_argument("Размер должен быть больше нуля.");
    }

    rb->buffer = new int[size];
    rb->maxSize = size;
    rb->head = 0;
    rb->tail = 0;
    rb->currentSize = 0;
}

void FreeBuffer(RingBuffer* rb) 
{
    delete[] rb->buffer;
}

size_t FreeSpace(const RingBuffer* rb) 
{
    return rb->maxSize - rb->currentSize;
}

size_t OccupiedSpace(const RingBuffer* rb) 
{
    return rb->currentSize;
}

void Add(RingBuffer* rb, int item) 
{
    if (rb->currentSize == rb->maxSize) 
    {
        throw std::overflow_error("Буффер полон.");
    }

    rb->buffer[rb->tail] = item;
    rb->tail = (rb->tail + 1) % rb->maxSize; 
    rb->currentSize++;
}

int Remove(RingBuffer* rb) 
{
    if (rb->currentSize == 0) 
    {
        throw std::underflow_error("Буффер пуст.");
    }

    int item = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % rb->maxSize;
    rb->currentSize--;
    return item;
}

void ResizeBuffer(RingBuffer* rb, size_t newSize)
{
    int* newBuffer = new int[newSize];
    for (size_t i = 0; i < rb->currentSize; ++i)
    {
        newBuffer[i] = rb->buffer[(rb->head + i) % rb->maxSize];
    }
    delete[] rb->buffer;
    rb->buffer = newBuffer;
    rb->maxSize = newSize;
    rb->head = 0;
    rb->tail = rb->currentSize;
}