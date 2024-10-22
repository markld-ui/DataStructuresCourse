#ifndef LISTITEM_H
#define LISTITEM_H

//! \brief ��������� ��� ������������� ���� ����������� ������.
struct Node
{
	//! \brief ��������, ���������� � ����.
	int data;

	//! \brief ��������� �� ��������� ���� � ������.
	Node* next;

	//! \brief ��������� �� ���������� ���� � ������.
	Node* prev;

	//! \brief ����������� ��� �������� ���� �� ���������.
	//! \param value ��������, ������� ����� ��������� � ����.
	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

#endif