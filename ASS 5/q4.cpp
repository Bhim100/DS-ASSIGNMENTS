#include <iostream>
using namespace std;

class node{

    public:
    int data;
    node *next;
    
    public:
    node(int data){
        this->data=data;
        next=nullptr;

    }
    

};


class Linkedlist{
    node *head;
    
    public:
    Linkedlist(){
        head=nullptr;

    }
    void insert(int val){
        node*value= new node(val);
         
        if (head == nullptr) {
            head = value;
            return;
        }

        node *temp=head;
        
        while(temp->next !=nullptr){
            temp=temp->next;

        }
        temp->next=value;

    }

    void printLL(){
        node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        

    }

    void reverse() {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;   

};
};

int main() {
    Linkedlist LL;
    int x;

    for(int i=0;i<5;i++){
        cout<<"enter values to insert";
        cin>>x;
        LL.insert(x);
    }

   

    cout << "Linked List: ";
    LL.printLL();   
    cout<<"after reversal\n";
    LL.reverse();
    LL.printLL(); 
    
    

    return 0;
}