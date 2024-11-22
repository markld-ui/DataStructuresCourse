#ifndef MENU_H
#define MENU_H

#include "Dictionary.h"
#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

/*!
 * \brief ���� � ���������� ��������
 */
void MenuController();

/*!
 * \brief ���� � ���������
 * \param variable ���������� ������ ���� ������
 */
template <typename Type>
Type ValidInput();

/*!
 * \brief ��������� ����� ����� ������
 * \param letter ������ ����� ���� ������
 * \return ������ �������� ���� ������
 */
string GetTypeName(const char* letter);

/*!
 * \brief �������� ���� ���������
 */
void ClearTerminal();

/*!
 * \brief ����� �������
 * \param dictionary �������
 */
void ShowDictionary(Dictionary* dictionary);

/*!
 * \brief ����� ���-�������
 * \param dictionary �������
 */
void ShowHashTable(Dictionary* dictionary);

/*!
 * \brief ����� ���-�������
 * \param hashTable ���-�������
 */
void ShowHashTable(HashTable* hashTable);

/*!
 * \brief ������ �� ��������
 */
void MenuDictionaryCase();

/*!
 * \brief ������ � ���-��������
 */
void MenuHashTableCase();

#endif // MENU_H