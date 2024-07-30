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
int minimumEnergyUsingMemo(vector<int> &height, int n, vector<int> &memo)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return abs(height[0] - height[1]);

    if (memo[n] != -1)
        return memo[n];

    int jump_2_stair = INT_MAX;

    int jump_1_stair = minimumEnergyUsingMemo(height, n - 1, memo) + abs(height[n] - height[n - 1]);
    if (n > 1)
        jump_2_stair = minimumEnergyUsingMemo(height, n - 2, memo) + abs(height[n] - height[n - 2]);

    return memo[n] = min(jump_1_stair, jump_2_stair);
}

// Function to calculate the minimum energy required to reach the nth step using memoization
int minimumEnergyUsingTab(vector<int> &height, int n)
{
    vector<int> tab(n, -1);
    tab[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int jump_2_stair = INT_MAX;
        int jump_1_stair = tab[i-1] + abs(height[i] - height[i-1]);
        if(jump_2_stair > 1) jump_2_stair = tab[i-2] + abs(height[i] - height[i-2]);

        tab[i] = min(jump_1_stair, jump_2_stair); 
    }

    return tab[n-1];
}

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> memo(n, -1);
    // return minimumEnergyUsingMemo(height, n - 1, memo);

    return minimumEnergyUsingTab(height, n);
}

int main()
{
    // Example test case: Heights of the steps
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();

    // Explanation: The minimum energy required to reach the last step is 20.
    // The path is: 10 -> 20 -> 10 (energy cost: 10 + 10 = 20)
    cout << "Minimum energy required to reach the last step: " << minimumEnergy(height, n) << endl;

    return 0;
}