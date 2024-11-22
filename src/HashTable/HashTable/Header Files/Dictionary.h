#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "HashTable.h"
#include <string>

using namespace std;

/*!
 * \brief Класс словаря
 */
class Dictionary
{
private:
    /*!
     * \brief Хеш-таблица
     */
    HashTable* _hashTable;

public:
    /*!
     * \brief Конструктор словаря
     */
    Dictionary();

    /*!
     * \brief Деструктор словаря
     */
    ~Dictionary();
    /*!
    * \brief Добавление в словарь ключ-значения
    * \param key Ключ
    * \param value Значение
    */
    void Add(const string& key, const string& value);

    /*!
    * \brief Удаление из словаря ключ-значения
    * \param key Ключ
    * \return Статус удаления
    */
    void Delete(const string& key);

    /*!
    * \brief Поиск значения по ключу
    * \param key Ключ
    * \return Значение
    */
    string Search(const string& key);

    /*!
     * \brief Взять хэш-таблицу
     * \return Указатель на хэш-таблицу
     */
    const HashTable* GetHashTable();
};

#endif // DICTIONARY_H