#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(Product p, int qty): product(p) {
    quantity = qty;
}

Product ShoppingItem::getProduct() const {
    return product;
}

int ShoppingItem::getQuantity() const {
    return quantity;
}