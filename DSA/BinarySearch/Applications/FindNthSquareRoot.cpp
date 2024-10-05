#include <iostream>

using namespace std;

/*
Idea: Find the nth root of a number m using binary search.

Approach:
1. Use binary search to find the nth root.
2. Calculate the mid value and raise it to the power of n.
3. Adjust the search range based on the comparison with m.

Time Complexity: O(n log m)
Space Complexity: O(1)
*/

int NthRoot(int n, int m) {
    int s = 0, e = m, md = -1;
    
    while (s <= e) {
        md = s + (e - s) / 2;
        
        long long int num = 1;
        
        for (int i = 0; i < n; i++) {
            num *= md;
            
            if (num > m) break;
        }
        
        if (num == m) return md;
        else if (num > m) e = md - 1;
        else s = md + 1;
    }
    
    return -1;
}

int main() {
    int n = 3;
    int m = 27;

    int result = NthRoot(n, m);

    // Test case explanation:
    // n = 3, m = 27
    // The 3rd root of 27 is 3.
    // Expected output: 3

    cout << "The " << n << "th root of " << m << " is " << result << endl;

    return 0;
}