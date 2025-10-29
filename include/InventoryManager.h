#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <string>
#include <vector>
#include "HashTable.h"
#include "Product.h"

using namespace std;

class InventoryManager
{
private:
    HashTable<string, Product> productById;
    HashTable<string, vector<string>> productsByCategory;

    vector<string> parseCategories(const string &categoryStr);
    vector<string> parseCSVLine(const string &line);
    string trim(const string &str);

public:
    InventoryManager();
    bool loadFromCSV(const string &filename);
    bool findProduct(const string &inventoryId) const;
    bool listInventory(const string &category) const;
};

#endif