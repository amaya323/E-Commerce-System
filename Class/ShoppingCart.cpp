#include "ShoppingCart.h"

void ShoppingCart::addItem(const Product &product, int qty) {
    shoppingItems.emplace_back(product, qty);
    cout << "Product added successfully!" << endl;
}

double ShoppingCart::getTotalPrice() const {
    double total = 0;
    for (const auto &item: shoppingItems) {
        total += item.getProduct().getPrice() * item.getQuantity();
    }
    return total;
}

void ShoppingCart::viewCart() const {
    cout << left << setw(12) << "Product ID"
            << setw(20) << "Name"
            << setw(10) << "Price"
            << setw(10) << "Quantity"
            << endl;

    cout << string(52, '-') << endl; // Print a separator line

    for (const auto &item: shoppingItems) {
        cout << left << setw(12) << item.getProduct().getProductId()
                << setw(20) << item.getProduct().getProductName()
                << setw(10) << fixed << setprecision(2) << item.getProduct().getPrice()
                << setw(10) << item.getQuantity()
                << endl;
    }
    cout << string(52, '-') << endl;
    cout << "Total: " << getTotalPrice() << endl;
}

vector<ShoppingItem> ShoppingCart::getItems() {
    return shoppingItems;
}

void ShoppingCart::clearCart() {
    shoppingItems.clear();
}
