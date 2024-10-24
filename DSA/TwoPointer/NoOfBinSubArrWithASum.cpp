#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Idea: Find the number of subarrays with a given sum.

Approach:
1. Use a nested loop to iterate through all possible subarrays.
2. For each subarray, calculate the sum.
3. If the sum equals the goal, increment the count.
4. Return the count.

Time Complexity: O(n^2) - We traverse all possible subarrays.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt = 0;
    int i = 0, j = 0;

    while (i < nums.size()) {
        int sum = 0;
        j = i;
        while (j < nums.size()) {
            sum += nums[j];
            if (sum == goal) cnt++;
            j++;
        }
        i++;
    }

    return cnt;
}

int main() {
    // Test case 1: nums = [1, 0, 1, 0, 1], goal = 2
    // Explanation: The subarrays with sum 2 are [1, 0, 1], [0, 1, 0, 1], and [1, 0, 1].
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Number of subarrays with sum " << goal1 << ": " << numSubarraysWithSum(nums1, goal1) << endl;

    // Test case 2: nums = [0, 0, 0, 0, 0], goal = 0
    // Explanation: All subarrays have sum 0.
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Number of subarrays with sum " << goal2 << ": " << numSubarraysWithSum(nums2, goal2) << endl;

    // Test case 3: nums = [1, 1, 1, 1, 1], goal = 3
    // Explanation: The subarrays with sum 3 are [1, 1, 1], [1, 1, 1], and [1, 1, 1].
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int goal3 = 3;
    cout << "Number of subarrays with sum " << goal3 << ": " << numSubarraysWithSum(nums3, goal3) << endl;

    // Test case 4: nums = [1, 2, 3, 4, 5], goal = 5
    // Explanation: The subarrays with sum 5 are [2, 3] and [5].
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int goal4 = 5;
    cout << "Number of subarrays with sum " << goal4 << ": " << numSubarraysWithSum(nums4, goal4) << endl;

    return 0;
}