#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

//! \brief —труктура дл€ представлени€ двусв€зного списка.
struct DoublyLinkedList
{
private:
    Node* head; //!< ”казатель на первый узел списка.
    Node* tail; //!< ”казатель на последний узел списка.

public:
    //! \brief  онструктор дл€ создани€ пустого двусв€зного списка.
    DoublyLinkedList();

    //! \brief ƒеструктор дл€ освобождени€ пам€ти, зан€той списком.
    ~DoublyLinkedList();

    //! \brief ƒобавл€ет значение в конец списка.
    //! \param value «начение, которое будет добавлено.
    void add(int value);

    //! \brief ”дал€ет узел со значением value из списка.
    //! \param value «начение узла, который нужно удалить.
    void remove(int value);

    //! \brief ¬ставл€ет значение в начало списка.
    //! \param value «начение, которое будет вставлено.
    void insertAtBeginning(int value);

    //! \brief ¬ставл€ет значение в конец списка.
    //! \param value «начение, которое будет вставлено.
    void insertAtEnd(int value);

    //! \brief ¬ставл€ет значение после узла с заданным значением.
    //! \param afterValue «начение узла, после которого будет вставлено новое значение.
    //! \param value «начение, которое будет вставлено.
    void insertAfter(int afterValue, int value);

    //! \brief ¬ставл€ет значение перед узлом с заданным значением.
    //! \param beforeValue «начение узла, перед которым будет вставлено новое значение.
    //! \param value «начение, которое будет вставлено.
    void insertBefore(int beforeValue, int value);

    //! \brief —ортирует список.
    void sort();

    //! \brief ¬ыполн€ет линейный поиск узла со значением value.
    //! \param value «начение, которое нужно найти.
    //! \return ”казатель на узел с найденным значением или nullptr, если не найдено.
    Node* linearSearch(int value);

    //! \brief ѕечатает содержимое списка.
    void printList();
};

#endif