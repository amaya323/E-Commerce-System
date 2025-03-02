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
    Order(int id, vector<ShoppingItem> items, Address add);
    int getOrderId() const;
    double getTotalAmount() const;
    void viewOrder() const;
};

#endif //ORDER_H
