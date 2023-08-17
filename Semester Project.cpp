
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

class StockManagementSystem {
private:
    vector<Item> stock;

public:
    void addItem(const string& name, int quantity, double price) {
        Item newItem;
        newItem.name = name;
        newItem.quantity = quantity;
        newItem.price = price;
                stock.push_back(newItem);
        cout << "Item added to stock: " << name << endl;
    }

    void updateItem(const string& name, int newQuantity, double newPrice) {
        for (vector<Item>::iterator it = stock.begin(); it != stock.end(); ++it) {
            if (it->name == name) {
                it->quantity = newQuantity;
                it->price = newPrice;
                cout << "Item updated: " << name << endl;
                return;
            }
        }
        cout << "Item not found: " << name << endl;
    }

    void displayStock() {
        cout << "Current Stock Status:" << endl;
        for (vector<Item>::const_iterator it = stock.begin(); it != stock.end(); ++it) {
            cout << "Name: " << it->name << " | Quantity: " << it->quantity << " | Price: " << it->price << endl;
        }
    }
};

int main() {
    StockManagementSystem system;

    system.addItem("Product A", 10, 25.99);
    system.addItem("Product B", 5, 15.49);

    system.displayStock();

    system.updateItem("Product A", 15, 29.99);

    system.displayStock();
