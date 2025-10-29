#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <string>

using namespace std;

template <typename K, typename V>
class HashTable
{
private:
    struct Node
    {
        K key;
        V value;
        Node *next;

        Node(const K &k, const V &v) : key(k), value(v), next(nullptr) {}
    };
    Node **table;

    int capacity;
    int size_;

    hash<K> hasher;

    int do_hash(const K &key) const
    {
        return hasher(key) % capacity;
    }

public:
    HashTable(int initialCapacity = 1000)
        : capacity(initialCapacity), size_(0)
    {
        table = new Node *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            Node *cur = table[i];
            while (cur)
            {
                Node *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
        delete[] table;
    }

    void insert(const K &key, const V &value)
    {
        int i = do_hash(key);
        Node *cur = table[i];

        while (cur)
        {
            if (cur->key == key)
            {
                cur->value = value; // update
                return;
            }
            cur = cur->next;
        }

        Node *n = new Node(key, value);
        n->next = table[i];
        table[i] = n;
        size_++;
    }

    bool find(const K &key, V &value) const
    {
        int i = do_hash(key);
        Node *cur = table[i];

        while (cur)
        {
            if (cur->key == key)
            {
                value = cur->value;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    int getSize() const
    {
        return size_;
    }
};

#endif