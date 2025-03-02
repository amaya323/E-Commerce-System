#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "Address.h"

class Customer {
private:
    int customerId;
    string customerName;
    vector<Address> addresses;

public:
    void setCustomerId(int id);
    void setCustomerName(string name);
    void addAddress(string name, string address);
    vector <Address> getAddresses() const;
    void printAddresses();
};
#endif //CUSTOMER_H
