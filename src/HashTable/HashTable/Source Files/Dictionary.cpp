#include "Dictionary.h"

Dictionary::Dictionary()
{
    _hashTable = new HashTable;
}

Dictionary::~Dictionary()
{
    delete _hashTable;
}

void Dictionary::Add(const string& key, const string& value)
{
    _hashTable->Add(key, value);
}

void Dictionary::Delete(const string& key)
{
    _hashTable->Delete(key);
}

string Dictionary::Search(const string& key)
{
    HashTableItem* temp = _hashTable->Search(key);
    return temp ? temp->Value : "";
}

const HashTable* Dictionary::GetHashTable()
{
    return _hashTable;
}