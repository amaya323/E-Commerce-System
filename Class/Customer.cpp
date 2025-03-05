#include "Customer.h"

Customer::Customer(int customerId, string customerName){
    this->customerId = customerId;
    this->customerName = customerName;
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
            << setw(20) << "Address"
            << setw(12) << "Contact"
            << endl;
    cout << string(52, '-') << endl; // Print a separator line

    int counter = 0;
    for (const auto &address: addresses) {
        counter++;
        cout << left << setw(5) << counter
                << setw(20) << address.getAddress()
                << setw(12) << address.getContactNumber()
                << endl;
    }
    cout << string(52, '-') << endl;
    cout << endl << "[" << addresses.size() + 1 << "] Add Address" << endl;
    cout << "[" << addresses.size() + 2 << "] Cancel (Back to Menu)" << endl;
}
