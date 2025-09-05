#include <bits/stdc++.h>

using namespace std;

// Function to set precedence of operators
int precedence(char op) {
    if (op == '^') return 3;        // highest precedence
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;                       
}


string infixToPostfix(string infix) {
    stack<char> st;       
    string postfix = "";  

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ) , pop until ( is found
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // If operator 
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
