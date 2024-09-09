#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two numbers that add up to a specific target
// Idea: Use a hash map to store the difference between the target and the current element as the key and the index as the value.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the hash map.
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // To store the difference and index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // Calculate the complement
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return the indices if complement is found
        }
        numMap[nums[i]] = i; // Store the index of the current element
    }

    return {}; // Return an empty vector if no solution is found
}

int main() {
    // Example test cases
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> nums3 = {3, 3};
    int target3 = 6;

    vector<int> result1 = twoSum(nums1, target1);
    vector<int> result2 = twoSum(nums2, target2);
    vector<int> result3 = twoSum(nums3, target3);

    cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]" << endl; // Expected Output: [0, 1]
    cout << "Test Case 2: [" << result2[0] << ", " << result2[1] << "]" << endl; // Expected Output: [1, 2]
    cout << "Test Case 3: [" << result3[0] << ", " << result3[1] << "]" << endl; // Expected Output: [0, 1]

    return 0;
}

/*
Test Cases:
1. Input: nums = {2, 7, 11, 15}, target = 9
   Expected Output: [0, 1]
   Explanation: The numbers at indices 0 and 1 add up to 9.

2. Input: nums = {3, 2, 4}, target = 6
   Expected Output: [1, 2]
   Explanation: The numbers at indices 1 and 2 add up to 6.

3. Input: nums = {3, 3}, target = 6
   Expected Output: [0, 1]
   Explanation: The numbers at indices 0 and 1 add up to 6.
*/