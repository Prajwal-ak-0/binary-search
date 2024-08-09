#include <bits/stdc++.h>

using namespace std;

int knapsackRecursive(int W, vector<int> wt, vector<int> va, int n)
{
    if (W == 0 || n == 0)
        return 0;

    if (wt[n - 1] <= W)
    {
        return max(knapsackRecursive(W, wt, va, n - 1), knapsackRecursive(W - wt[n - 1], wt, va, n - 1) + va[n - 1]);
    }
    else
    {
        return knapsackRecursive(W, wt, va, n - 1);
    }
}

int knapsackMemo(int W, vector<int> wt, vector<int> va, int n, vector<vector<int>> K)
{
    if (n == 0 || W == 0)
        return 0;

    if (K[n][W] != -1)
        return K[n][W];

    if (wt[n - 1] <= W)
    {
        K[n][W] = max(knapsackMemo(W, wt, va, n - 1, K), knapsackMemo(W - wt[n - 1], wt, va, n - 1, K) + va[n - 1]);
        return K[n][W];
    }
    else
    {
        K[n][W] = knapsackMemo(W, wt, va, n - 1, K);
        return K[n][W];
    }
}

int knapsackTab(int W, vector<int> wt, vector<int> va, int n)
{
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                K[i][j] = max(va[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    return K[n][W];
}

int knapsackOpt(int W, vector<int> wt, vector<int> va, int n)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                curr[j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                curr[j] = max(va[i - 1] + prev[j - wt[i - 1]], prev[j]);
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[W];
}

int main()
{
    vector<int> val = {10, 20, 50, 60};
    vector<int> wt = {2, 3, 4, 5};
    int W = 8;
    int n = val.size();
    vector<vector<int>> K(n + 1, vector<int>(W + 1, -1));

    // cout << "Maximum value (Recursive): " << knapsackRecursive(W, wt, val, n) << endl;
    // cout << "Maximum value (Memo): " << knapsackMemo(W, wt, val, n, K) << endl;
    // cout << "Maximum value (Tab): " << knapsackTab(W, wt, val, n) << endl;
    cout << "Maximum value (Space Opt): " << knapsackOpt(W, wt, val, n) << endl;

    return 0;
}