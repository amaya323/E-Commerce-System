#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
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
    printTitle("E-Commerce System Menu"); // Print menu title

    // Display menu options
    cout << "1. View Products" << endl;
    cout << "2. View Shopping Cart" << endl;
    cout << "3. View Orders" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to validate user input as an integer choice
bool validNumber(const string &input, int &output) {
    // Check if the input contains a decimal point (not an integer)
    if (input.find('.') != string::npos) {
        output = -1;
        return false;
    }

    // Ensure all characters are digits
    for (char c: input) {
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

// Function to handle returning to the menu, once use inputs '1' return to menu else, stay
void backMenu(string &placeholder, int &backToMenu) {
    cout << endl << "[1] Back to Menu." << endl;
    // Exit loop if user enters 1
    do {
        getline(cin, placeholder);
        validNumber(placeholder, backToMenu);
    } while (backToMenu != 1);
}

// Function to handle Yes or No input validation
void askYesOrNo(string question, string &placeholder, char &yOrN) {
    cout << endl << question;
    // Ensure input is only 'Y' or 'N' (case-insensitive)
    do {
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

// Function to get the shipping address from the customer
void getShippingAddress(Customer &customer) {
    string address;
    string contact;

    // Get recipient address
    cout << "Enter address: ";
    getline(cin, address);

    // Get contact number

    bool isContactValid;
    do {
        isContactValid = true;
        cout << "Enter number (09XXXXXXXXX): ";
        getline(cin, contact);

        // Ensure all characters are digits
        for (char c: contact) {
            if (!isdigit(c)) {
                isContactValid = false;
                break;
            }
        }

        // Validate format: exactly 11 digits & starts with "09"
        if (isContactValid && contact.size() != 11 || contact[0] != '0' || contact[1] != '9') {
            isContactValid = false;
        }

        if (!isContactValid) {
            cout << endl << "Error: Invalid contact number." << endl;
        }

    } while (!isContactValid);  // Loop continues only if contact is invalid

    // Add address to the customer's address list
    customer.addAddress(address, contact);
}


void displayProduct(const vector<Product>& products) {
// Display product details
    cout << left << setw(12) << "Product ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    cout << string(52, '-') << endl;

    for (const auto &product: products) {
        cout << left << setw(12) << product.getProductId()
             << setw(20) << product.getProductName()
             << setw(10) << fixed << setprecision(2) << product.getPrice()
             << endl;
    }

    cout << endl << "[" << products.size() + 1 << "] Back to Menu" << endl;
}

#endif //FUNCTIONS_H
