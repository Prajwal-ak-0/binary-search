#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate the number of unique paths using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the number of unique paths by moving either down or right.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int solve(vector<vector<int>> &dp, int i, int j) {
    if (i == 0 || j == 0)
        return dp[i][j] = 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = solve(dp, i - 1, j) + solve(dp, i, j - 1);
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function starting from the bottom-right corner.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(dp, m - 1, n - 1);
}

int main() {
    // Example test case
    int m = 3, n = 7;

    // Explanation: There are 28 unique paths from the top-left corner to the bottom-right corner.
    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;

    return 0;
}

/*
Test Case:
Input: m = 3, n = 7
Expected Output: 28
Explanation: There are 28 unique paths from the top-left corner to the bottom-right corner.
*/