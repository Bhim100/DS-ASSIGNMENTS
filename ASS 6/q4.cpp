#include <iostream>
using namespace std;


class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char val) {
        data = val;
        prev = next = nullptr;
    }
};


class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = nullptr;
    }

    
    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

   
    void display() {
        Node* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    bool isPalindrome() {
        if (!head) return true; 

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    string str;
    cout << "Enter characters for the list (no spaces): ";
    cin >> str;

    // Insert all characters into the DLL
    for (char ch : str)
        dll.insertAtEnd(ch);

    dll.display();

    if (dll.isPalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is NOT a palindrome.\n";

    return 0;
}
