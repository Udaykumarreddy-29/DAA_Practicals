#include <iostream>
using namespace std;

unsigned long long calculateFactorialRecursive(int n) {
  
    if (n <= 1) {
        return 1;
    }
    
    return n * calculateFactorialRecursive(n - 1);
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
        unsigned long long factorial = calculateFactorialRecursive(number);
        cout << "Factorial of " << number << " is: " << factorial << endl;
    }

    return 0;
}
