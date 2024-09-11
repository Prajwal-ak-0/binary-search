#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Approach 1: Brute Force
// Idea: Check all possible pairs of buy and sell days to find the maximum profit.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxProfitBruteForce(vector<int>& prices) {
    int mx = INT_MIN, n = prices.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mx = max(mx, prices[j] - prices[i]);
        }
    }

    return mx;
}

// Approach 2: Optimized using a single pass
// Idea: Track the minimum price and calculate the maximum profit by comparing the current price with the minimum price.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxProfitOptimized(vector<int>& prices) {
    int mn = prices[0], mxP = 0;
    
    for(int p : prices){
        mn = min(mn, p);
        mxP = max(mxP, p - mn);
    }

    return mxP;
}

int main() {
    // Example test cases
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {1, 2, 3, 4, 5};
    vector<int> prices4 = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Using Brute Force Approach:" << endl;
    cout << "Test Case 1: Max Profit = " << maxProfitBruteForce(prices1) << endl; // Expected Output: 5
    cout << "Test Case 2: Max Profit = " << maxProfitBruteForce(prices2) << endl; // Expected Output: 0
    cout << "Test Case 3: Max Profit = " << maxProfitBruteForce(prices3) << endl; // Expected Output: 4
    cout << "Test Case 4: Max Profit = " << maxProfitBruteForce(prices4) << endl; // Expected Output: 4

    cout << "Using Optimized Approach:" << endl;
    cout << "Test Case 1: Max Profit = " << maxProfitOptimized(prices1) << endl; // Expected Output: 5
    cout << "Test Case 2: Max Profit = " << maxProfitOptimized(prices2) << endl; // Expected Output: 0
    cout << "Test Case 3: Max Profit = " << maxProfitOptimized(prices3) << endl; // Expected Output: 4
    cout << "Test Case 4: Max Profit = " << maxProfitOptimized(prices4) << endl; // Expected Output: 4

    return 0;
}

/*
Test Cases:
1. Input: prices = {7, 1, 5, 3, 6, 4}
   Expected Output: Max Profit = 5
   Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.

2. Input: prices = {7, 6, 4, 3, 1}
   Expected Output: Max Profit = 0
   Explanation: No transactions are done, i.e., max profit = 0.

3. Input: prices = {1, 2, 3, 4, 5}
   Expected Output: Max Profit = 4
   Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5 - 1 = 4.

4. Input: prices = {3, 3, 5, 0, 0, 3, 1, 4}
   Expected Output: Max Profit = 4
   Explanation: Buy on day 4 (price = 0) and sell on day 8 (price = 4), profit = 4 - 0 = 4.
*/