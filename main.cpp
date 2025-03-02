#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//Function to print a title with formatting
void printTitle(const string& title) {
    system("cls"); // Clear the console screen
    int length = title.length();
    int padding = max(10, 30 - length);  // Ensure a minimum length
    string border(padding, '=');

    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

// Address class representing a customer's address
class Address {
private:
    string name;
    string address;

public:
    // Constructor to initialize address details
    Address(string n, string a) {
        name = n;
        address = a;
    }

    string getName() const{
        return name;
    }
    string getAddress() const{
        return address;
    }
};

// Customer class representing a user
class Customer {
private:
    int customerId;
    string customerName;
    vector<Address> addresses;

public:
    //setter for customerId
    void setCustomerId(int id) {
        customerId = id;
    }

    //setter for customerName
    void setCustomerName(string name) {
        customerName = name;
    }

    // Function to add a new address
    void addAddress(string name, string address) {
        addresses.emplace_back(name, address);
    }

    // Function to identify how many address of customer are stored
    int getHowManyAddresses() const {
        return addresses.size();
    }

    // Function to get address at Index N
    Address getAddressAtIndex(int index) const {
        return addresses[index];
    }
    // Function to print addresses
    void printAddresses() {
        cout << left << setw (5) << " "
                    << setw(15) << "Recipient"
                    << setw(12) << "Address"
                    << endl;
        cout << string(52, '-') << endl; // Print a separator line

        int counter = 0;
        for (const auto& address : addresses) {
            counter++;
            cout << left << setw(5) << counter
                << setw(15) << address.getName()
                << setw(12) << address.getAddress()
                << endl;
        }
        cout << string(52, '-') << endl;
        cout << endl << "[" << addresses.size() + 1 << "] Cancel (Back to Menu)" << endl;
    }
};

// Product class representing an item available for purchase
class Product {
private:
    int productId;
    string productName;
    double price;

public:
    // Constructor to initialize product details
    Product (int id, string name, double p){
        productId = id;
        productName = name;
        price = p;
    }

    // Getter function to retrieve product ID
    int getProductId() const{
        return productId;
    }

    // Getter function to retrieve product name
    string getProductName() const{
        return productName;
    }

    // Getter function to retrieve product price
    double getPrice() const{
        return price;
    }
};

// ShoppingItem class representing an item in the shopping cart
class ShoppingItem {
private:
    int quantity;
public:
    Product product;

    // Constructor to initialize shopping item with product and quantity
    ShoppingItem(Product p, int qty): product(p) {
        quantity = qty;
    }

    // Getter function to retrieve quantity
    int getQuantity() const{
        return quantity;
    }

    // Setter function to update quantity
    void setQuantity(int qty) {
        quantity = qty;
    }

    // Function to calculate total cost of the shopping item
    double getTotal() const {
        return product.getPrice() * quantity;
    }

    // Function to display a checkout message
    static void checkout() {
        cout<<"You have successfully checked out the products!"<<endl;
    }
};

// ShoppingCart class representing the user's cart
class ShoppingCart {
private:
    vector<ShoppingItem> shoppingItems;

public:
    // Function to add an item to the cart
    void addItem(const Product& product, int qty) {
        shoppingItems.emplace_back(product, qty);
        cout << "Product added successfully!" << endl;
    }

    // Function to calculate total price of items in the cart
    double getTotalPrice() const{
        double total = 0;
        for (const auto& item : shoppingItems) {
            total += item.product.getPrice() * item.getQuantity();
        }
        return total;
    }

    // Function to display cart contents
    void viewCart() const {
        cout << left << setw(12) << "Product ID"
        << setw(20) << "Name"
        << setw(10) << "Price"
        << setw(10) << "Quantity"
        << endl;

        cout << string(52, '-') << endl; // Print a separator line

        for (const auto& item : shoppingItems) {
            cout << left << setw(12) << item.product.getProductId()
                << setw(20) << item.product.getProductName()
                << setw(10) << fixed << setprecision(2) << item.product.getPrice()
                << setw(10) << item.getQuantity()
                << endl;
        }
        cout << string(52, '-') << endl;
        cout << "Total: " << getTotalPrice() << endl;
    }

    // Function to retrieve shopping cart items
    vector<ShoppingItem> getItems() {
        return shoppingItems;
    }

    // Function to clear all items from the cart
    void clearCart() {
        shoppingItems.clear();
    }
};

// Order class representing a placed order
class Order {
private:
    int orderId;
    vector<ShoppingItem> orderItems;
    Address address;

public:
    // Constructor to initialize order ID and order items
    Order(int id, vector<ShoppingItem> items, Address add): address(add) {
        orderId = id;
        orderItems = items;
    }

    // Getter function to retrieve order ID
    int getOrderId() const {
        return orderId;
    }

    // Function to calculate total amount of the order
    double getTotalAmount() const{
        double total = 0;
        for (const auto& item : orderItems) {
            total += item.product.getPrice() * item.getQuantity();
        }
        return total;
    }

    // Function to display order details
    void viewOrder() const {
        cout << "Order ID: " << orderId << endl;
        cout << "Shipping address: " << address.getAddress() << endl;
        cout << "Total Amount: " << fixed << setprecision(2) <<getTotalAmount() << endl;
        cout << left << setw(12) << "Product ID"
        << setw(20) << "Name"
        << setw(10) << "Price"
        << setw(10) << "Quantity"
        << endl;

        cout << string(52, '-') << endl;

        for (const auto& item : orderItems) {
            cout << left << setw(12) << item.product.getProductId()
                << setw(20) << item.product.getProductName()
                << setw(10) << fixed << setprecision(2) << item.product.getPrice()
                << setw(10) << item.getQuantity()
                << endl;
        }
        cout << string(52, '-') << endl;
        cout << "Total: " << getTotalAmount() << endl;
    }
};

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

        if (choice == 1) { // Viewing products

            char addMoreToCart;
            do {
                // Display product list
                printTitle("Products");
                cout << left << setw(12) << "Product ID"
                            << setw(20) << "Name"
                            << setw(10) << "Price"
                            << endl;
                cout << string(52, '-') << endl;

                for (const auto& item : productList) {
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

                if (productId == productList.size() + 1) {break;}

                while (true) {
                    cout << "Enter quantity: ";
                    getline(cin, choicePlaceholder);
                    validChoice(choicePlaceholder, quantity);
                    if (quantity != -1) {
                        cart.addItem(productList[productId-1], quantity);
                        break;
                    }
                    cout << "Error: Enter a valid quantity." << endl;
                }
                yesOrNo("Do you want to add another product? (Y/N): ", choicePlaceholder, addMoreToCart);
            } while (addMoreToCart == 'Y' || addMoreToCart == 'y');
        }
        else if (choice == 2) { // Viewing shopping cart

            printTitle("Shopping Cart");
            if (cart.getItems().empty()) {
                cout << "Your shopping cart is empty." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }
            cart.viewCart();
            char checkOut;
            yesOrNo("Checkout all products? (Y/N): ", choicePlaceholder, checkOut);

            if (checkOut == 'y') { //if user checks out clear the cart
                printTitle("Addresses");
                int addressChoice;
                if (customer.getHowManyAddresses() == 0) {
                    cout << "You have no saved addresses." << endl << endl;
                    cout << "[1] Add address" << endl;
                    cout << "[2] Cancel (Back to Menu)" << endl << endl;

                    do {
                        getline(cin, choicePlaceholder);
                        validChoice(choicePlaceholder, addressChoice);
                    } while (addressChoice != 1 && addressChoice != 2);
                    if (addressChoice == 1) {
                        getShippingAddress(customer, choicePlaceholder);
                    }else {
                        continue;
                    }
                } if (customer.getHowManyAddresses() != 0) {
                    printTitle("Addresses");
                    customer.printAddresses();
                    while (true) {
                        cout << endl << "Choose an address for shipping: ";
                        getline(cin, choicePlaceholder);
                        validChoice(choicePlaceholder, addressChoice);
                        if (!(addressChoice <= 0 || addressChoice > customer.getHowManyAddresses() + 1)) {
                            break;
                        }
                        cout << endl << "Error: Invalid address choice." << endl;
                    }
                }
                if (addressChoice == customer.getHowManyAddresses() + 1) {continue;}

                orderCount++;
                orders.emplace_back(orderCount , cart.getItems(), customer.getAddressAtIndex(addressChoice-1));
                cart.clearCart();
                cout << "Successfully checked out the products! Order ID: " << orders.size() << endl;
                backMenu(choicePlaceholder, backToMenu);
            }
        }
        else if (choice == 3) { // Viewing orders
            printTitle("Orders");
            if (orders.empty()) {
                cout << "No orders placed." << endl;
                backMenu(choicePlaceholder, backToMenu);
                continue;
            }

            for (const auto& order : orders) {
                order.viewOrder();
                cout << endl;
            }
            backMenu(choicePlaceholder, backToMenu);
        }
        else if (choice == 4) { // Exiting
            cout << "Thank you for shopping with us!" << endl;
        }
        else {
            cout << "Error: Please enter a valid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
