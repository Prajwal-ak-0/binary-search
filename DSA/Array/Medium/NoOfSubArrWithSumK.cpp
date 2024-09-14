#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of subarrays with a sum equal to k
// Idea: Use a nested loop to check all possible subarrays and count those with a sum equal to k.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;

    vector<int> nums3 = {1, -1, 1, -1, 1};
    int k3 = 0;

    vector<int> nums4 = {3, 4, 7, 2, -3, 1, 4, 2};
    int k4 = 7;

    cout << "Test Case 1: Number of Subarrays = " << subarraySum(nums1, k1) << endl; // Expected Output: 2
    cout << "Test Case 2: Number of Subarrays = " << subarraySum(nums2, k2) << endl; // Expected Output: 2
    cout << "Test Case 3: Number of Subarrays = " << subarraySum(nums3, k3) << endl; // Expected Output: 4
    cout << "Test Case 4: Number of Subarrays = " << subarraySum(nums4, k4) << endl; // Expected Output: 4

    return 0;
}

/*
Test Cases:
1. Input: nums = {1, 1, 1}, k = 2
   Expected Output: 2
   Explanation: The subarrays with sum equal to 2 are [1, 1] and [1, 1].

2. Input: nums = {1, 2, 3}, k = 3
   Expected Output: 2
   Explanation: The subarrays with sum equal to 3 are [1, 2] and [3].

3. Input: nums = {1, -1, 1, -1, 1}, k = 0
   Expected Output: 4
   Explanation: The subarrays with sum equal to 0 are [1, -1], [-1, 1], [1, -1], and [1, -1, 1, -1].

4. Input: nums = {3, 4, 7, 2, -3, 1, 4, 2}, k = 7
   Expected Output: 4
   Explanation: The subarrays with sum equal to 7 are [3, 4], [7], [7, 2, -3, 1], and [1, 4, 2].
*/