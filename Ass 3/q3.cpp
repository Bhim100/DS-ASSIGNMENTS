#include <bits/stdc++.h>

using namespace std;


bool Balanced(string expr) {
    int countBrackets = 0;

    // Count only the brackets
    for (char ch : expr) {
        if (ch == '(' || ch == ')' || 
            ch == '{' || ch == '}' || 
            ch == '[' || ch == ']') {
            countBrackets++;
        }
    }

    //  if odd number  brackets, its not  balanced
    if (countBrackets % 2 != 0) {
        return false;
    }

    stack<char> st;

    
    for (char ch : expr) {
        // If it's an opening bracket push it
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (st.empty()) return false;//there are no opening brackets

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop(); 
            } else {
                return false; 
            }
        }
    }

    
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (Balanced(expression)) {
        cout << "The expression has balanced parentheses.\n";
    } else {
        cout << "The expression does NOT have balanced parentheses.\n";
    }

    return 0;
}
