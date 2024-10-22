#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

//! \brief ��������� ��� ������������� ����������� ������.
struct DoublyLinkedList
{
private:
    Node* head; //!< ��������� �� ������ ���� ������.
    Node* tail; //!< ��������� �� ��������� ���� ������.

public:
    //! \brief ����������� ��� �������� ������� ����������� ������.
    DoublyLinkedList();

    //! \brief ���������� ��� ������������ ������, ������� �������.
    ~DoublyLinkedList();

    //! \brief ��������� �������� � ����� ������.
    //! \param value ��������, ������� ����� ���������.
    void add(int value);

    //! \brief ������� ���� �� ��������� value �� ������.
    //! \param value �������� ����, ������� ����� �������.
    void remove(int value);

    //! \brief ��������� �������� � ������ ������.
    //! \param value ��������, ������� ����� ���������.
    void insertAtBeginning(int value);

    //! \brief ��������� �������� � ����� ������.
    //! \param value ��������, ������� ����� ���������.
    void insertAtEnd(int value);

    //! \brief ��������� �������� ����� ���� � �������� ���������.
    //! \param afterValue �������� ����, ����� �������� ����� ��������� ����� ��������.
    //! \param value ��������, ������� ����� ���������.
    void insertAfter(int afterValue, int value);

    //! \brief ��������� �������� ����� ����� � �������� ���������.
    //! \param beforeValue �������� ����, ����� ������� ����� ��������� ����� ��������.
    //! \param value ��������, ������� ����� ���������.
    void insertBefore(int beforeValue, int value);

    //! \brief ��������� ������.
    void sort();

    //! \brief ��������� �������� ����� ���� �� ��������� value.
    //! \param value ��������, ������� ����� �����.
    //! \return ��������� �� ���� � ��������� ��������� ��� nullptr, ���� �� �������.
    Node* linearSearch(int value);

    //! \brief �������� ���������� ������.
    void printList();
};

#endif