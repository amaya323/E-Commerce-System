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
    // Setter for customer ID
    void setCustomerId(int id);

    // Setter for customer name
    void setCustomerName(string name);

    // Function to add address
    void addAddress(string address, string contact);

    string getName() const;

    // Getter for addresses
    vector <Address> getAddresses() const;

    // Function to print all addresses
    void printAddresses();
};
#endif //CUSTOMER_H
