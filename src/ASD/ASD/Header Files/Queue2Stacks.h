#ifndef QUEUE2STACKS_H
#define QUEUE2STACKS_H

#include "Stack.h"

//! \brief Структура очереди на основе двух стеков.
struct Queue2Stacks {
    Stack stack1;           //!< Первый стек для реализации очереди.
    Stack stack2;           //!< Второй стек для реализации очереди.
};

//! \brief Инициализирует очередь на основе двух стеков.
//! \param queue Указатель на структуру Queue2Stacks.
//! \param size Размер стека.
void InitQueue2Stacks(Queue2Stacks* queue, int size);

//! \brief Освобождает память, занятую очередью.
//! \param queue Указатель на структуру Queue2Stacks.
void FreeQueue2Stacks(Queue2Stacks* queue);

//! \brief Добавляет элемент в очередь.
//! \param queue Указатель на структуру Queue2Stacks.
//! \param item Добавляемый элемент.
void Enqueue2Stacks(Queue2Stacks* queue, int item);

//! \brief Извлекает элемент из очереди.
//! \param queue Указатель на структуру Queue2Stacks.
//! \return Извлечённый элемент.
int Dequeue2Stacks(Queue2Stacks* queue);

//! \brief Проверяет, пуста ли очередь.
//! \param queue Указатель на структуру Queue2Stacks.
//! \return true, если очередь пуста, иначе false.
bool IsQueue2StacksEmpty(const Queue2Stacks* queue);

#endif
