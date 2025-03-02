#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include "Product.h"

class ShoppingItem {
private:
    int quantity;
public:
    Product product;
    ShoppingItem(Product p, int qty);
    Product getProduct() const;
    int getQuantity() const;
    double getTotal() const;
};

#endif //SHOPPINGITEM_H
