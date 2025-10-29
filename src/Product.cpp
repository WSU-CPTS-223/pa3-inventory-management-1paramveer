#include "Product.h"

using namespace std;

Product::Product() {}

Product::Product(const string &uniqId,
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
                 const vector<string> &categories)
    : uniqId(uniqId), productName(productName), brandName(brandName),
      asin(asin), category(category), upcEanCode(upcEanCode),
      listPrice(listPrice), sellingPrice(sellingPrice), quantity(quantity),
      modelNumber(modelNumber), aboutProduct(aboutProduct),
      productSpecification(productSpecification), technicalDetails(technicalDetails),
      shippingWeight(shippingWeight), productDimensions(productDimensions),
      image(image), variants(variants), sku(sku), productUrl(productUrl),
      stock(stock), productDetails(productDetails), dimensions(dimensions),
      color(color), ingredients(ingredients), directionToUse(directionToUse),
      isAmazonSeller(isAmazonSeller), sizeQuantityVariant(sizeQuantityVariant),
      productDescription(productDescription), categories(categories) {}

void Product::printDetails() const
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "Uniq Id: " << uniqId << endl;
    cout << "Product Name: " << productName << endl;

    if (!brandName.empty())
        cout << "Brand Name: " << brandName << endl;

    if (!asin.empty())
        cout << "Asin: " << asin << endl;

    cout << "Category: ";
    if (!categories.empty())
    {
        for (int i = 0; i < categories.size(); i++)
        {
            cout << categories[i];
            if (i < categories.size() - 1)
                cout << " | ";
        }
    }
    else
    {
        cout << "NA";
    }
    cout << endl;

    if (!upcEanCode.empty())
        cout << "Upc Ean Code: " << upcEanCode << endl;

    if (!listPrice.empty())
        cout << "List Price: " << listPrice << endl;

    if (!sellingPrice.empty())
        cout << "Selling Price: " << sellingPrice << endl;

    if (!quantity.empty())
        cout << "Quantity: " << quantity << endl;

    if (!modelNumber.empty())
        cout << "Model Number: " << modelNumber << endl;

    if (!aboutProduct.empty())
        cout << "About Product: " << aboutProduct << endl;

    if (!productSpecification.empty())
        cout << "Product Specification: " << productSpecification << endl;

    if (!technicalDetails.empty())
        cout << "Technical Details: " << technicalDetails << endl;

    if (!shippingWeight.empty())
        cout << "Shipping Weight: " << shippingWeight << endl;

    if (!productDimensions.empty())
        cout << "Product Dimensions: " << productDimensions << endl;

    if (!image.empty())
        cout << "Image: " << image << endl;

    if (!variants.empty())
        cout << "Variants: " << variants << endl;

    if (!sku.empty())
        cout << "Sku: " << sku << endl;

    if (!productUrl.empty())
        cout << "Product Url: " << productUrl << endl;

    if (!stock.empty())
        cout << "Stock: " << stock << endl;

    if (!productDetails.empty())
        cout << "Product Details: " << productDetails << endl;

    if (!dimensions.empty())
        cout << "Dimensions: " << dimensions << endl;

    if (!color.empty())
        cout << "Color: " << color << endl;

    if (!ingredients.empty())
        cout << "Ingredients: " << ingredients << endl;

    if (!directionToUse.empty())
        cout << "Direction To Use: " << directionToUse << endl;

    if (!isAmazonSeller.empty())
        cout << "Is Amazon Seller: " << isAmazonSeller << endl;

    if (!sizeQuantityVariant.empty())
        cout << "Size Quantity Variant: " << sizeQuantityVariant << endl;

    if (!productDescription.empty())
        cout << "Product Description: " << productDescription << endl;

    cout << "----------------------------------------------------------------" << endl;
}