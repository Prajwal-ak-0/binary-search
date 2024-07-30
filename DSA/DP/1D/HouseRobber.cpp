    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    // Memoization approach
    // Idea: Use a memoization array to store the results of subproblems to avoid redundant calculations.
    // Time Complexity: O(n), where n is the number of houses.
    // Space Complexity: O(n), for storing the memo array.
    int solveMemo(vector<int>& nums, int n, vector<int>& memo) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);

        if (memo[n] != -1) return memo[n];

        int rob_1 = solveMemo(nums, n - 2, memo) + nums[n];
        int rob_2 = solveMemo(nums, n - 1, memo);

        return memo[n] = max(rob_1, rob_2);
    }

    int robMemo(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> memo(n, -1);
        return solveMemo(nums, n - 1, memo);
    }

    // Tabulation approach
    // Idea: Use a DP array to iteratively store the maximum amount of money that can be robbed up to each house.
    // Time Complexity: O(n), where n is the number of houses.
    // Space Complexity: O(n), for storing the DP array.
    int robTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for (int i = 2; i < n; i++) {
            int step_2 = dp[i - 2] + nums[i];
            int step_1 = dp[i - 1];
            dp[i] = max(step_1, step_2);
        }

        return dp[n - 1];
    }

    // Space optimized approach
    // Idea: Use two variables to keep track of the maximum amount of money that can be robbed up to the previous two houses.
    // Time Complexity: O(n), where n is the number of houses.
    // Space Complexity: O(1), as only two variables are used.
    int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int prev_1 = max(nums[0], nums[1]);
        int prev_2 = nums[0];
        int curr;
        for (int i = 2; i < n; i++) {
            int step_2 = prev_2 + nums[i];
            int step_1 = prev_1;
            curr = max(step_2, step_1);
            prev_2 = prev_1;
            prev_1 = curr;
        }

        return curr;
    }

    int main() {
        vector<int> nums = {2, 7, 9, 3, 1};

        cout << "Memoization approach: " << robMemo(nums) << endl;
        cout << "Tabulation approach: " << robTab(nums) << endl;
        cout << "Space optimized approach: " << robSpaceOptimized(nums) << endl;

        return 0;
    }