#include "Imports.hpp"

using namespace std;

//Function to print a title with formatting
void printTitle(const string &title) {
    system("cls"); // Clear the console screen
    int length = title.length();
    int padding = max(10, 30 - length); // Ensure a minimum length
    string border(padding, '=');

    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

//Function to display the main menu
void displayMenu() {
    system("cls"); // Clear the console screen
    printTitle("E-Commerce System Menu");
    cout << "1. View Products" << endl;
    cout << "2. View Shopping Cart" << endl;
    cout << "3. View Orders" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

//Function to validate user input as an integer choice
bool validChoice(const string& input, int &output) {
    if (input.find('.') != string::npos) { // Check if input contains a decimal point
        output = -1;
        return false;
    }

    for (char c : input) { // Check if all characters are digits
        if (!isdigit(c)) {
            output = -1;
            return false;
        }
    }

    try {
        // Attempt to convert input to integer
        output = stoi(input);
        if (output <= 0) {
            output = -1;
            return false;
        }
        return true;
    }
    // Catch exceptions for invalid input or out of range values
    catch (invalid_argument &e) {
        output = -1;
        return false;
    }
    catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Function to handle returning to the menu
void backMenu(string& placeholder, int& backToMenu) {
    cout << endl << "[1] Back to Menu." << endl;
    while (true) {
        getline(cin, placeholder);
        validChoice(placeholder, backToMenu);
        if (backToMenu == 1) {
            break;
        }
    }
}

void yesOrNo(string question, string& placeholder, char& yOrN) {
    cout << endl << question;
    do {
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

void getShippingAddress(Customer& customer, string& placeholder) {
    char anotherAddress = 0;
    do {
        string name;
        string address;

        cout << "Enter name of order recipient: ";
        getline(cin, name);

        cout << "Enter address of order recipient: ";
        getline(cin, address);

        customer.addAddress(name, address);
        yesOrNo("Do you want to add another address? (Y/N): ", placeholder, anotherAddress);
    }while (anotherAddress == 'Y' || anotherAddress == 'y');

}

void getCustomer(Customer& customer, string& placeholder) {
    char addShipping = 0;
    string name;
    printTitle("Welcome Customer!");
    cout << "Enter name: ";
    getline(cin, name);

    customer.setCustomerId(1);
    customer.setCustomerName(name);

    yesOrNo("Do you want to add a shipping address? (Y/N): ", placeholder, addShipping);
    if (addShipping == 'Y' || addShipping == 'y') {
        getShippingAddress(customer, placeholder);
    }
}



