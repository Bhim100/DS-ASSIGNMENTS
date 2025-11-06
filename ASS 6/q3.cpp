#include <iostream>
using namespace std;

// -------------------- DOUBLY LINKED LIST --------------------
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
public:
    DLLNode* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DLLNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DLLNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DLLNode* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// -------------------- CIRCULAR SINGLY LINKED LIST --------------------
class CSLLNode {
public:
    int data;
    CSLLNode* next;

    CSLLNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularSinglyLinkedList {
public:
    CSLLNode* tail;

    CircularSinglyLinkedList() {
        tail = nullptr;
    }

    void insert(int val) {
        CSLLNode* newNode = new CSLLNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    int getSize() {
        if (!tail) return 0;

        int count = 0;
        CSLLNode* temp = tail->next;
        do {
            count++;

        }while (temp != tail->next);
        cout << endl;
    }
};