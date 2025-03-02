#ifndef ORDER_H
#define ORDER_H

#include "ShoppingItem.h"
#include "Address.h"
class Order {
private:
    int orderId;
    vector<ShoppingItem> orderItems;
    Address address;

public:
    // Default constructor for orders
    Order(int id, vector<ShoppingItem> items, Address add);

    // Get for order ID
    int getOrderId() const;

    // Function to calculate and get total amount of the order
    double getTotalAmount() const;

    // Function to display order
    void viewOrder() const;
};

#endif //ORDER_H
