#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};


class Linked_list{
    private:
    Node *head;
    public:
    Linked_list(){
        head=nullptr;}

    void Insert_Beg(int val){
        Node *first=new Node(val);
        first->next=head;
        head=first;
    }
    void Insert_End(int val){
        Node*New=new Node(val);
        if (head == nullptr) {
        head = New;
        return;}
        
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;

        }
        temp->next=New;
        
    }
    void deleteFromBeg() {
    if (head == nullptr) {
        cout << "Empty LL \n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
    void deleteFromEnd(){
        if(head==nullptr){
            cout<<"LL empty"<<endl;
        }
        if(head->next==NULL){
                delete head;
                head=nullptr;
                return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
        temp = temp->next;
        }
         delete temp->next;
        temp->next = nullptr;

    }
    void searchNode(int value) {
    Node* temp = head;
    int pos;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node found at position: " <<pos<<endl;           
            return;
        }
        temp = temp->next;
        pos++;
    }
    }
    void displayList() {
    if (head == nullptr) {
        cout << "List Empty\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
    void Insert_after(int val,int target){

        
        Node*temp=head;
        while(temp!=nullptr){
            if(temp->data==target){
                Node*newnode= new Node(val);
                newnode->next=temp->next;
                temp->next=newnode;

            }
            temp=temp->next;

        }

    } 
    void Insert_before(int val,int target){
        
        if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == target) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
        
        
        Node*temp=head;
        while(temp->next!=nullptr){
            if(temp->next->data==target){
                Node*newnode= new Node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                return;

            }
            temp=temp->next;
            
        }

    
    }

};  

