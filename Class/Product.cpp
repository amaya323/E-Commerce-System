#include "Product.h"

Product::Product (int productId, string productName, double price){
    this->productId = productId;
    this->productName = productName;
    this->price = price;
}

int Product::getProductId() const{
    return productId;
}

string Product::getProductName() const{
    return productName;
}

double Product::getPrice() const{
    return price;
}
