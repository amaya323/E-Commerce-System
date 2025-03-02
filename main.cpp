#include "Imports.hpp"
#include "Functions.cpp"
using namespace std;

//Main function to run the e-commerce system
int main() {
    // List of available products
    vector<Product> productList = {
        Product(1, "Laptop", 30000.00),
        Product(2, "Phone", 8000.00),
        Product(3, "Headphones", 850.00),
        Product(4, "Game Console", 20150.00),
        Product(5, "Personal Computer", 50000.00)
    };

    ShoppingCart cart;
    vector<Order> orders;
    int choice;
    string choicePlaceholder;
    int backToMenu = 0;
    int orderCount = 0;

    Customer customer;
    getCustomer(customer, choicePlaceholder);

    do {
        displayMenu();
        getline(cin, choicePlaceholder);
        validChoice(choicePlaceholder, choice);

        if (choice == 1) {
            // Viewing products

            char addMoreToCart;
            do {
                // Display product list
                printTitle("Products");
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
                while (true) {
                    cout << "Enter product ID to add to cart: ";
                    getline(cin, choicePlaceholder);
                    validChoice(choicePlaceholder, productId);
                    if (productId > 0 && productId <= productList.size() + 1) {
                        break;
                    }
                    cout << endl << "Error: Invalid Product ID" << endl << endl;
                }

                if (productId == productList.size() + 1) { break; }

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
                yesOrNo("Do you want to add another product? (Y/N): ", choicePlaceholder, addMoreToCart);
            } while (addMoreToCart == 'Y' || addMoreToCart == 'y');
        } else if (choice == 2) {
            // Viewing shopping cart

            printTitle("Shopping Cart");
            if (cart.getItems().empty()) {
                cout << "Your shopping cart is empty." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }
            cart.viewCart();
            char checkOut;
            yesOrNo("Checkout all products? (Y/N): ", choicePlaceholder, checkOut);

            if (checkOut == 'y') {
                //if user checks out clear the cart
                printTitle("Addresses");
                int addressChoice;
                if (customer.getAddresses().size() == 0) {
                    cout << "You have no saved addresses." << endl << endl;
                    cout << "[1] Add address" << endl;
                    cout << "[2] Cancel (Back to Menu)" << endl << endl;

                    do {
                        getline(cin, choicePlaceholder);
                        validChoice(choicePlaceholder, addressChoice);
                    } while (addressChoice != 1 && addressChoice != 2);
                    if (addressChoice == 1) {
                        getShippingAddress(customer, choicePlaceholder);
                    } else {
                        continue;
                    }
                }
                if (customer.getAddresses().size() != 0) {
                    printTitle("Addresses");
                    customer.printAddresses();
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
                if (addressChoice == customer.getAddresses().size() + 1) { continue; }

                orderCount++;
                orders.emplace_back(orderCount, cart.getItems(), customer.getAddresses()[addressChoice - 1]);
                cart.clearCart();
                cout << "Successfully checked out the products! Order ID: " << orders.size() << endl;
                backMenu(choicePlaceholder, backToMenu);
            }
        } else if (choice == 3) {
            // Viewing orders
            printTitle("Orders");
            if (orders.empty()) {
                cout << "No orders placed." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }

            for (const auto &order: orders) {
                order.viewOrder();
                cout << endl;
            }
            backMenu(choicePlaceholder, backToMenu);
        } else if (choice == 4) {
            // Exiting
            cout << "Thank you for shopping with us!" << endl;
        } else {
            cout << "Error: Please enter a valid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
