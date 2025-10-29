#include "InventoryManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

InventoryManager::InventoryManager()
    : productById(2000), productsByCategory(1000) {}

string InventoryManager::trim(const string &str)
{
    int start = str.find_first_not_of(" \t\r\n");
    int end = str.find_last_not_of(" \t\r\n");

    if (start == string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

vector<string> InventoryManager::parseCategories(const string &categoryStr)
{
    vector<string> categories;

    if (categoryStr.empty() || trim(categoryStr).empty())
    {
        categories.push_back("NA");
        return categories;
    }

    stringstream ss(categoryStr);
    string category;

    while (getline(ss, category, '|'))
    {
        category = trim(category);
        if (!category.empty())
        {
            categories.push_back(category);
        }
    }

    if (categories.empty())
    {
        categories.push_back("NA");
    }

    return categories;
}

vector<string> InventoryManager::parseCSVLine(const string &line)
{
    vector<string> fields;
    string field;
    bool inQuotes = false;

    for (int i = 0; i < line.length(); i++)
    {
        char c = line[i];

        if (c == '"')
        {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes)
        {
            fields.push_back(field);
            field.clear();
        }
        else
        {
            field += c;
        }
    }
    fields.push_back(field);

    return fields;
}

bool InventoryManager::loadFromCSV(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error - Could not open file" << endl;
        return false;
    }

    string line;
    getline(file, line); // skip header line

    int count = 0;
    while (getline(file, line))
    {
        if (line.empty())
            continue;

        vector<string> fields = parseCSVLine(line);

        if (fields.size() < 5)
            continue;

        string uniqId = (fields.size() > 0) ? trim(fields[0]) : "";
        string productName = (fields.size() > 1) ? trim(fields[1]) : "";
        string brandName = (fields.size() > 2) ? trim(fields[2]) : "";
        string asin = (fields.size() > 3) ? trim(fields[3]) : "";
        string category = (fields.size() > 4) ? fields[4] : "";
        string upcEanCode = (fields.size() > 5) ? trim(fields[5]) : "";
        string listPrice = (fields.size() > 6) ? trim(fields[6]) : "";
        string sellingPrice = (fields.size() > 7) ? trim(fields[7]) : "";
        string quantity = (fields.size() > 8) ? trim(fields[8]) : "";
        string modelNumber = (fields.size() > 9) ? trim(fields[9]) : "";
        string aboutProduct = (fields.size() > 10) ? trim(fields[10]) : "";
        string productSpecification = (fields.size() > 11) ? trim(fields[11]) : "";
        string technicalDetails = (fields.size() > 12) ? trim(fields[12]) : "";
        string shippingWeight = (fields.size() > 13) ? trim(fields[13]) : "";
        string productDimensions = (fields.size() > 14) ? trim(fields[14]) : "";
        string image = (fields.size() > 15) ? trim(fields[15]) : "";
        string variants = (fields.size() > 16) ? trim(fields[16]) : "";
        string sku = (fields.size() > 17) ? trim(fields[17]) : "";
        string productUrl = (fields.size() > 18) ? trim(fields[18]) : "";
        string stock = (fields.size() > 19) ? trim(fields[19]) : "";
        string productDetails = (fields.size() > 20) ? trim(fields[20]) : "";
        string dimensions = (fields.size() > 21) ? trim(fields[21]) : "";
        string color = (fields.size() > 22) ? trim(fields[22]) : "";
        string ingredients = (fields.size() > 23) ? trim(fields[23]) : "";
        string directionToUse = (fields.size() > 24) ? trim(fields[24]) : "";
        string isAmazonSeller = (fields.size() > 25) ? trim(fields[25]) : "";
        string sizeQuantityVariant = (fields.size() > 26) ? trim(fields[26]) : "";
        string productDescription = (fields.size() > 27) ? trim(fields[27]) : "";

        if (uniqId.empty() || productName.empty())
            continue;

        vector<string> categories = parseCategories(category);

        Product product(uniqId, productName, brandName, asin, category,
                        upcEanCode, listPrice, sellingPrice, quantity, modelNumber,
                        aboutProduct, productSpecification, technicalDetails,
                        shippingWeight, productDimensions, image, variants, sku,
                        productUrl, stock, productDetails, dimensions, color,
                        ingredients, directionToUse, isAmazonSeller,
                        sizeQuantityVariant, productDescription, categories);

        productById.insert(uniqId, product);

        for (const string &cat : categories)
        {
            vector<string> productList;

            if (productsByCategory.find(cat, productList))
            {
                productList.push_back(uniqId);
                productsByCategory.insert(cat, productList);
            }
            else
            {
                vector<string> newList;
                newList.push_back(uniqId);
                productsByCategory.insert(cat, newList);
            }
        }

        count++;
    }

    file.close();
    cout << "Successfully loaded " << count << " products." << endl;
    return true;
}

bool InventoryManager::findProduct(const string &inventoryId) const
{
    Product product;
    if (productById.find(inventoryId, product))
    {
        product.printDetails();
        return true;
    }
    else
    {
        cout << "Inventory/Product not found" << endl;
        return false;
    }
}

bool InventoryManager::listInventory(const string &category) const
{
    vector<string> productList;
    if (productsByCategory.find(category, productList))
    {
        cout << "\nProducts in category '" << category << "':" << endl;
        cout << "------------------------------------------------------" << endl;

        for (const string &id : productList)
        {
            Product product;
            if (productById.find(id, product))
            {
                cout << "Uniq Id: " << product.getUniqId() << endl;
                cout << "Product Name: " << product.getProductName() << endl;
                cout << endl;
            }
        }

        cout << "Total: " << productList.size() << " products" << endl;
        return true;
    }
    else
    {
        cout << "Invalid Category" << endl;
        return false;
    }
}