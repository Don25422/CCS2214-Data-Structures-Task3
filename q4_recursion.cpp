#include <iostream>
using namespace std;

// 4a) Sum of first N natural numbers
int sumNatural(int n) {
    if (n <= 0) return 0;               // Base case
    return n + sumNatural(n - 1);       // Recursive case
}

// 4b) Factorial of a number
long long factorial(int n) {
    if (n <= 1) return 1;               // Base case (0! = 1, 1! = 1)
    return n * factorial(n - 1);        // Recursive case
}

// 4c) Nth term of Fibonacci series (0-indexed: F(0)=0, F(1)=1, F(2)=1...)
int fibonacciTerm(int n) {
    if (n <= 1) return n;               // Base cases
    return fibonacciTerm(n - 1) + fibonacciTerm(n - 2);
}

// 4d) Generate and print N terms of a Fibonacci series
void printFibonacciSeries(int n, int a = 0, int b = 1) {
    if (n <= 0) return;                 // Base case: no more terms to print
    cout << a << " ";                   // Print current term
    printFibonacciSeries(n - 1, b, a + b); // Advance to next term
}

int main() {
    int n = 6;

    cout << "Testing with N = " << n << "\n";
    cout << "-----------------------------------\n";
    cout << "a) Sum of first " << n << " numbers : " << sumNatural(n) << "\n";
    cout << "b) Factorial of " << n << "       : " << factorial(n) << "\n";
    cout << "c) Fibonacci term F(" << n << ")   : " << fibonacciTerm(n) << "\n";
    cout << "d) First " << n << " Fibonacci terms: ";
    printFibonacciSeries(n);
    cout << "\n";

    return 0;
}