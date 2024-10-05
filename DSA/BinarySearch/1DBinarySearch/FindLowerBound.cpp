#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the largest element in the sorted vector that is less than or equal to x.

Approach:
1. Use binary search.
2. Adjust pointers based on comparison with x.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findFloor(vector<long long> &v, long long n, long long x) {
    int s = 0, e = v.size() - 1;
    int result = -1;
    
    while (s <= e) {
        int m = s + (e - s) / 2;
        
        if (v[m] == x) return m;
        else if (v[m] < x) {
            result = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    
    return result;
}

int main() {
    vector<long long> v = {1, 2, 4, 6, 10, 12, 14};
    long long x = 5;
    
    int index = findFloor(v, v.size(), x);
    
    // Test case explanation:
    // Vector: [1, 2, 4, 6, 10, 12, 14]
    // x = 5
    // The largest element less than or equal to 5 is 4, which is at index 2.
    // Expected output: 2
    
    if (index != -1) {
        cout << "The floor of " << x << " is " << v[index] << " at index " << index << endl;
    } else {
        cout << "No floor found for " << x << endl;
    }
    
    return 0;
}