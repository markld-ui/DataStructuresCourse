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

// ���������� ������ �������
int DynamicArray::GetSize()
{
    return _size;
}

// ���������� ����������� �������
int DynamicArray::GetCapacity()
{
    return _capacity;
}

// ���������� ������
int* DynamicArray::GetArray()
{
    return _array;
}

// ������� ��� ���������� ������� �������
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

// ��������� ������� � ������ (� �����, ���� ������ = size)
void DynamicArray::AddElement(int index, int value)
{
    if (_size == _capacity)
    {
        Resize(_capacity * _growthFactor);
    }
    if (index < 0  || index > _size)
    {
        cerr << "������: �������� ������\n";
        return;
    }
    for (int i = _size; i > index; --i)
    {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
    ++_size;
}

// ������� ������� �� �������
void DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        cerr << "������: �������� ������\n";
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

// ������� ������� �� ��������
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
        cerr << "������� �� ������\n";
    }
}

// ���������� ������� �� �������
int DynamicArray::GetElemnt(int index)
{
    if (index < 0 || index >= _size)
    {
        cerr << "������: �������� ������\n";
        return -1;
    }
    return _array[index];
}

// ���������� ������� (���������� std::sort)
void DynamicArray::SortArray()
{
    sort(_array, _array + _size);
}

// �������� ����� ��������
void DynamicArray::LinerSearch(int value)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            cout << "������� ������ �� �������: " << i << "\n";
            return;
        }
    }
    cout << "������� �� ������\n";
}

// �������� ����� �������� (������ ������ ���� ������������)
void DynamicArray::BinarySearch(int value)
{
    int left = 0;
    int right = _size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (_array[mid] == value)
        {
            cout << "������� ������ �� �������: " << mid << "\n";
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
    cout << "������� �� ������\n";
}

// ���������� �������
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