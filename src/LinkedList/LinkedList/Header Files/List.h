#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

//! \brief ��������� ��� ������������� ����������� ������.
struct DoublyLinkedList
{
private:
    Node* _head; //!< ��������� �� ������ ���� ������.
    Node* _tail; //!< ��������� �� ��������� ���� ������.

public:
    //! \brief ����������� ��� �������� ������� ����������� ������.
    DoublyLinkedList();

    //! \brief ���������� ��� ������������ ������, ������� �������.
    ~DoublyLinkedList();

    //! \brief ��������� �������� � ����� ������.
    //! \param value ��������, ������� ����� ���������.
    void Add(int value);

    //! \brief ������� ���� �� ��������� value �� ������.
    //! \param value �������� ����, ������� ����� �������.
    void Remove(int value);

    //! \brief ��������� �������� � ������ ������.
    //! \param value ��������, ������� ����� ���������.
    void InsertAtBeginning(int value);

    //! \brief ��������� �������� � ����� ������.
    //! \param value ��������, ������� ����� ���������.
    void InsertAtEnd(int value);

    //! \brief ��������� �������� ����� ���� � �������� ���������.
    //! \param afterValue �������� ����, ����� �������� ����� ��������� ����� ��������.
    //! \param value ��������, ������� ����� ���������.
    void InsertAfter(int afterValue, int value);

    //! \brief ��������� �������� ����� ����� � �������� ���������.
    //! \param beforeValue �������� ����, ����� ������� ����� ��������� ����� ��������.
    //! \param value ��������, ������� ����� ���������.
    void InsertBefore(int beforeValue, int value);

    //! \brief ��������� ������.
    void Sort();

    //! \brief ��������� �������� ����� ���� �� ��������� value.
    //! \param value ��������, ������� ����� �����.
    //! \return ������ �������� ���� -1, ���� �� �������.
    int LinearSearch(int value);

    //! \brief ������ ��������� �� ������ ���� ������
    Node* getHead() const { return _head; }
};

//! \brief �������� ���������� ������.
void PrintList(const DoublyLinkedList& list);

#endif