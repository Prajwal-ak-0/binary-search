#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum number of consecutive 1s in a binary array
// Idea: Use a sliding window approach to count the maximum number of consecutive 1s.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int findMaxConsecutiveOnes(vector<int>& nums) {
    int i = 0, j = 0, count = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] == 1) {
            count = max(count, j - i + 1);
        } else {
            i = j + 1;
        }
    }
    return count;
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    vector<int> nums3 = {0, 0, 0, 0, 0};
    vector<int> nums4 = {1, 1, 1, 1, 1};

    cout << "Test Case 1: " << findMaxConsecutiveOnes(nums1) << endl; // Expected Output: 3
    cout << "Test Case 2: " << findMaxConsecutiveOnes(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << findMaxConsecutiveOnes(nums3) << endl; // Expected Output: 0
    cout << "Test Case 4: " << findMaxConsecutiveOnes(nums4) << endl; // Expected Output: 5

    return 0;
}

/*
Test Cases:
1. Input: nums = {1, 1, 0, 1, 1, 1}
   Expected Output: 3
   Explanation: The maximum number of consecutive 1s is 3.

2. Input: nums = {1, 0, 1, 1, 0, 1}
   Expected Output: 2
   Explanation: The maximum number of consecutive 1s is 2.

3. Input: nums = {0, 0, 0, 0, 0}
   Expected Output: 0
   Explanation: There are no 1s in the array.

4. Input: nums = {1, 1, 1, 1, 1}
   Expected Output: 5
   Explanation: The maximum number of consecutive 1s is 5.
*/