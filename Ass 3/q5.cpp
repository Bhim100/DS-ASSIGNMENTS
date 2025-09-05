#include <bits/stdc++.h>
using namespace std;


int evaluatePostfix(string expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            // Convert char to int and push
            st.push(ch - '0');
        } 
        else {
            // Pop two operands
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top(); // final result
}

int main() {
    string expr = "23*54*+9-";
    cout << "Postfix Evaluation Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
