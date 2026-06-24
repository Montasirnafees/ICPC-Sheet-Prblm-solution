#include <iostream>
using namespace std;

// 1. Sum of two numbers
int calculate(int a, int b) {
    return a + b;
}

// 2. Average of three numbers
double calculate(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

// 3. Product of two double numbers
double calculate(double a, double b) {
    return a * b;
}

// 4. Factorial of a number
int calculate(int a) {
    int fact = 1;
    for(int i = 1; i <= a; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int a, b, c, n;
    double x, y;

    // Sum
    cout << "Enter two integers for sum: ";
    cin >> a >> b;
    cout << "Sum = " << calculate(a, b) << endl;

    // Average
    cout << "Enter three integers for average: ";
    cin >> a >> b >> c;
    cout << "Average = " << calculate(a, b, c) << endl;

    // Product
    cout << "Enter two decimal numbers for product: ";
    cin >> x >> y;
    cout << "Product = " << calculate(x, y) << endl;

    // Factorial
    cout << "Enter a number for factorial: ";
    cin >> n;
    cout << "Factorial = " << calculate(n) << endl;

    return 0;
}
