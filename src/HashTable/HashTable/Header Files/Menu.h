#ifndef MENU_H
#define MENU_H

#include "Dictionary.h"
#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

/*!
 * \brief Меню и управление словарем
 */
void MenuController();

/*!
 * \brief Ввод с проверкой
 * \param variable Переменная любого типа данных
 */
template <typename Type>
Type ValidInput();

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char* letter);

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal();

/*!
 * \brief Вывод словаря
 * \param dictionary Словарь
 */
void ShowDictionary(Dictionary* dictionary);

/*!
 * \brief Вывод хэш-таблицы
 * \param dictionary Словарь
 */
void ShowHashTable(Dictionary* dictionary);

/*!
 * \brief Вывод хэш-таблицы
 * \param hashTable хеш-таблица
 */
void ShowHashTable(HashTable* hashTable);

/*!
 * \brief Работа со словарем
 */
void MenuDictionaryCase();

/*!
 * \brief Работа с хеш-таблицей
 */
void MenuHashTableCase();

#endif // MENU_H