#ifndef MENU_H
#define MENU_H

#include "Stack.h"       
#include "RingBuffer.h"   
#include "Queue.h"        
#include "Queue2Stacks.h" 

//! \brief ������� ���� ���������, ����������� ������� �������� ��� ����������� ������.
void ShowMenu();

//! \brief ���� ��� ������ �� ������.
//! \param stack ��������� �� ��������� Stack.
void ShowStackMenu(Stack* stack);        

//! \brief ���� ��� ������ � ��������� �������.
//! \param ring_buffer ��������� �� ��������� RingBuffer.
void ShowRingBufferMenu(RingBuffer* rb); 

//! \brief ���� ��� ������ � �������� �� ������ ���������� ������.
//! \param queue ��������� �� ��������� Queue.
void ShowQueueMenu(Queue* queue);      

//! \brief ���� ��� ������ � �������� �� ������ ���� ������.
//! \param queue ��������� �� ��������� Queue2Stacks.
void ShowQueue2StacksMenu(Queue2Stacks* queue);

//! \brief �������� ����� �����.
void ClearInput();

//! \brief �������� ������������� ���� �� ������������ � ���������� ������.
//! \return ��������� ����� �����.
int GetIntegerInput();

#endif