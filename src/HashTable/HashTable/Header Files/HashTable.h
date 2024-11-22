#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashTableItem.h"
#include <random>
#include <ctime>

using namespace std;

/*!
 * \brief Класс хеш-таблицы
 */
class HashTable
{
private:
    static const int _MinCapacity = 4;
    /*!
     * \brief Мощность
     */
    int _capacity;

    /*!
     * \brief Переменная, 
        представляющая количество элементов, которые в данный момент находятся в хеш-таблице.
     */
    int _length;

    /*!
     * \brief Массив целых чисел, представляющий таблицу Пирсона, 
        которая используется для вычисления хеш-кодов.
     */
    int* _pearsonTable;

    /*!
     * \brief Данные таблицы
     */
    HashTableItem** _data;

    /*!
    * \brief Создание новой таблицы Пирсона
    */
    int* MakePearsonTable();

    /*!
    * \brief Найти хеш-код
    * \param key Ключ
    * \return Хеш-код
    */
    int GetHashCode(const string& key);

    /*!
    * \brief Перехеширование
    * \param capacity Новая мощность хеш-таблицы
    */
    void Rehashig(const int& capacity);

    /*!
    * \brief Разрешение коллизии
    * \param item Конфликтный элемент
    * \param key Ключ
    * \param value Значение
    */
    HashTableItem* ResolveCollision(HashTableItem* item, const string& key, const string& value);

    /*!
    * \brief Добавить элемент в список в правильном порядке
    * \param item Элемент списка
    * \param key Ключ
    * \param value Измененный элемент списка
    */
    HashTableItem* AddRightOrder(HashTableItem* item, const string& key, const string& value);

    /*!
     * \brief Удалить элемент
     * \param item Элемент списка
     * \param key Ключ удаляемого элемента
     * \return Измененный элемент списка
     */
    HashTableItem* Delete(HashTableItem* item, const string& key);

public:

    /*!
    * \brief Конструктор
    * \param capacity Мощность хеш-таблицы
    */
    HashTable(const int& capacity = 4);

    /*!
    * \brief Деструктор
    */
    ~HashTable();

    /*!
    * \brief Добавление ключ-значения в таблицу
    * \param key Ключ
    * \param value Значение
    */
    void Add(const string& key, const string& value);

    /*!
    * \brief Удаление ключ-значения из таблицы
    * \param key Ключ
    * \return Статус удаления
    */
    void Delete(const string& key);

    /*!
    * \brief Поиск значения по ключу
    * \param key Ключ
    * \return Нужный элемент хеш-таблицы
    */
    HashTableItem* Search(const string& key, int hashCode = -1);

    /*!
    * \brief Взятие данных хеш-таблицы из класса
    * \return Данные хеш-таблицы
    */
    HashTableItem** GetData() const;

    /*!
    * \brief Взятие мощности хеш-таблицы
    * \return Мощность
    */
    int GetCapacity() const;

    /*!
    * \brief Взятие занятого пространства хеш-таблицы
    * \return длина хеш-таблицы
    */
    int GetLenght() const;

    /*!
     * \brief Взятие таблицы Пирсона
     * \return Указатель на таблицу Пирсона
     */
    const int* GetPearsonTable() const;

    /*!
    * \brief Публичный метод нахождения хеш-кода
    * \param key Ключ
    * \return Хеш-код
    */
    int PublicGetHashCode(const string& key);
};

#endif // HASHTABLE_H