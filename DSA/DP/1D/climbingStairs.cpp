#include <iostream>
#include <vector>

using namespace std;

// Idea: This is a classic dynamic programming problem where the number of ways to reach the nth step is the sum of the ways to reach the (n-1)th and (n-2)th steps.
// Approach: Use an iterative approach with two variables to store the previous two results to save space.
// Time Complexity: O(n), where n is the number of stairs.
// Space Complexity: O(1), as we are using a constant amount of space.

// Function to calculate the number of ways to climb n stairs using memorization method
int climbStairsUsingMemo(int n, vector<int> &memo)
{
    if (n == 1 || n == 2) {
        return n;
    }
    if (memo[n] == -1)
    {
        memo[n] = climbStairsUsingMemo(n - 1, memo) + climbStairsUsingMemo(n - 2, memo);
    }
    return memo[n];
}

// Function to calculate the number of ways to climb n stairs using tabulation method and space optimization
int climbStairsUsingTab(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }

    int prev1 = 1; // Ways to reach the 1st step
    int prev2 = 2; // Ways to reach the 2nd step
    int curr = 0;

    for (int i = 3; i <= n; i++)
    {
        curr = prev1 + prev2; // Current step is the sum of the previous two steps
        prev1 = prev2;        // Move the previous step forward
        prev2 = curr;         // Move the current step forward
    }

    return curr;
}

int main()
{
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs using TABULATION : " << climbStairsUsingTab(n) << endl;
    vector<int> memo(n+1, -1);
    cout << "Number of ways to climb " << n << " stairs using MEMORIZATION : " << climbStairsUsingMemo(n, memo) << endl;
}