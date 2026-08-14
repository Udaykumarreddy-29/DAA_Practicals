#include <iostream>
using namespace std; // Includes the standard namespace

// Function to calculate factorial iteratively
unsigned long long calculateFactorial(int n) {
    if (n < 0) {
        return 0; 
    }

    unsigned long long result = 1;
    
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    
    return result;
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Error: Factorial of a negative number doesn't exist." << endl;
    } else if (number > 20) {
        cout << "Error: Result too large to handle with standard data types (Max input: 20)." << endl;
    } else {
        unsigned long long factorial = calculateFactorial(number);
        cout << "Factorial of " << number << " is: " << factorial << endl;
    }

    return 0;
}
