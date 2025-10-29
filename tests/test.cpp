#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "HashTable.h"

using namespace std;

void testHashTableInsertAndFind()
{
    cout << "\nTest: Insert and find." << endl;

    HashTable<string, int> hashTable1;
    hashTable1.insert("one", 1);
    hashTable1.insert("two", 2);
    hashTable1.insert("three", 3);

    int i1;
    assert(hashTable1.find("one", i1) && i1 == 1);
    assert(hashTable1.find("two", i1) && i1 == 2);
    assert(hashTable1.find("three", i1) && i1 == 3);

    cout << "PASS" << endl;
}

void testHashTableUpdate()
{
    cout << "\nTest: Update." << endl;

    HashTable<string, int> hashTable2;
    hashTable2.insert("key1", 100);
    hashTable2.insert("key1", 200);

    int i2;
    assert(hashTable2.find("key1", i2) && i2 == 200);
    cout << "PASS" << endl;

    int i3 = hashTable2.getSize();
    hashTable2.insert("key1", 300);
    assert(hashTable2.getSize() == i3);
    cout << "PASS" << endl;
}

void testHashTableCollisions()
{
    cout << "\nTest: Collisions." << endl;

    HashTable<int, string> hashTable3(10);

    for (int i4 = 0; i4 < 30; i4++)
    {
        hashTable3.insert(i4, "value" + to_string(i4));
    }

    assert(hashTable3.getSize() == 30);
    cout << "PASS" << endl;

    string s1;
    assert(hashTable3.find(0, s1) && s1 == "value0");
    assert(hashTable3.find(15, s1) && s1 == "value15");
    assert(hashTable3.find(29, s1) && s1 == "value29");
    cout << "PASS" << endl;
}

void testHashTableWithVectors()
{
    cout << "\nTest: HashTable with Vector Values." << endl;

    HashTable<string, vector<string>> hashTable4;

    vector<string> vector1 = {"P001", "P002", "P003"};
    hashTable4.insert("Electronics", vector1);

    vector<string> vector2 = {"P004", "P005"};
    hashTable4.insert("Books", vector2);

    vector<string> v1;
    assert(hashTable4.find("Electronics", v1));
    assert(v1.size() == 3);
    assert(v1[0] == "P001");
    cout << "PASS" << endl;

    vector<string> vector3;
    hashTable4.insert("EmptyCategory", vector3);
    assert(hashTable4.find("EmptyCategory", v1));
    assert(v1.empty());
    cout << "PASS" << endl;
}

int main()
{
    cout << "Running tests..." << endl
         << endl;

    testHashTableInsertAndFind();
    testHashTableUpdate();
    testHashTableCollisions();
    testHashTableWithVectors();

    cout << "\nAll PASSED" << endl;
    return 0;
}
