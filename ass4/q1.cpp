#include <iostream>
using namespace std;

#define MAX 100  

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << element << endl;
        }
        else {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = element;
            cout << "inserted " << element << " in the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "removed element:  " << arr[front] << endl;
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty   " << endl;
        } else {
            cout << "Front element is:    " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, element;

    do {
        cout << "\n--- Queue Operations Menu ---\n";
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
                q.enqueue(element);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;

            case 6:
                if (q.isFull())
                    cout << "Queue is full\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 0:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice! Try again\n";
        }

    } while (choice != 0);

    return 0;
}
