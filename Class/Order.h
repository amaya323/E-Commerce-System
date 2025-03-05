#ifndef ORDER_H
#define ORDER_H

#include "ShoppingItem.h"
#include "Customer.h"
class Order {
private:
    int orderId;
    int addressId;
    vector<ShoppingItem> orderItems;
    Customer customer;

public:
    // Default constructor for orders
    Order(int orderId, vector<ShoppingItem> orderItems, Customer customer);

    // Get for order ID
    int getOrderId() const;

    // Setter for chosen address of customer
    void setAddressId(int addressId);

    // Getter for the ID of the chosen address of the customer
    int getAddressId() const;

    // Function to calculate and get total amount of the order
    double getTotalAmount() const;

    // Function to display order
    void viewOrder() const;
};

#endif //ORDER_H
