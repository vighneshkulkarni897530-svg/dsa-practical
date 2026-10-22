
#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    if (r <= 0 || r > 10 || c <= 0 || c > 10) {
        cout << "Invalid matrix size!";
        return 0;
    }

    int A[10][10], B[10][10];
    int add[10][10], sub[10][10], mul[10][10];

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> B[i][j];

    // Addition and Subtraction
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            add[i][j] = A[i][j] + B[i][j];
            sub[i][j] = A[i][j] - B[i][j];
        }
    }

    // Multiplication (only for square matrices)
    if (r == c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mul[i][j] = 0;

                for (int k = 0; k < c; k++)
                    mul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nAddition Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << add[i][j] << " ";
        cout << endl;
    }

    cout << "\nSubtraction Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << sub[i][j] << " ";
        cout << endl;
    }

    if (r == c) {
        cout << "\nMultiplication Matrix:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << mul[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "\nMultiplication not possible in this program for non-square matrices.";
    }

    cout << "\nTranspose of Matrix A:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << A[j][i] << " ";
        cout << endl;
    }

    return 0;
}
