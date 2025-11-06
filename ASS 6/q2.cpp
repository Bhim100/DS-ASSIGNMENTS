#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void displayWithHeadRepeat(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";

    
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    
    cout << head->data << "\n";
}

int main() {
    // manually create a circular linked list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = head; // circular connection

    displayWithHeadRepeat(head);
}
