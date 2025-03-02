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
    Product (int id, string name, double p);
    int getProductId() const;
    string getProductName() const;
    double getPrice() const;
};
#endif //PRODUCT_H
