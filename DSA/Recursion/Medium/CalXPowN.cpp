#include <iostream>

using namespace std;

/*
Idea: Calculate x raised to the power n (x^n).

Approach:
1. If n is 0, return 1 (base case).
2. If n is negative, convert x to 1/x and n to -n.
3. Use recursion to calculate the power:
   - If n is even, recursively calculate (x * x)^(n / 2).
   - If n is odd, recursively calculate x * x^(n - 1).

Time Complexity: O(log n) - We divide the problem size by 2 in each recursive step.
Space Complexity: O(log n) - The recursion stack will have log n depth.
*/

double myPow(double x, int n) {
    long long N = n;
    if (N == 0)
        return 1;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    if (N % 2 == 0)
        return myPow(x * x, N / 2);
    return x * myPow(x, N - 1);
}

int main() {
    // Test case 1: x = 2.0, n = 10
    // Explanation: 2^10 = 1024
    // Expected output: 1024
    double x1 = 2.0;
    int n1 = 10;
    cout << "myPow(" << x1 << ", " << n1 << ") = " << myPow(x1, n1) << endl;

    // Test case 2: x = 2.0, n = -2
    // Explanation: 2^-2 = 1 / (2^2) = 1 / 4 = 0.25
    // Expected output: 0.25
    double x2 = 2.0;
    int n2 = -2;
    cout << "myPow(" << x2 << ", " << n2 << ") = " << myPow(x2, n2) << endl;

    // Test case 3: x = 2.1, n = 3
    // Explanation: 2.1^3 = 2.1 * 2.1 * 2.1 = 9.261
    // Expected output: 9.261
    double x3 = 2.1;
    int n3 = 3;
    cout << "myPow(" << x3 << ", " << n3 << ") = " << myPow(x3, n3) << endl;

    return 0;
}