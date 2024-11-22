#ifndef HASHTABLEITEM_H
#define HASHTABLEITEM_H

#include <string>
using namespace std;

/*!
 * \brief ��������� �������� ���-�������
 */
struct HashTableItem
{
    /*!
     * \brief ����
     */
    string Key;

    /*!
     * \brief ��������
     */
    string Value;

    /*!
     * \brief ��������� �� ��������� �������
     */
    HashTableItem* Next;

    /*!
    * \brief ����������� �������� ���-�������
    * \param key ����
    * \param value ��������
    * \param prev ���������� �������
    * \param next ��������� �������
    */
    HashTableItem(const string& key, const string& value, HashTableItem* next = nullptr);
};

#endif // !HASHTABLEITEM_H