#include "DynamicArray.h"
#include <iostream>
#include <algorithm>

using namespace std;

DynamicArray::DynamicArray() : _size(0), _capacity(4), _growthFactor(1.5)
{
    _array = new int[_capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] _array;
}

// Возвращает размер массива
int DynamicArray::GetSize()
{
    return _size;
}

// Возвращает вместимость массива
int DynamicArray::GetCapacity()
{
    return _capacity;
}

// Возвращает массив
int* DynamicArray::GetArray()
{
    return _array;
}

// Функция для увеличения размера массива
void DynamicArray::Resize(int newCapacity)
{
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; ++i)
    {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

// Добавляет элемент в массив (в конец, если индекс = size)
void DynamicArray::AddElement(int index, int value)
{
    if (_size == _capacity)
    {
        Resize(_capacity * _growthFactor);
    }
    if (index < 0  || index > _size)
    {
        cerr << "Ошибка: Неверный индекс\n";
        return;
    }
    for (int i = _size; i > index; --i)
    {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
    ++_size;
}

// Удаляет элемент по индексу
void DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        cerr << "Ошибка: Неверный индекс\n";
        return;
    }
    for (int i = index; i < _size - 1; ++i)
    {
        _array[i] = _array[i + 1];
    }
    --_size;

    if (_capacity > _size * 2)
    {
        Resize(_capacity / _growthFactor);
    }
}

// Удаляет элемент по значению
void DynamicArray::RemoveByValue(int value)
{
    int index = -1;
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        RemoveByIndex(index);
    }
    else
    {
        cerr << "Элемент не найден\n";
    }
}

// Возвращает элемент по индексу
int DynamicArray::GetElemnt(int index)
{
    if (index < 0 || index >= _size)
    {
        cerr << "Ошибка: Неверный индекс\n";
        return -1;
    }
    return _array[index];
}

// Сортировка массива (используем std::sort)
void DynamicArray::SortArray()
{
    sort(_array, _array + _size);
}

// Линейный поиск элемента
void DynamicArray::LinerSearch(int value)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            cout << "Элемент найден на индексе: " << i << "\n";
            return;
        }
    }
    cout << "Элемент не найден\n";
}

// Бинарный поиск элемента (массив должен быть отсортирован)
void DynamicArray::BinarySearch(int value)
{
    int left = 0;
    int right = _size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (_array[mid] == value)
        {
            cout << "Элемент найден на индексе: " << mid << "\n";
            return;
        }
        else if (_array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "Элемент не найден\n";
}

// Сортировка выбором
void DynamicArray::SelectionSort()
{
    for (int i = 0; i < _size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < _size; ++j)
        {
            if (_array[j] < _array[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = _array[i];
            _array[i] = _array[minIndex];
            _array[minIndex] = temp;
        }
    }
}