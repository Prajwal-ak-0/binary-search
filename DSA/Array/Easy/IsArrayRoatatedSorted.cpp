#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted and rotated
// Idea: Count the number of times the next element is smaller than the current element.
// Approach: Iterate through the array and check if the next element is smaller than the current element.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
bool check(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[(i + 1) % nums.size()] < nums[i]) {
            count++;
        }
        if (count > 1) return false;
    }
    return true;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> nums4 = {1, 1, 1};

    cout << "Test Case 1: " << (check(nums1) ? "True" : "False") << endl; // Expected Output: True
    cout << "Test Case 2: " << (check(nums2) ? "True" : "False") << endl; // Expected Output: False
    cout << "Test Case 3: " << (check(nums3) ? "True" : "False") << endl; // Expected Output: True
    cout << "Test Case 4: " << (check(nums4) ? "True" : "False") << endl; // Expected Output: True

    return 0;
}

/*
Test Cases:
1. Input: nums = {3, 4, 5, 1, 2}
   Expected Output: True
   Explanation: The array is sorted and rotated.

2. Input: nums = {2, 1, 3, 4}
   Expected Output: False
   Explanation: The array is not sorted and rotated.

3. Input: nums = {1, 2, 3, 4, 5}
   Expected Output: True
   Explanation: The array is sorted and not rotated.

4. Input: nums = {1, 1, 1}
   Expected Output: True
   Explanation: The array is sorted and not rotated.
*/