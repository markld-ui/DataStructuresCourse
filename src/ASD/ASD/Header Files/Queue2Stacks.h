#ifndef QUEUE2STACKS_H
#define QUEUE2STACKS_H

#include "Stack.h"

//! \brief ��������� ������� �� ������ ���� ������.
struct Queue2Stacks {
    Stack stack1;           //!< ������ ���� ��� ���������� �������.
    Stack stack2;           //!< ������ ���� ��� ���������� �������.
};

//! \brief �������������� ������� �� ������ ���� ������.
//! \param queue ��������� �� ��������� Queue2Stacks.
//! \param size ������ �����.
void InitQueue2Stacks(Queue2Stacks* queue, int size);

//! \brief ����������� ������, ������� ��������.
//! \param queue ��������� �� ��������� Queue2Stacks.
void FreeQueue2Stacks(Queue2Stacks* queue);

//! \brief ��������� ������� � �������.
//! \param queue ��������� �� ��������� Queue2Stacks.
//! \param item ����������� �������.
void Enqueue2Stacks(Queue2Stacks* queue, int item);

//! \brief ��������� ������� �� �������.
//! \param queue ��������� �� ��������� Queue2Stacks.
//! \return ����������� �������.
int Dequeue2Stacks(Queue2Stacks* queue);

//! \brief ���������, ����� �� �������.
//! \param queue ��������� �� ��������� Queue2Stacks.
//! \return true, ���� ������� �����, ����� false.
bool IsQueue2StacksEmpty(const Queue2Stacks* queue);

#endif
