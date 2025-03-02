#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ShoppingItem.h"

class ShoppingCart {
private:
    vector<ShoppingItem> shoppingItems;

public:
    void addItem(const Product& product, int qty);
    double getTotalPrice() const;
    void viewCart() const;
    vector<ShoppingItem> getItems();
    void clearCart();
};

#endif //SHOPPINGCART_H
