#include <iostream>
#include "List.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* current = _head;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void DoublyLinkedList::Add(int value)
{
	Node* newNode = new Node(value);
	if (!_head)
	{
		_head = _tail = newNode;
	}
	else
	{
		_tail->next = newNode;
		newNode->prev = _tail;
		_tail = newNode;
	}
}

void DoublyLinkedList::Remove(int value)
{
	Node* current = _head;
	while (current) 
	{
		if (current->data == value) 
		{
			if (current->prev)
			{
				current->prev->next = current->next;
			}
			else
			{
				_head = current->next;
			}
			
			if (current->next) 
			{
				current->next->prev = current->prev;
			}
			else 
			{
				_tail = current->prev;
			}

			delete current;
			return;
		}

		current = current->next;
	}
}

void DoublyLinkedList::InsertAtBeginning(int value) 
{
	Node* newNode = new Node(value);
	if (_head) {
		newNode->next = _head;
		_head->prev = newNode;
		_head = newNode;
	}
	else 
	{
		_head = _tail = newNode;
	}
}

void DoublyLinkedList::InsertAtEnd(int value)
{
	Add(value);
}

void DoublyLinkedList::InsertAfter(int afterValue, int value)
{
	Node* current = _head;
	while (current) 
	{
		if (current->data == afterValue) 
		{
			Node* newNode = new Node(value);
			newNode->next = current->next;
			newNode->prev = current;

			if (current->next) 
			{
				current->next->prev = newNode;
			}
			else 
			{
				_tail = newNode;
			}

			current->next = newNode;
			return;
		}

		current = current->next;
	}
}

void DoublyLinkedList::InsertBefore(int beforeValue, int value) 
{
	Node* current = _head;
	while (current) 
	{
		if (current->data == beforeValue)
		{
			if (current->prev)
			{
				Node* newNode = new Node(value);
				newNode->next = current;
				newNode->prev = current->prev;
				current->prev->next = newNode;
				current->prev = newNode;
			}
			else
			{
				InsertAtBeginning(value);
			}

			return;
		}

		current = current->next;
	}
}

void DoublyLinkedList::Sort() 
{
	if (!_head) return;
	Node* current = _head;
	while (current) 
	{
		Node* nextNode = current->next;
		while (nextNode) 
		{
			if (current->data > nextNode->data)
			{
				swap(current->data, nextNode->data);
			}

			nextNode = nextNode->next;
		}

		current = current->next;
	}
}

int DoublyLinkedList::LinearSearch(int value) 
{
	Node* current = _head;
	int index = 0;

	while (current) 
	{
		if (current->data == value)
		{
			return index;
		}

		current = current->next;
		index++;
	}

	return -1;
}