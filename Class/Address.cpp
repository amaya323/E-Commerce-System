#include "Address.h"

Address::Address(string address, string contactNumber) {
    this->address = address;
    this->contactNumber = contactNumber;
}

string Address::getAddress() const{
    return address;
}

string Address::getContactNumber() const {
    return contactNumber;
}


