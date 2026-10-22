
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> orders;
    int n, choice;

    string menu[] = {
        "Vanilla",
        "Chocolate",
        "Strawberry",
        "Mango",
        "Butterscotch"
    };

    cout << "------ Ice Cream Menu ------\n";

    for (int i = 0; i < 5; i++)
        cout << i + 1 << ". " << menu[i] << endl;

    cout << "\nEnter number of orders: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number of orders!";
        return 0;
    }

    // Take bulk orders
    for (int i = 0; i < n; i++)
    {
        cout << "Enter choice for Order " << i + 1 << ": ";
        cin >> choice;

        // Validate user choice
        if (choice >= 1 && choice <= 5)
            orders.push(menu[choice - 1]);
        else
            cout << "Invalid Choice!\n";
    }

    cout << "\nOrder placed successfully.\n";
    cout << "Order cancellation is not allowed.\n";

    // Display all orders
    cout << "\nOrders in Queue:\n";

    while (!orders.empty())
    {
        cout << orders.front() << endl;
        orders.pop();
    }

    return 0;
}
