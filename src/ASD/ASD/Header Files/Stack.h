#ifndef STACK_H
#define STACK_H

//! \brief Структура стека.
struct Stack
{
	int* Buffer;		//!< Указатель на массив данных.
	int BufferSize;		//!< Максимальный размер стека.
	int Top;			//!< Индекс вершины стека.
};

//! \brief Инициализирует стек.
//! \param stack Указатель на структуру Stack.
//! \param size Размер стека.
void Initialize(Stack* stack, int size);

//! \brief Добавляет элемент в стек.
//! \param stack Указатель на структуру Stack.
//! \param data Добавляемый элемент.
void Push(Stack* stack, int data);

//! \brief Извлекает элемент из стека.
//! \param stack Указатель на структуру Stack.
//! \return Извлечённый элемент.
int Pop(Stack* stack);

//! \brief Проверяет, пуст ли стек.
//! \param stack Указатель на структуру Stack.
//! \return true, если стек пуст, иначе false.
bool IsEmpty(const Stack* stack);

//! \brief Удаляет стек и освобождает память.
//! \param stack Указатель на структуру Stack.
void Delete(Stack* stack);

//! \brief Изменяет размер стека.
//! \param stack Указатель на структуру Stack.
//! \param newSize Новый размер стека.
void Resize(Stack* stack, int newSize);

#endif