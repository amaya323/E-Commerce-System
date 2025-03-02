
#include "Order.h"

Order::Order(int id, vector<ShoppingItem> items, Address add): address(add) {
    orderId = id;
    orderItems = items;
}

int Order::getOrderId() const {
    return orderId;
}

double Order::getTotalAmount() const {
    double total = 0;
    for (const auto &item: orderItems) {
        total += item.getProduct().getPrice() * item.getQuantity();
    }
    return total;
}

void Order::viewOrder() const {
    cout << "Order ID: " << orderId << endl;
    cout << "Shipping address: " << address.getAddress() << endl;
    cout << "Total Amount: " << fixed << setprecision(2) << getTotalAmount() << endl;
    cout << left << setw(12) << "Product ID"
            << setw(20) << "Name"
            << setw(10) << "Price"
            << setw(10) << "Quantity"
            << endl;

    cout << string(52, '-') << endl;

    for (const auto &item: orderItems) {
        cout << left << setw(12) << item.getProduct().getProductId()
                << setw(20) << item.getProduct().getProductName()
                << setw(10) << fixed << setprecision(2) << item.getProduct().getPrice()
                << setw(10) << item.getQuantity()
                << endl;
    }
    cout << string(52, '-') << endl;
    cout << "Total: " << getTotalAmount() << endl;
}
