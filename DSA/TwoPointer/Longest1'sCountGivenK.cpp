#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Idea: Find the longest subarray with at most k 0s.

Approach:
1. Use a sliding window approach with two pointers `i` and `j`.
2. Traverse the array with the right pointer `j`.
3. If the current element is 0, increment the `zero_count`.
4. If the `zero_count` exceeds k, move the left pointer `i` to the right until the `zero_count` is less than or equal to k.
5. Update the maximum length of the subarray.
6. Return the maximum length.

Time Complexity: O(n) - We traverse the array once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0, mx = 0, zero_count = 0;

    while (j < nums.size()) {
        if (nums[j] == 0)
            zero_count++;

        while (zero_count > k)
            if (nums[i++] == 0)
                zero_count--;

        mx = max(mx, j - i + 1);
        j++;
    }

    return mx;
}

int main() {
    // Test case 1: nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
    // Explanation: The longest subarray with at most 2 0s is [1, 1, 1, 0, 0, 1, 1, 1, 1], which has length 9.
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Longest subarray with at most " << k1 << " 0s: " << longestOnes(nums1, k1) << endl;

    // Test case 2: nums = [0, 0, 1, 1, 1, 0, 0], k = 0
    // Explanation: The longest subarray with at most 0 0s is [1, 1, 1], which has length 3.
    vector<int> nums2 = {0, 0, 1, 1, 1, 0, 0};
    int k2 = 0;
    cout << "Longest subarray with at most " << k2 << " 0s: " << longestOnes(nums2, k2) << endl;

    // Test case 3: nums = [1, 1, 1, 1, 1], k = 1
    // Explanation: The longest subarray with at most 1 0s is [1, 1, 1, 1, 1], which has length 5.
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 1;
    cout << "Longest subarray with at most " << k3 << " 0s: " << longestOnes(nums3, k3) << endl;

    // Test case 4: nums = [0, 0, 0, 0], k = 2
    // Explanation: The longest subarray with at most 2 0s is [0, 0], which has length 2.
    vector<int> nums4 = {0, 0, 0, 0};
    int k4 = 2;
    cout << "Longest subarray with at most " << k4 << " 0s: " << longestOnes(nums4, k4) << endl;

    return 0;
}