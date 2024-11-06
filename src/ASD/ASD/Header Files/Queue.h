#ifndef QUEUE_H
#define QUEUE_H

#include "RingBuffer.h"

//! \brief Структура очереди на основе кольцевого буфера.
struct Queue 
{
    RingBuffer* Buffer = new RingBuffer();                  //!< Кольцевой буфер для хранения элементов очереди.
    const double GrowthFactor = 1.5;                        //!< growthFactor автоматического увелечения объёма очереди
};

//! \brief Инициализирует очередь.
//! \param queue Указатель на структуру Queue.
//! \param size Размер очереди.
void InitQueue(Queue* queue, size_t size);

//! \brief Освобождает память, занятую очередью.
//! \param queue Указатель на структуру Queue.
void FreeQueue(Queue* queue);

//! \brief Добавляет элемент в очередь.
//! \param queue Указатель на структуру Queue.
//! \param item Добавляемый элемент.
void Enqueue(Queue* queue, int item);

//! \brief Извлекает элемент из очереди.
//! \param queue Указатель на структуру Queue.
//! \return Извлечённый элемент.
int Dequeue(Queue* queue);

//! \brief Проверяет, пуста ли очередь.
//! \param queue Указатель на структуру Queue.
//! \return true, если очередь пуста, иначе false.
bool IsQueueEmpty(const Queue* queue);

//! \brief Возвращает свободное место в очереди.
//! \param queue Указатель на структуру Queue.
size_t QueueFreeSpace(const Queue* queue);

//! \brief Возвращает занятое место в очереди.
//! \param queue Указатель на структуру Queue.
size_t QueueOccupiedSpace(const Queue* queue);

#endif
