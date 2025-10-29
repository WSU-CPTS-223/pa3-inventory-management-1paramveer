#include <iostream>
#include <string>
#include <sstream>
#include "InventoryManager.h"

using namespace std;

InventoryManager *inventoryManager = nullptr;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory", 0) == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    else if (line.rfind("find", 0) == 0)
    {
        stringstream ss(line);
        string cmd, inventoryId;
        ss >> cmd >> inventoryId;

        if (inventoryId.empty())
        {
            cout << "Usage: find <inventoryid>" << endl;
        }
        else
        {
            inventoryManager->findProduct(inventoryId);
        }
    }
    else if (line.rfind("listInventory", 0) == 0)
    {
        stringstream ss(line);
        string cmd, category;
        ss >> cmd;
        getline(ss, category);

        int start = category.find_first_not_of(" \t");
        int end = category.find_last_not_of(" \t");

        if (start != string::npos && end != string::npos)
        {
            category = category.substr(start, end - start + 1);
        }

        if (category.empty())
        {
            cout << "Usage: listInventory <category_string>" << endl;
        }
        else
        {
            inventoryManager->listInventory(category);
        }
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;

    inventoryManager = new InventoryManager();

    cout << "\nLoading inventory data..." << endl;
    inventoryManager->loadFromCSV("files/marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv");

    cout << "\n> ";
}

int main(int argc, char const *argv[])
{
    string line;

    bootStrap();

    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";

        line = ":quit";
    }

    // calls destructor
    delete inventoryManager;
    return 0;
}