#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve the knapsack problem using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the maximum value that can be obtained by including or excluding each item.
// Time Complexity: O(n * W), where n is the number of items and W is the maximum weight capacity.
// Space Complexity: O(n * W), for storing the memoization array.
int solve(int n, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (n == wt.size() || W == 0) return dp[n][W] = 0;

    if (dp[n][W] != -1) return dp[n][W];

    if (W < wt[n]) {
        return dp[n][W] = solve(n + 1, W, wt, val, dp);
    } else {
        return dp[n][W] = max(
            solve(n + 1, W, wt, val, dp),
            solve(n + 1, W - wt[n], wt, val, dp) + val[n]
        );
    }
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function starting from the first item and the full weight capacity.
// Time Complexity: O(n * W), where n is the number of items and W is the maximum weight capacity.
// Space Complexity: O(n * W), for storing the memoization array.
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, -1));
    return solve(0, W, wt, val, dp);
}

int main() {
    // Example test case
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    // Explanation: The maximum value that can be obtained is 9 by selecting items with weights 3 and 4.
    cout << "Maximum value in Knapsack: " << knapSack(W, wt, val) << endl;

    return 0;
}

/*
Test Case:
Input: wt = {1, 3, 4, 5}, val = {1, 4, 5, 7}, W = 7
Expected Output: 9
Explanation: The maximum value that can be obtained is 9 by selecting items with weights 3 and 4.
*/