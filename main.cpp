#include "Imports.hpp"
#include "Functions.h"
using namespace std;

// Main function to run the e-commerce system
int main() {
    // List of available products
    vector<Product> productList = {
        Product(1, "Laptop", 30000.00),
        Product(2, "Phone", 8000.00),
        Product(3, "Headphones", 850.00),
        Product(4, "Game Console", 20150.00),
        Product(5, "Personal Computer", 50000.00)
    };

    ShoppingCart cart; // Shopping cart instance
    vector<Order> orders; // Stores all orders
    int choice; // User menu choice
    string choicePlaceholder; // Input placeholder for validation
    int backToMenu = 0; // Variable to handle return to menu

    Customer customer; // Customer instance
    getCustomer(customer, choicePlaceholder); // Get customer details

    // Main loop for menu navigation
    do {
        displayMenu(); // Display the main menu
        getline(cin, choicePlaceholder);
        validChoice(choicePlaceholder, choice); // Validate user choice

        if (choice == 1) { // Viewing products
            char addMoreToCart;
            do {
                printTitle("Products"); // Display product list header

                // Display product details
                cout << left << setw(12) << "Product ID"
                        << setw(20) << "Name"
                        << setw(10) << "Price"
                        << endl;
                cout << string(52, '-') << endl;

                for (const auto &item: productList) {
                    cout << left << setw(12) << item.getProductId()
                            << setw(20) << item.getProductName()
                            << setw(10) << fixed << setprecision(2) << item.getPrice()
                            << endl;
                }
                cout << endl << "[" << productList.size() + 1 << "] Back to Menu" << endl;

                int productId, quantity;

                // Prompt user to select a product by ID
                while (true) {
                    cout << "Enter product ID to add to cart: ";
                    getline(cin, choicePlaceholder);
                    validChoice(choicePlaceholder, productId);
                    if (productId > 0 && productId <= productList.size() + 1) {
                        break;
                    }
                    cout << endl << "Error: Invalid Product ID" << endl << endl;
                }

                if (productId == productList.size() + 1) { break; } // Return to menu

                // Prompt user to enter quantity
                while (true) {
                    cout << "Enter quantity: ";
                    getline(cin, choicePlaceholder);
                    validChoice(choicePlaceholder, quantity);
                    if (quantity != -1) {
                        cart.addItem(productList[productId - 1], quantity);
                        break;
                    }
                    cout << "Error: Enter a valid quantity." << endl;
                }

                // Ask if the user wants to add another product
                yesOrNo("Do you want to add another product? (Y/N): ", choicePlaceholder, addMoreToCart);
            } while (addMoreToCart == 'Y' || addMoreToCart == 'y');

        } else if (choice == 2) { // Viewing shopping cart
            printTitle("Shopping Cart");

            if (cart.getItems().empty()) { // Check if cart is empty
                cout << "Your shopping cart is empty." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }

            cart.viewCart(); // Display cart contents

            char checkOut;
            yesOrNo("Checkout all products? (Y/N): ", choicePlaceholder, checkOut);

            if (checkOut == 'y') {
                // Display address selection
                printTitle("Addresses");
                int addressChoice;

                // If no saved address, ask user to add an address or cancel order
                if (customer.getAddresses().empty()) {
                    cout << "You have no saved addresses." << endl << endl;
                    cout << "[1] Add address" << endl;
                    cout << "[2] Cancel (Back to Menu)" << endl << endl;

                    // Validate choice input
                    do {
                        getline(cin, choicePlaceholder);
                        validChoice(choicePlaceholder, addressChoice);
                    } while (addressChoice != 1 && addressChoice != 2);

                    if (addressChoice == 1) { // Add address
                        getShippingAddress(customer, choicePlaceholder);
                    } else { // Cancel (Back to Menu)
                        continue;
                    }
                }

                // Print addresses of the customer
                if (!customer.getAddresses().empty()) {
                    printTitle("Addresses");
                    customer.printAddresses();

                    // Validate address choice of customer
                    while (true) {
                        cout << endl << "Choose an address for shipping: ";
                        getline(cin, choicePlaceholder);
                        validChoice(choicePlaceholder, addressChoice);
                        if (!(addressChoice <= 0 || addressChoice > customer.getAddresses().size() + 1)) {
                            break;
                        }
                        cout << endl << "Error: Invalid address choice." << endl;
                    }
                }

                // Customer choose cancel order (back to menu)
                if (addressChoice == customer.getAddresses().size() + 1) { continue; }

                // Create a new order and clear cart
                orders.emplace_back(orders.size() + 1, cart.getItems(), customer.getAddresses()[addressChoice - 1]);
                cart.clearCart();

                cout << "Successfully checked out the products! Order ID: " << orders.size() << endl;
                backMenu(choicePlaceholder, backToMenu);
            }
        } else if (choice == 3) { // Viewing orders
            printTitle("Orders");

            if (orders.empty()) {
                cout << "No orders placed." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }

            for (const auto &order: orders) { // Display all orders
                order.viewOrder();
                cout << endl;
            }
            backMenu(choicePlaceholder, backToMenu);
        } else if (choice == 4) { // Exiting
            cout << "Thank you for shopping with us!" << endl;
        } else {
            cout << "Error: Please enter a valid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}