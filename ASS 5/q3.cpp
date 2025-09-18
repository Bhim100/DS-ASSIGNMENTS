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
    int mid(){
         
        if (head == nullptr) {
        cout << "List is empty." << endl;
        return -1;
    }

       
        node *slow=head;
        node* fast=head;;

        while(fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next; 
            fast=fast->next->next;   
        }
        return slow->data;
    }
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

    int middle = LL.mid();
    cout << "Middle element: " << middle << endl;

    return 0;
}