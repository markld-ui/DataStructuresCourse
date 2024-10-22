#include <iostream>
#include "List.h"
#include "ListMenu.h"

int main()
{
    setlocale(LC_ALL, "ru");
    DoublyLinkedList* list = new DoublyLinkedList();

    ShowMenu(list);

    delete list;

    return 0;
}