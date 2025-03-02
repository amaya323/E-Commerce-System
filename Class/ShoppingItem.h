#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include "Product.h"

class ShoppingItem {
private:
    int quantity;
    Product product;
public:

    // Default constructor for shopping item (item = product and quantity)
    ShoppingItem(Product p, int qty);

    // Getter for product
    Product getProduct() const;

    // Getter for quantity of the product to order or add to cart
    int getQuantity() const;

};

#endif //SHOPPINGITEM_H
