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
    string choicePlaceholder; // Input placeholder for validation
    int choice; // User menu choice
    int backToMenu = 0; // Variable to handle return to menu
    string name;

     // Customer instance

    printTitle("Welcome Customer!");
    cout << "Enter name: ";
    getline(cin, name);
    Customer customer(1, name);


    // Main loop for menu navigation
    do {
        backToMenu = productList.size() + 1; // Return to menu choice number is the number of products + 1;
        displayMenu(); // Display the main menu
        getline(cin, choicePlaceholder);
        validNumber(choicePlaceholder, choice); // Validate user choice

        if (choice == 1) { // Viewing products
            char addMoreToCart;
            do {
                printTitle("Products"); // Display product list header

                // Display product details
                displayProduct(productList);

                int productId, quantity;

                // Prompt user to select a product by ID
                getValidatedInput("Enter product ID to add to cart: ", productId, 1, productList.size() + 1);

                if (productId == backToMenu) { break; } // Return to menu

                // Prompt user to enter quantity
                getValidatedInput("Enter quantity: ", quantity, 1, 100);

                bool isAlreadyExists = false;
                for (int i = 0; i < cart.getItems().size(); i++) {
                    if (cart.getItems()[i].getProduct().getProductId() == productId) {
                        cart.addQuantity(i, quantity);
                        isAlreadyExists = true;
                        break;
                    }
                }
                if (isAlreadyExists == false) {
                    cart.addItem(productList[productId - 1], quantity);
                }

                // Ask if the user wants to add another product
                askYesOrNo("Do you want to add another product? (Y/N): ", choicePlaceholder, addMoreToCart);
            } while (tolower(addMoreToCart) == 'y');

        } else if (choice == 2) { // Viewing shopping cart
            printTitle("Shopping Cart");

            if (cart.getItems().empty()) { // Check if cart is empty
                cout << "Your shopping cart is empty." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }

            cart.viewCart(); // Display cart contents

            char checkOut;
            askYesOrNo("Checkout all products? (Y/N): ", choicePlaceholder, checkOut);

            if (checkOut == 'y') {
                // Display address selection
                printTitle("Addresses");
                int addressChoice = 0;

                // If no saved address, ask user to add an address or cancel order
                if (customer.getAddresses().empty()) {
                    cout << "You have no saved addresses." << endl << endl;
                    cout << "[1] Add address" << endl;
                    cout << "[2] Cancel (Back to Menu)" << endl << endl;

                    // Validate choice input
                    do {
                        getline(cin, choicePlaceholder);
                        validNumber(choicePlaceholder, addressChoice);
                    } while (addressChoice != 1 && addressChoice != 2);

                    if (addressChoice == 1) { // Add address
                        getShippingAddress(customer);
                    } else { // Cancel (Back to Menu)
                        continue;
                    }
                }

                // Loop for getting address of customer
                bool addAnotherAddress;
                do{
                    addressChoice = 0;
                    addAnotherAddress = false;
                    // Print addresses of the customer
                    if (!customer.getAddresses().empty()) {
                        printTitle("Addresses");
                        customer.printAddresses();

                        // Validate address choice of customer
                        getValidatedInput("Choose an address for shipping: ", addressChoice, 1, customer.getAddresses().size() + 2);
                    }

                    if (addressChoice == customer.getAddresses().size() + 1){
                        getShippingAddress(customer);
                        addAnotherAddress = true;
                    }
                }while (addAnotherAddress);


                // Customer choose cancel order (back to menu)
                if (addressChoice == customer.getAddresses().size() + 2){continue;}


                // Create a new order and clear cart
                orders.emplace_back(orders.size() + 1, cart.getItems(), customer, addressChoice-1);
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
                order.viewShoppingItems();
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