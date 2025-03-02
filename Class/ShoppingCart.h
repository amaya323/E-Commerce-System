#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ShoppingItem.h"

class ShoppingCart {
private:
    vector<ShoppingItem> shoppingItems;

public:

    // Function to add an item to shopping cart
    void addItem(const Product& product, int qty);

    // Function to get total price of the shopping cart
    double getTotalPrice() const;

    // Function to display cart
    void viewCart() const;

    // Getter for the cart items
    vector<ShoppingItem> getItems();

    // Function to clear the cart (if cart is checked out successfully)
    void clearCart();
};

#endif //SHOPPINGCART_H
