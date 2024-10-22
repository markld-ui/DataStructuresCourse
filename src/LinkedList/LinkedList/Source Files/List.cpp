#include <iostream>
#include "List.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* current = head;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void DoublyLinkedList::add(int value)
{
	Node* newNode = new Node(value);
	if (!head)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void DoublyLinkedList::remove(int value)
{
	Node* current = head;
	while (current) 
	{
		if (current->data == value) {
			if (current->prev) {
				current->prev->next = current->next;
			}
			else {
				head = current->next;
			}
			if (current->next) {
				current->next->prev = current->prev;
			}
			else {
				tail = current->prev;
			}
			delete current;
			return;
		}
		current = current->next;
	}
}

void DoublyLinkedList::insertAtBeginning(int value) {
	Node* newNode = new Node(value);
	if (head) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else {
		head = tail = newNode;
	}
}

void DoublyLinkedList::insertAtEnd(int value) {
	add(value);
}

void DoublyLinkedList::insertAfter(int afterValue, int value) {
	Node* current = head;
	while (current) {
		if (current->data == afterValue) {
			Node* newNode = new Node(value);
			newNode->next = current->next;
			newNode->prev = current;

			if (current->next) {
				current->next->prev = newNode;
			}
			else {
				tail = newNode;
			}
			current->next = newNode;
			return;
		}
		current = current->next;
	}
}

void DoublyLinkedList::insertBefore(int beforeValue, int value) {
	Node* current = head;
	while (current) {
		if (current->data == beforeValue) {
			if (current->prev) {
				Node* newNode = new Node(value);
				newNode->next = current;
				newNode->prev = current->prev;
				current->prev->next = newNode;
				current->prev = newNode;
			}
			else {
				insertAtBeginning(value);
			}
			return;
		}
		current = current->next;
	}
}

void DoublyLinkedList::sort() {
	if (!head) return;
	Node* current = head;
	while (current) {
		Node* nextNode = current->next;
		while (nextNode) {
			if (current->data > nextNode->data) {
				swap(current->data, nextNode->data);
			}
			nextNode = nextNode->next;
		}
		current = current->next;
	}
}

Node* DoublyLinkedList::linearSearch(int value) {
	Node* current = head;
	while (current) {
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void DoublyLinkedList::printList() {
	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}