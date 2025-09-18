#include <iostream>
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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    int countocc(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    
    void deletocc(int key) {
        
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
            while (temp != nullptr && temp->next != nullptr) {
                if (temp->next->data == key) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }
    }
};

int main(){
    LinkedList LL; //100 100 200
    int c;
    for(int i =0;i<3;i++){
        cout<<"enter value to enter::\n";
        int x;
        cin>>x;
        LL.insert(x);
    }
    LL.printList();

    c=LL.countocc(100);
    cout<< " NO OF 100 is \n"<<c;

    LL.deletocc(100);

    LL.printList();


    return 0;
}