
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maximum = arr[0];
    int minimum = arr[0];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];

        if (arr[i] < minimum)
            minimum = arr[i];

        sum += arr[i];
    }

    double average = (double)sum / n;

    int maxFreq = 0;
    int frequentElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxFreq) {
            maxFreq = count;
            frequentElement = arr[i];
        }
    }

    cout << "\nMaximum Value = " << maximum;
    cout << "\nMinimum Value = " << minimum;
    cout << "\nAverage Value = " << average;
    cout << "\nHighest Frequency Element = " << frequentElement;
    cout << "\nFrequency = " << maxFreq;

    return 0;
}
