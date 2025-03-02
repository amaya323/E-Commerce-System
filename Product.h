#ifndef PRODUCT_H
#define PRODUCT_H
class Product {
private:
    int productId;
    string productName;
    double price;

public:
    Product (int id, string name, double p){
        productId = id;
        productName = name;
        price = p;
    }

    int getProductId() const{
        return productId;
    }

    string getProductName() const{
        return productName;
    }

    double getPrice() const{
        return price;
    }
};
#endif //PRODUCT_H
