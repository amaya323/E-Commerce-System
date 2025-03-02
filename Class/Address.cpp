#include "Address.h"

Address::Address(string n, string a) {
    name = n;
    address = a;
}

string Address::getName() const{
    return name;
}
string Address::getAddress() const{
    return address;
}
