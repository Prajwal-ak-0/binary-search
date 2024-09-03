#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate the number of unique paths with obstacles using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the number of unique paths by moving either down or right, considering obstacles.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return dp[i][j] = 0;

    if (i < 0 || j < 0)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = solve(i - 1, j, obstacleGrid, dp) + solve(i, j - 1, obstacleGrid, dp);
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function starting from the bottom-right corner.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the memoization array.
int uniquePathsWithObstaclesRecursive(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    return solve(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, obstacleGrid, dp);
}

// Function to calculate the number of unique paths with obstacles using dynamic programming
// Idea: Use a 2D dp array to store the number of unique paths to each cell, considering obstacles.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n), for storing the dp array.
int uniquePathsWithObstaclesDP(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // Create a 2D vector dp with the same dimensions as obstacleGrid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the starting point
    if (obstacleGrid[0][0] == 0) {
        dp[0][0] = 1;
    }

    // Fill the first row
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill the rest of the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    // Example test case
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Test the recursive approach
    cout << "Number of unique paths (Recursive): " << uniquePathsWithObstaclesRecursive(obstacleGrid) << endl;

    // Test the dynamic programming approach
    cout << "Number of unique paths (DP): " << uniquePathsWithObstaclesDP(obstacleGrid) << endl;

    return 0;
}

/*
Test Case:
Input: obstacleGrid = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
}
Expected Output:
Number of unique paths (Recursive): 2
Number of unique paths (DP): 2
Explanation: There are 2 unique paths from the top-left corner to the bottom-right corner, avoiding the obstacle.
*/