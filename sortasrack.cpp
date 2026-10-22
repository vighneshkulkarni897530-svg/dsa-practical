
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> original, temp;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number of elements.";
        return 0;
    }

    cout << "Enter stack elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        original.push(value);
    }

    while (!original.empty())
    {
        int current = original.top();
        original.pop();

        while (!temp.empty() && temp.top() > current)
        {
            original.push(temp.top());
            temp.pop();
        }

        temp.push(current);
    }

    cout << "\nSorted Stack (Top to Bottom):\n";

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}
