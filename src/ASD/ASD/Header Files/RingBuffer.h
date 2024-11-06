#ifndef RINGBUFFER_H
#define RINGBUFFER_H

//! \brief Структура кольцевого буфера.
struct RingBuffer 
{
    int* Buffer;          //!< Указатель на массив данных.
    size_t MaxSize;      //!< Максимальный размер буфера.
    size_t Head;          //!< Индекс начала буфера.
    size_t Tail;          //!< Индекс конца буфера.
    size_t CurrentSize;  //!< Текущий размер буфера.
};


//! \brief Инициализирует кольцевой буфер.
//! \param rb Указатель на структуру RingBuffer.
//! \param size Размер буфера.
void InitBuffer(RingBuffer* rb, size_t size);

//! \brief Освобождает память, занятую буфером.
//! \param rb Указатель на структуру RingBuffer.
void FreeBuffer(RingBuffer* rb);

//! \brief Возвращает количество свободных мест в буфере.
//! \param rb Указатель на структуру RingBuffer.
size_t FreeSpace(const RingBuffer* rb);

//! \brief Возвращает количество занятых мест в буфере.
//! \param rb Указатель на структуру RingBuffer.
size_t OccupiedSpace(const RingBuffer* rb);

//! \brief Добавляет элемент в буфер.
//! \param rb Указатель на структуру RingBuffer.
//! \param item Добавляемый элемент.
void Add(RingBuffer* rb, int item);

//! \brief Извлекает элемент из буфера.
//! \param rb Указатель на структуру RingBuffer.
//! \return Извлечённый элемент.
int Remove(RingBuffer* rb);

//! \brief Изменяет размер буфера при необходимости.
//! \param rb Указатель на структуру RingBuffer.
//! \param newSize Новый размер буфера.
void ResizeBuffer(RingBuffer* rb, size_t newSize);

#endif