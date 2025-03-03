#include "Address.h"

Address::Address(string name, string address, string contactNumber) {
    this->name = name;
    this->address = address;
    this->contactNumber = contactNumber;
}

string Address::getName() const{
    return name;
}

string Address::getAddress() const{
    return address;
}

string Address::getContactNumber() const {
    return contactNumber;
}


