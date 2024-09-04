#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void initializeLastRow(int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
}

int calculateMaxChocolates(int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

// Main function to find the maximum chocolates that can be collected
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Initialize the DP array for the last row
    initializeLastRow(n, m, grid, dp);

    // Calculate the maximum chocolates that can be collected
    return calculateMaxChocolates(n, m, grid, dp);
}

int main() {
    // Example test case
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size();
    int m = grid[0].size();

    // Explanation: The maximum chocolates that can be collected is 21.
    cout << "Maximum Chocolates: " << maximumChocolates(n, m, grid) << endl;

    return 0;
}

/*
Test Case:
Input: grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}}
Expected Output: 21
Explanation: The maximum chocolates that can be collected is 21.
*/