#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to calculate the minimum falling path sum using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the minimum falling path sum by moving either up, up-right, or up-left.
// Time Complexity: O(n^2), where n is the number of rows in the matrix.
// Space Complexity: O(n^2), for storing the memoization array.
int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || j >= matrix.size())
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0)
        return matrix[0][j];

    int up = solve(i - 1, j, matrix, dp);
    int upRight = solve(i - 1, j + 1, matrix, dp);
    int upLeft = solve(i - 1, j - 1, matrix, dp);

    dp[i][j] = matrix[i][j] + min(up, min(upRight, upLeft));
    return dp[i][j];
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function for each element in the last row.
// Time Complexity: O(n^2), where n is the number of rows in the matrix.
// Space Complexity: O(n^2), for storing the memoization array.
int minFallingPathSumMemoization(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int mini = INT_MAX;

    for (int j = 0; j < n; j++) {
        mini = min(mini, solve(n - 1, j, matrix, dp));
    }

    return mini;
}

// Function to calculate the minimum falling path sum using dynamic programming
// Idea: Use a DP array to store the minimum falling path sum to each cell by moving either up, up-right, or up-left.
// Time Complexity: O(n^2), where n is the number of rows in the matrix.
// Space Complexity: O(n^2), for storing the DP array.
int minFallingPathSumDP(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int up = dp[i - 1][j];
            int upRight = (j + 1 < n) ? dp[i - 1][j + 1] : INT_MAX;
            int upLeft = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;

            dp[i][j] = matrix[i][j] + min(up, min(upRight, upLeft));
        }
    }

    int mini = INT_MAX;
    for (int j = 0; j < n; j++) {
        mini = min(mini, dp[n - 1][j]);
    }

    return mini;
}

int main() {
    // Example test case
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    // Explanation: The minimum falling path sum is 13 by following the path 1→5→7.
    cout << "Minimum Falling Path Sum (Memoization): " << minFallingPathSumMemoization(matrix) << endl;
    cout << "Minimum Falling Path Sum (DP): " << minFallingPathSumDP(matrix) << endl;

    return 0;
}

/*
Test Case:
Input: matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}
Expected Output: 
Minimum Falling Path Sum (Memoization): 13
Minimum Falling Path Sum (DP): 13
Explanation: The minimum falling path sum is 13 by following the path 1→5→7.
*/