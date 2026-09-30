#include <iostream>
using namespace std;

class Order {
    int orderID;

    // Static member
    static int nextID;

public:
    // Constructor
    Order() {
        orderID = nextID++;
    }

    void display() {
        cout << "Order ID: " << orderID << endl;
    }
};

// Initialize static member
int Order::nextID = 1001;

int main() {

    Order o1;
    Order o2;
    Order o3;
    Order o4;

    o1.display();
    o2.display();
    o3.display();
    o4.display();

    return 0;
}