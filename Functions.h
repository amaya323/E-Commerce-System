#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Imports.hpp"

using namespace std;

// Function to print a formatted title
void printTitle(const string &title) {
    system("cls"); // Clear the console screen (Windows-specific)
    int length = title.length();
    int padding = max(10, 30 - length); // Ensure a minimum padding of 10, max 30 - title length
    string border(padding, '=');

    // Print a formatted title with borders
    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

// Function to display the main menu
void displayMenu() {
    system("cls"); // Clear the console screen
    printTitle("E-Commerce System Menu"); // Print menu title

    // Display menu options
    cout << "1. View Products" << endl;
    cout << "2. View Shopping Cart" << endl;
    cout << "3. View Orders" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to validate user input as an integer choice
bool validNumber(const string& input, int &output) {
    // Check if the input contains a decimal point (not an integer)
    if (input.find('.') != string::npos) {
        output = -1;
        return false;
    }

    // Ensure all characters are digits
    for (char c : input) {
        if (!isdigit(c)) {
            output = -1;
            return false;
        }
    }

    try {
        // Convert input string to integer
        output = stoi(input);

        // Ensure input is a positive integer
        if (output <= 0) {
            output = -1;
            return false;
        }
        return true;
    }
    // Catch exceptions for invalid input (non-numeric or out-of-range values)
    catch (invalid_argument &e) {
        output = -1;
        return false;
    }
    catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Generic function to validate numerical input within a range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (validNumber(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        } else {
            cout << "Error: Invalid input. Please enter a number between " << minVal << " and " << maxVal << ".\n";
        }
    } while (!isValid);
}

// Function to handle returning to the menu
void backMenu(string& placeholder, int& backToMenu) {
    cout << endl << "[1] Back to Menu." << endl;
    // Exit loop if user enters 1
    do {
        getline(cin, placeholder);
        validNumber(placeholder, backToMenu);
    } while (backToMenu != 1);
}

// Function to handle Yes or No input validation
void yesOrNo(string question, string& placeholder, char& yOrN) {
    cout << endl << question;
    // Ensure input is only 'Y' or 'N' (case-insensitive)
    do {
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

// Function to get the shipping address from the customer
void getShippingAddress(Customer& customer, string& placeholder) {
    char anotherAddress = 0; // Variable to store user response

    do {
        string address;
        string contact;

        // Get recipient address
        cout << "Enter address: ";
        getline(cin, address);

        // Get contact number
        bool isContactValid = false;
        do {
            cout << "Enter number (09XXXXXXXXX): ";
            getline(cin, contact);
            if (contact.size() == 11 && contact[0] == '0' && contact[1] == '9') {
                isContactValid = true;
            } else {
                cout << endl <<"Error: Invalid contact number. " << endl << endl;
            }
        } while (!isContactValid);

        // Add address to the customer's address list
        customer.addAddress(address, contact);

        // Ask if the user wants to add another address
        yesOrNo("Do you want to add another address? (Y/N): ", placeholder, anotherAddress);

    } while (anotherAddress == 'Y' || anotherAddress == 'y'); // Continue if 'Y' or 'y' is entered
}

// Function to collect customer information
void getCustomer(Customer& customer, string& placeholder) {
    char addShipping = 0; // Variable to store user response
    string name;

    // Get customer name
    cout << "Enter name: ";
    getline(cin, name);

    // Set customer details (assuming ID is set to 1 for now)
    customer.setCustomerId(1);
    customer.setCustomerName(name);

    // Ask if the customer wants to add a shipping address
    yesOrNo("Do you want to add a shipping address? (Y/N): ", placeholder, addShipping);

    // If user chooses to add a shipping address, call the function to collect addresses
    if (tolower(addShipping) == 'y') {
        getShippingAddress(customer, placeholder);
    }
}

#endif //FUNCTIONS_H
