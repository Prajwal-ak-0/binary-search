#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
// Approach: Recursively calculate the minimum energy required to reach each step and store the results in the memo array.
// Time Complexity: O(n), where n is the number of steps.
// Space Complexity: O(n), for storing the memo array.

// Function to calculate the minimum energy required to reach the nth step using memoization
int minimumEnergyUsingMemo(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;

    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1)
        return dp[ind];

    int jump_i_stairs = INT_MAX;

    // Loop to try all possible jumps from '1' to 'k'
    for (int j = 1; j <= k; j++)
    {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0)
        {
            // Calculate the cost for this jump and update jump_i_stairs with the minimum cost
            int jump = minimumEnergyUsingMemo(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            jump_i_stairs = min(jump, jump_i_stairs);
        }
    }

    // Store the minimum cost for this index in the dp array and return it.
    return dp[ind] = jump_i_stairs;
}

// Function to calculate the minimum energy required to reach the nth step using tabulation
int minimumEnergyUsingTab(vector<int> &height, int n, int k, vector<int> &memo)
{
    memo[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int jump_i_stairs = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = memo[i - j] + abs(height[i] - height[i - j]);
                jump_i_stairs = min(jump, jump_i_stairs);
            }
        }

        memo[i] = jump_i_stairs;
    }

    return memo[n - 1];
}

int minimumEnergy(vector<int> &height, int n, int k)
{
    vector<int> memo(n, -1);
    return minimumEnergyUsingMemo(n - 1, height, memo, k);

    // return minimumEnergyUsingTab(height, n, k, memo);
}

int main()
{
    // Example test case: Heights of the steps
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    int k = 2;

    // Explanation: The minimum energy required to reach the last step is 20.
    // The path is: 10 -> 20 -> 10 (energy cost: 10 + 10 = 20)
    cout << "Minimum energy required to reach the last step: " << minimumEnergy(height, n, k) << endl;

    return 0;
}