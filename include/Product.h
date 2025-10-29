#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Product
{
private:
    string uniqId;
    string productName;
    string brandName;
    string asin;
    string category;
    string upcEanCode;
    string listPrice;
    string sellingPrice;
    string quantity;
    string modelNumber;
    string aboutProduct;
    string productSpecification;
    string technicalDetails;
    string shippingWeight;
    string productDimensions;
    string image;
    string variants;
    string sku;
    string productUrl;
    string stock;
    string productDetails;
    string dimensions;
    string color;
    string ingredients;
    string directionToUse;
    string isAmazonSeller;
    string sizeQuantityVariant;
    string productDescription;
    vector<string> categories;

public:
    Product();

    Product(const string &uniqId,
            const string &productName,
            const string &brandName,
            const string &asin,
            const string &category,
            const string &upcEanCode,
            const string &listPrice,
            const string &sellingPrice,
            const string &quantity,
            const string &modelNumber,
            const string &aboutProduct,
            const string &productSpecification,
            const string &technicalDetails,
            const string &shippingWeight,
            const string &productDimensions,
            const string &image,
            const string &variants,
            const string &sku,
            const string &productUrl,
            const string &stock,
            const string &productDetails,
            const string &dimensions,
            const string &color,
            const string &ingredients,
            const string &directionToUse,
            const string &isAmazonSeller,
            const string &sizeQuantityVariant,
            const string &productDescription,
            const vector<string> &categories);

    // getters
    string getUniqId() const { return uniqId; }
    string getProductName() const { return productName; }

    // returns a vector of different categories
    // needed for listInventory function to make comparisons to each and every category for a product
    const vector<string> &getCategories() const { return categories; }

    // debug print function
    void printDetails() const;
};

#endif