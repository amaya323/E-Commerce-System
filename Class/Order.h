#ifndef ORDER_H
#define ORDER_H

#include "ShoppingCart.h"
#include "Customer.h"
class Order{
private:
    int orderId;
    vector<ShoppingItem> orderItems;
    Customer customer;
    Address address;

public:
    // Default constructor for orders
    Order(int orderId, vector<ShoppingItem> orderItems, const Customer &customer, Address address);

    // Function to get total price of the shopping cart
    double getTotalPrice() const ;

    // Function to display cart
    void viewShoppingItems() const ;
};

#endif //ORDER_H
