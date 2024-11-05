#ifndef MENU_H
#define MENU_H

#include "Stack.h"       
#include "RingBuffer.h"   
#include "Queue.h"        
#include "Queue2Stacks.h" 

//! \brief Главное меню программы, позволяющее выбрать операции над структурами данных.
void ShowMenu();

//! \brief Меню для работы со стеком.
//! \param stack Указатель на структуру Stack.
void ShowStackMenu(Stack* stack);        

//! \brief Меню для работы с кольцевым буфером.
//! \param ring_buffer Указатель на структуру RingBuffer.
void ShowRingBufferMenu(RingBuffer* rb); 

//! \brief Меню для работы с очередью на основе кольцевого буфера.
//! \param queue Указатель на структуру Queue.
void ShowQueueMenu(Queue* queue);      

//! \brief Меню для работы с очередью на основе двух стеков.
//! \param queue Указатель на структуру Queue2Stacks.
void ShowQueue2StacksMenu(Queue2Stacks* queue);

//! \brief Очищение полей ввода.
void ClearInput();

//! \brief Получает целочисленный ввод от пользователя с обработкой ошибок.
//! \return Введенное целое число.
int GetIntegerInput();

#endif