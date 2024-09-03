#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to calculate the minimum path sum in a triangle using memoization
// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the minimum path sum by moving either up or up-left.
// Time Complexity: O(n^2), where n is the number of rows in the triangle.
// Space Complexity: O(n^2), for storing the memoization array.
int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if (i == 0 && j == 0)
        return triangle[0][0];

    if (i < 0 || j < 0 || j > i)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, triangle, dp);
    int upLeft = solve(i - 1, j - 1, triangle, dp);

    return dp[i][j] = triangle[i][j] + min(up, upLeft);
}

// Function to initialize the memoization array and call the recursive solve function
// Idea: Initialize a 2D memoization array and call the solve function for each element in the last row.
// Time Complexity: O(n^2), where n is the number of rows in the triangle.
// Space Complexity: O(n^2), for storing the memoization array.
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int minSum = INT_MAX;
    for (int j = 0; j < n; ++j) {
        minSum = min(minSum, solve(n - 1, j, triangle, dp));
    }

    return minSum;
}

int main() {
    // Example test case
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // Explanation: The minimum path sum is 11 by following the path 2→3→5→1.
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;

    return 0;
}

/*
Test Case:
Input: triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}
Expected Output: 11
Explanation: The minimum path sum is 11 by following the path 2→3→5→1.
*/