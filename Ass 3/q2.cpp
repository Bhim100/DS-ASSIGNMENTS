#include <bits/stdc++.h>
using namespace std;

#define MAX 100   // Max size of Stack

class Stack {
private:
    char arr[MAX];
    int top;

public:
    
    Stack() {
        top = -1;
    }

    
    bool isEmpty() {
        return (top == -1);
    }

   
    bool isFull() {
        return (top == MAX - 1);
    }


    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow " <<endl;
        } else {
            top = top + 1;   
            arr[top] = x;
            
        }
    }

   
    char pop() {
        if (isEmpty()) {
            cout << "Stack Empty" << endl;
        } else {
            char x = arr[top];
            top = top - 1;
            return x;
        }
    }

    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

   
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

void rev_string(char str[]){
    int n = strlen(str);
    Stack s;
    for(int i=0; i<n; i++){
        s.push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        str[i] = s.pop();
    }
}
int main() {
    char str[MAX];
    cout << "Enter string:  ";
    cin.getline(str, MAX);

    rev_string(str);

    cout << "Reversed string:   " << str << endl;
    return 0;
}
    
