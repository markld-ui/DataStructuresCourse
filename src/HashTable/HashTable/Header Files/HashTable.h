#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashTableItem.h"
#include <random>
#include <ctime>

using namespace std;

/*!
 * \brief ����� ���-�������
 */
class HashTable
{
private:
    static const int _MinCapacity = 4;
    /*!
     * \brief ��������
     */
    int _capacity;

    /*!
     * \brief ����������, 
        �������������� ���������� ���������, ������� � ������ ������ ��������� � ���-�������.
     */
    int _length;

    /*!
     * \brief ������ ����� �����, �������������� ������� �������, 
        ������� ������������ ��� ���������� ���-�����.
     */
    int* _pearsonTable;

    /*!
     * \brief ������ �������
     */
    HashTableItem** _data;

    /*!
    * \brief �������� ����� ������� �������
    */
    int* MakePearsonTable();

    /*!
    * \brief ����� ���-���
    * \param key ����
    * \return ���-���
    */
    int GetHashCode(const string& key);

    /*!
    * \brief ���������������
    * \param capacity ����� �������� ���-�������
    */
    void Rehashig(const int& capacity);

    /*!
    * \brief ���������� ��������
    * \param item ����������� �������
    * \param key ����
    * \param value ��������
    */
    HashTableItem* ResolveCollision(HashTableItem* item, const string& key, const string& value);

    /*!
    * \brief �������� ������� � ������ � ���������� �������
    * \param item ������� ������
    * \param key ����
    * \param value ���������� ������� ������
    */
    HashTableItem* AddRightOrder(HashTableItem* item, const string& key, const string& value);

    /*!
     * \brief ������� �������
     * \param item ������� ������
     * \param key ���� ���������� ��������
     * \return ���������� ������� ������
     */
    HashTableItem* Delete(HashTableItem* item, const string& key);

public:

    /*!
    * \brief �����������
    * \param capacity �������� ���-�������
    */
    HashTable(const int& capacity = 4);

    /*!
    * \brief ����������
    */
    ~HashTable();

    /*!
    * \brief ���������� ����-�������� � �������
    * \param key ����
    * \param value ��������
    */
    void Add(const string& key, const string& value);

    /*!
    * \brief �������� ����-�������� �� �������
    * \param key ����
    * \return ������ ��������
    */
    void Delete(const string& key);

    /*!
    * \brief ����� �������� �� �����
    * \param key ����
    * \return ������ ������� ���-�������
    */
    HashTableItem* Search(const string& key, int hashCode = -1);

    /*!
    * \brief ������ ������ ���-������� �� ������
    * \return ������ ���-�������
    */
    HashTableItem** GetData() const;

    /*!
    * \brief ������ �������� ���-�������
    * \return ��������
    */
    int GetCapacity() const;

    /*!
    * \brief ������ �������� ������������ ���-�������
    * \return ����� ���-�������
    */
    int GetLenght() const;

    /*!
     * \brief ������ ������� �������
     * \return ��������� �� ������� �������
     */
    const int* GetPearsonTable() const;

    /*!
    * \brief ��������� ����� ���������� ���-����
    * \param key ����
    * \return ���-���
    */
    int PublicGetHashCode(const string& key);
};

#endif // HASHTABLE_H