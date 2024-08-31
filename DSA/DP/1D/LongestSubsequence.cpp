#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Dynamic Programming Approach
// Idea: Use a DP array to store the length of the longest increasing subsequence ending at each index.
// Approach: For each element, check all previous elements and update the DP array if a longer subsequence can be formed.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(n), for storing the DP array.
int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) return nums.size();

    vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int mx = 0;
    for (int i = 0; i < dp.size(); i++) {
        mx = max(mx, dp[i]);
    }

    return mx;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}

/*
Test Case:
Input: nums = {10, 9, 2, 5, 3, 7, 101, 18}
Expected Output: 4
Explanation: The longest increasing subsequence is {2, 3, 7, 101}, which has length 4.
*/