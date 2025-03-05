#include "Customer.h"

void Customer::setCustomerId(int id) {
    customerId = id;
}

void Customer::setCustomerName(string name) {
    customerName = name;
}

void Customer::addAddress(string address, string contact) {
    addresses.emplace_back(address, contact);
}

string Customer::getName() const {
    return customerName;
}

vector<Address> Customer::getAddresses() const {
    return addresses;
}

void Customer::printAddresses() {
    cout << left << setw(5) << " "
            << setw(12) << "Address"
            << endl;
    cout << string(52, '-') << endl; // Print a separator line

    int counter = 0;
    for (const auto &address: addresses) {
        counter++;
        cout << left << setw(5) << counter
                << setw(12) << address.getAddress()
                << endl;
    }
    cout << string(52, '-') << endl;
    cout << endl << "[" << addresses.size() + 1 << "] Cancel (Back to Menu)" << endl;
}
