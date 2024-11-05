#ifndef RINGBUFFER_H
#define RINGBUFFER_H

//! \brief ��������� ���������� ������.
struct RingBuffer {
    int* buffer;          //!< ��������� �� ������ ������.
    size_t maxSize;      //!< ������������ ������ ������.
    size_t head;          //!< ������ ������ ������.
    size_t tail;          //!< ������ ����� ������.
    size_t currentSize;  //!< ������� ������ ������.
};


//! \brief �������������� ��������� �����.
//! \param rb ��������� �� ��������� RingBuffer.
//! \param size ������ ������.
void InitBuffer(RingBuffer* rb, size_t size);

//! \brief ����������� ������, ������� �������.
//! \param rb ��������� �� ��������� RingBuffer.
void FreeBuffer(RingBuffer* rb);

//! \brief ���������� ���������� ��������� ���� � ������.
//! \param rb ��������� �� ��������� RingBuffer.
size_t FreeSpace(const RingBuffer* rb);

//! \brief ���������� ���������� ������� ���� � ������.
//! \param rb ��������� �� ��������� RingBuffer.
size_t OccupiedSpace(const RingBuffer* rb);

//! \brief ��������� ������� � �����.
//! \param rb ��������� �� ��������� RingBuffer.
//! \param item ����������� �������.
void Add(RingBuffer* rb, int item);

//! \brief ��������� ������� �� ������.
//! \param rb ��������� �� ��������� RingBuffer.
//! \return ����������� �������.
int Remove(RingBuffer* rb);

//! \brief �������� ������ ������ ��� �������������.
//! \param rb ��������� �� ��������� RingBuffer.
//! \param newSize ����� ������ ������.
void ResizeBuffer(RingBuffer* rb, size_t newSize);

#endif