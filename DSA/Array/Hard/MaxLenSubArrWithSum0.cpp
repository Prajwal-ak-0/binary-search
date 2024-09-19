#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Idea: Brute Force Approach
// Approach: Check all subarrays and calculate their sums
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxLenBruteForce(vector<int>& arr, int n) {
    int mx = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0, cnt = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            cnt++;
            if(sum == 0) mx = max(cnt, mx);
        }
    }
    return mx;
}

// Idea: Optimized Approach using Hash Map
// Approach: Use a hash map to store the sum and its index
// Time Complexity: O(n)
// Space Complexity: O(n)
int maxLenOptimized(vector<int>& arr, int n) {
    int mx = 0, sum = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == 0) {
            mx = max(mx, i + 1);
        } else {
            if(mp.find(sum) != mp.end()) mx = max(mx, i - mp[sum]);
            else mp[sum] = i;
        }
    }
    return mx;
}

int main() {
    // Example test case
    vector<int> arr = {1, -1, 3, 2, -2, -3, 3};
    int n = arr.size();

    cout << "Max Length of Subarray with Sum 0 (Brute Force): " << maxLenBruteForce(arr, n) << endl;
    cout << "Max Length of Subarray with Sum 0 (Optimized): " << maxLenOptimized(arr, n) << endl;

    return 0;
}