#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Space optimized approach for a subarray
// Idea: Use two variables to keep track of the maximum amount of money that can be robbed up to the previous two houses in the subarray.
// Time Complexity: O(n), where n is the number of houses in the subarray.
// Space Complexity: O(1), as only two variables are used.
int solve(vector<int>& nums, int st, int ed) {
    if (st == ed) return nums[st];

    int prev_1 = nums[st];
    int prev_2 = 0;
    int curr = 0;

    for (int i = st + 1; i <= ed; i++) {
        int step_2 = prev_2 + nums[i];
        int step_1 = prev_1;

        curr = max(step_2, step_1);

        prev_2 = prev_1;
        prev_1 = curr;
    }

    return curr;
}

// Main function to solve the House Robber II problem
// Idea: Since the houses are in a circle, we need to consider two cases:
//       1. Rob houses from index 1 to n-1 (excluding the first house).
//       2. Rob houses from index 0 to n-2 (excluding the last house).
// Time Complexity: O(n), where n is the number of houses.
// Space Complexity: O(1), as only two variables are used in the solve function.
int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    return max(solve(nums, 1, n - 1), solve(nums, 0, n - 2));
}

int main() {
    vector<int> nums = {2, 3, 2};

    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;

    return 0;
}