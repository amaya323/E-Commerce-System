#include "Product.h"

Product::Product (int id, string name, double p): productId(id), productName(name), price(p){}

int Product::getProductId() const{
    return productId;
}

string Product::getProductName() const{
    return productName;
}

double Product::getPrice() const{
    return price;
}