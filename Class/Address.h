#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Address {
private:
    string name;
    string address;

public:
    // Constructor to initialize address details
    Address(string n, string a);
    string getName() const;
    string getAddress() const;
};

#endif //ADDRESS_H
