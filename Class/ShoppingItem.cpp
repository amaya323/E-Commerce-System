#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(Product product, int quantity): product(product) {
    quantity = quantity;
}

Product ShoppingItem::getProduct() const {
    return product;
}

int ShoppingItem::getQuantity() const {
    return quantity;
}