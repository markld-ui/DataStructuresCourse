#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

//! \brief —труктура дл€ представлени€ двусв€зного списка.
struct DoublyLinkedList
{
private:
    Node* _head; //!< ”казатель на первый узел списка.
    Node* _tail; //!< ”казатель на последний узел списка.

public:
    //! \brief  онструктор дл€ создани€ пустого двусв€зного списка.
    DoublyLinkedList();

    //! \brief ƒеструктор дл€ освобождени€ пам€ти, зан€той списком.
    ~DoublyLinkedList();

    //! \brief ƒобавл€ет значение в конец списка.
    //! \param value «начение, которое будет добавлено.
    void Add(int value);

    //! \brief ”дал€ет узел со значением value из списка.
    //! \param value «начение узла, который нужно удалить.
    void Remove(int value);

    //! \brief ¬ставл€ет значение в начало списка.
    //! \param value «начение, которое будет вставлено.
    void InsertAtBeginning(int value);

    //! \brief ¬ставл€ет значение в конец списка.
    //! \param value «начение, которое будет вставлено.
    void InsertAtEnd(int value);

    //! \brief ¬ставл€ет значение после узла с заданным значением.
    //! \param afterValue «начение узла, после которого будет вставлено новое значение.
    //! \param value «начение, которое будет вставлено.
    void InsertAfter(int afterValue, int value);

    //! \brief ¬ставл€ет значение перед узлом с заданным значением.
    //! \param beforeValue «начение узла, перед которым будет вставлено новое значение.
    //! \param value «начение, которое будет вставлено.
    void InsertBefore(int beforeValue, int value);

    //! \brief —ортирует список.
    void Sort();

    //! \brief ¬ыполн€ет линейный поиск узла со значением value.
    //! \param value «начение, которое нужно найти.
    //! \return »ндекс элемента либо -1, если не найдено.
    int LinearSearch(int value);

    //! \brief √еттер указател€ на первый узел списка
    Node* getHead() const { return _head; }
};

//! \brief ѕечатает содержимое списка.
void PrintList(const DoublyLinkedList& list);

#endif