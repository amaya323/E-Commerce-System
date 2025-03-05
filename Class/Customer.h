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
    //Default constructor for customer
    Customer(int customerId, string customerName);

    // Function to add address
    void addAddress(string address, string contact);

    // Getter fot customer name
    string getName() const;

    // Getter for addresses
    vector <Address> getAddresses() const;

    // Function to print all addresses
    void printAddresses();
};
#endif //CUSTOMER_H
