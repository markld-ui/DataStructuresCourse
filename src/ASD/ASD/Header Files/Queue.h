#ifndef QUEUE_H
#define QUEUE_H

#include "RingBuffer.h"

//! \brief ��������� ������� �� ������ ���������� ������.
struct Queue 
{
    RingBuffer* Buffer = new RingBuffer();                  //!< ��������� ����� ��� �������� ��������� �������.
    const double GrowthFactor = 1.5;                        //!< growthFactor ��������������� ���������� ������ �������
};

//! \brief �������������� �������.
//! \param queue ��������� �� ��������� Queue.
//! \param size ������ �������.
void InitQueue(Queue* queue, size_t size);

//! \brief ����������� ������, ������� ��������.
//! \param queue ��������� �� ��������� Queue.
void FreeQueue(Queue* queue);

//! \brief ��������� ������� � �������.
//! \param queue ��������� �� ��������� Queue.
//! \param item ����������� �������.
void Enqueue(Queue* queue, int item);

//! \brief ��������� ������� �� �������.
//! \param queue ��������� �� ��������� Queue.
//! \return ����������� �������.
int Dequeue(Queue* queue);

//! \brief ���������, ����� �� �������.
//! \param queue ��������� �� ��������� Queue.
//! \return true, ���� ������� �����, ����� false.
bool IsQueueEmpty(const Queue* queue);

//! \brief ���������� ��������� ����� � �������.
//! \param queue ��������� �� ��������� Queue.
size_t QueueFreeSpace(const Queue* queue);

//! \brief ���������� ������� ����� � �������.
//! \param queue ��������� �� ��������� Queue.
size_t QueueOccupiedSpace(const Queue* queue);

#endif
