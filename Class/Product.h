#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Product class representing an item available for purchase
class Product {
private:
    int productId;
    string productName;
    double price;

public:

    // Default constructor for products (ID, Name, Price)
    Product (int id, string name, double p);

    // Getter for product ID
    int getProductId() const;

    // Getter for product name
    string getProductName() const;

    // Getter for product price
    double getPrice() const;

};
#endif //PRODUCT_H
