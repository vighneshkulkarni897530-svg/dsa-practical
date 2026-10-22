
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str, rev = "";
    stack<char> s;

    cout << "Enter a string: ";
    getline(cin, str);

    // Push characters into stack
    for (char ch : str)
    {
        s.push(ch);
    }

    // Pop characters to reverse the string
    while (!s.empty())
    {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed String: " << rev;

    return 0;
}
