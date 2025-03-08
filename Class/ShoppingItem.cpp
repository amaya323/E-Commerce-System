#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(Product product, int quantity): product(product) {
    this->quantity = quantity;
}

Product ShoppingItem::getProduct() const {
    return product;
}

int ShoppingItem::getQuantity() const {
    return quantity;
}

void ShoppingItem::addQuantity(int quantity) {
    cout << "Adding quantity " <<endl;
    this->quantity = getQuantity() + quantity;
}