#include <iostream>

using namespace std;

/*
Idea: Find the floor value of the square root of a given number n using binary search.

Approach:
1. Initialize start (s) to 0 and end (e) to n.
2. Use binary search to find the middle value (m).
3. If m*m equals n, return m as the square root.
4. If m*m is greater than n, adjust the end pointer to m - 1.
5. If m*m is less than n, adjust the start pointer to m + 1.
6. Continue the process until start exceeds end.
7. Return the end pointer as the floor value of the square root.

Time Complexity: O(log n) - The binary search reduces the search space by half each time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

long long int floorSqrt(long long int n) {
    long long int s = 0, e = n, m;

    while (s <= e) {
        m = s + (e - s) / 2;

        if (m * m == n) return m;
        else if (m * m > n) e = m - 1;
        else s = m + 1;
    }

    return e;
}

int main() {
    long long int n = 10;

    long long int result = floorSqrt(n);

    // Test case explanation:
    // n = 10
    // The floor value of the square root of 10 is 3.
    // This is because 3*3 = 9 which is the largest perfect square less than or equal to 10.
    // Expected output: 3

    cout << "The floor value of the square root of " << n << " is " << result << endl;

    n = 16;
    result = floorSqrt(n);

    // Test case explanation:
    // n = 16
    // The floor value of the square root of 16 is 4.
    // This is because 4*4 = 16 which is exactly equal to 16.
    // Expected output: 4

    cout << "The floor value of the square root of " << n << " is " << result << endl;

    n = 27;
    result = floorSqrt(n);

    // Test case explanation:
    // n = 27
    // The floor value of the square root of 27 is 5.
    // This is because 5*5 = 25 which is the largest perfect square less than or equal to 27.
    // Expected output: 5

    cout << "The floor value of the square root of " << n << " is " << result << endl;

    return 0;
}