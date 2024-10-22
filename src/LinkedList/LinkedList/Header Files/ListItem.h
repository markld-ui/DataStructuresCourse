#ifndef LISTITEM_H
#define LISTITEM_H

//! \brief Структура для представления узла двусвязного списка.
struct Node
{
	//! \brief Значение, хранящееся в узле.
	int data;

	//! \brief Указатель на следующий узел в списке.
	Node* next;

	//! \brief Указатель на предыдущий узел в списке.
	Node* prev;

	//! \brief Конструктор для создания узла со значением.
	//! \param value Значение, которое будет храниться в узле.
	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

#endif