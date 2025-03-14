
#include "Order.h"

#include <utility>

Order::Order(int orderId, vector<ShoppingItem> orderItems, const Customer& customer, int addressId): customer(customer){
    this->orderId = orderId;
    this->orderItems = orderItems;
    this->addressId = addressId;
}

int Order::getAddressId() const {
    return addressId;
}

double Order::getTotalPrice() const {
    double total = 0;
    for (const auto &item : orderItems) {  // Use orderItems, NOT shoppingItems
        total += item.getProduct().getPrice() * item.getQuantity();
    }
    return total;
}

void Order::viewShoppingItems() const {



    cout << "Order ID: " << orderId << endl << endl;
    cout << "Shipping Details:" << endl;
    cout << "Received by: " <<customer.getName() << endl;
    cout << "Contact Number: " << customer.getAddresses()[getAddressId()].getContactNumber() << endl;
    cout << "Address: " << customer.getAddresses()[getAddressId()].getAddress() << endl << endl;

    cout << left << setw(12) << "Product ID"
         << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity"
         << endl;

    cout << string(52, '-') << endl; // Print a separator line

    for (const auto &item : orderItems) {  // Use orderItems instead of shoppingItems
        cout << left << setw(12) << item.getProduct().getProductId()
             << setw(20) << item.getProduct().getProductName()
             << setw(10) << fixed << setprecision(2) << item.getProduct().getPrice()
             << setw(10) << item.getQuantity()
             << endl;
    }
    cout << string(52, '-') << endl;
    cout << "Total: " << fixed << setprecision(2) << getTotalPrice() << endl;
    cout << string(52, '-') << endl; // Print a separator line
}


