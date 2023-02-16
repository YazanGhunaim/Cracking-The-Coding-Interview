 
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// hashtable to implement 905, jimmy;

class HashTable
{
private:
    // how many lists are we going to use?
    static const int hashGroups = 10;
    // we will have an array that stores lists and each lists stores a pair
    list<pair<int, string>> table[hashGroups]; // List 1 index 0, List 2 index 1.....

    // public functions
public:
    bool isEmpty() const; // const member function AKA promises not to modify the state of the object in which it is called
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchItem(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    for (int i{}; i < hashGroups; ++i)
    {
        if (table[i].size() != 0)
        {
            return false;
        }
    }
    return true;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups; // Key: 905, in return this function will spit out 5
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    // auto automatically deduces the datatype of a variable
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }

    if (!keyExists)
    {
        cell.emplace_front(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
    int hashvalue = hashFunction(key);
    auto &cell = table[hashvalue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); ++bItr)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            // erase returns the next iterator
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed." << endl;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }
    return;
}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; ++i)
    {
        if (table[i].size() == 0)
            continue;
        //--//
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); ++bItr)
        {
            cout << "[INFO] Key:" << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

string HashTable::searchItem(int key)
{
    int hashvalue = hashFunction(key);
    auto bItr = table[hashvalue].begin();
    for (; bItr != table[hashvalue].end(); ++bItr)
    {
        if (bItr->first == key)
        {
            return bItr->second;
        }
    }
    return NULL;
}

int main()
{
    HashTable HT;

    if (HT.isEmpty())
    {
        cout << "Correct answer. Good job." << endl;
    }
    else
    {
        cout << "Check the code." << endl;
    }

    HT.insertItem(905, "Yazan");
    HT.insertItem(112, "Caramel");
    HT.insertItem(201, "Amal");
    HT.insertItem(306, "Laith");
    HT.insertItem(705, "Louai");
    HT.insertItem(343, "Saif");
    HT.insertItem(343, "Blitz");

    HT.printTable();

    HT.removeItem(100);
    HT.removeItem(906);

    cout << HT.searchItem(343) << endl;

    if (HT.isEmpty())
    {
        cout << "Check the code." << endl;
    }
    else
    {
        cout << "Correct answer. Good job." << endl;
    }
    return 0;
}
