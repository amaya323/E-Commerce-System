#ifndef ORDER_H
#define ORDER_H

#include "ShoppingCart.h"
#include "Customer.h"
class Order: public ShoppingCart{
private:
    int orderId;
    int addressId;
    vector<ShoppingItem> orderItems;
    Customer customer;

public:
    // Default constructor for orders
    Order(int orderId, vector<ShoppingItem> orderItems, const Customer& customer, int addressId);

    // Getter for the ID of the chosen address of the customer
    int getAddressId() const;

    // Function to get total price of the shopping cart
    double getTotalPrice() const ;

    // Function to display cart
    void viewShoppingItems() const ;
};

#endif //ORDER_H
