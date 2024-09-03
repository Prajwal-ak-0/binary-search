#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to calculate the minimum path sum using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the minimum path sum by moving either up or left.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i == 0 && j == 0)
        return dp[0][0] = grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = grid[i][j] + min(solve(i - 1, j, grid, dp), solve(i, j - 1, grid, dp));
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function starting from the bottom-right corner.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int minPathSumMemoization(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return solve(grid.size() - 1, grid[0].size() - 1, grid, dp);
}

// Function to calculate the minimum path sum using dynamic programming
// Idea: Use a DP array to store the minimum path sum to each cell by moving either down or right.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the DP array.
int minPathSumDP(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum Path Sum (Memoization): " << minPathSumMemoization(grid) << endl;
    cout << "Minimum Path Sum (DP): " << minPathSumDP(grid) << endl;

    return 0;
}

/*
Test Case:
Input: grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
Expected Output: 
Minimum Path Sum (Memoization): 7
Minimum Path Sum (DP): 7
Explanation: The minimum path sum is 7 by following the path 1→3→1→1→1.
*/