#include <iostream>
using namespace std;

#define MAX 100  

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full " << element << endl;
        } else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }
            arr[rear] = element;
            cout << "Inserted " << element << " in the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty " << endl;
        } else {
            cout << "Removed element:   " << arr[front] << endl;

            if (front == rear) {
                
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element is:    " << arr[front] << endl;
        }
    }

    void display() {
    if (isEmpty()) {
        cout << "Queue is empty    " << endl;
    } else {
        cout << "Queue elements: ";
        int i = front;
        
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        
        cout << arr[rear];
        cout << endl;
    }
}
};

int main() {
    CircularQueue cq;
    int choice, element;

    do {
        cout << "\n--- Circular Queue Operations Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                cq.enqueue(element);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.peek();
                break;

            case 4:
                cq.display();
                break;

            case 5:
                if (cq.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 6:
                if (cq.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
