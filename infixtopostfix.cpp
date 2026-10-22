
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isdigit(static_cast<unsigned char>(ch))) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) &&
                    ch != '^'))) {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        if (isdigit(static_cast<unsigned char>(ch))) {
            st.push(ch - '0');
        }
        else {
            if (st.size() < 2) {
                cout << "Invalid Expression\n";
                return 0;
            }

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;

                case '/':
                    if (b == 0) {
                        cout << "Division by zero\n";
                        return 0;
                    }
                    st.push(a / b);
                    break;

                case '^':
                    st.push(static_cast<int>(pow(a, b)));
                    break;

                default:
                    cout << "Invalid Operator\n";
                    return 0;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Invalid Expression\n";
        return 0;
    }

    return st.top();
}

int main() {
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\nPostfix Expression: " << postfix;

    int result = evaluatePostfix(postfix);

    cout << "\nEvaluation Result: " << result;

    return 0;
}
