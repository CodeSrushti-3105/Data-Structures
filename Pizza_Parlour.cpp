#include <iostream>
using namespace std;

#define M 5  // Maximum number of orders

class PizzaParlor {
    string queue[M];  // Array to store pizza orders
    int front, rear;

public:
    PizzaParlor() {
        front = rear = -1;  // Initially, queue is empty
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % M == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Place a new pizza order
    void placeOrder(string order) {
        if (isFull()) {
            cout << "Parlor is full! Cannot place more orders.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % M;
        }

        queue[rear] = order;
        cout << "Order placed: " << order << endl;
    }

    // Serve the oldest order
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve!\n";
            return;
        }

        cout << "Order served: " << queue[front] << endl;

        if (front == rear) {
            // Only one order left, now queue will be empty
            front = rear = -1;
        } else {
            front = (front + 1) % M;
        }
    }

    // Display all pending orders
    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending orders: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % M;
        }
        cout << endl;
    }
};

int main() {
    PizzaParlor parlor;
    int choice;
    string order;

    do {
        cout << "\n--- Pizza Parlor Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter pizza name: ";
            cin.ignore();
            getline(cin, order);
            parlor.placeOrder(order);
            break;
        case 2:
            parlor.serveOrder();
            break;
        case 3:
            parlor.displayOrders();
            break;
        case 4:
            cout << "Thank you for using Pizza Parlor Simulation!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
