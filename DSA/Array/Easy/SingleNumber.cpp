#include <iostream>
#include <vector>
using namespace std;

// Function to find the single number in an array where every element appears twice except for one
// Idea: Use XOR operation to find the single number. XOR of a number with itself is 0 and XOR of a number with 0 is the number itself.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int n : nums) {
        res = n ^ res;
    }
    return res;
}

int main() {
    // Example test cases
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};
    vector<int> nums4 = {0, 1, 0};

    cout << "Test Case 1: " << singleNumber(nums1) << endl; // Expected Output: 1
    cout << "Test Case 2: " << singleNumber(nums2) << endl; // Expected Output: 4
    cout << "Test Case 3: " << singleNumber(nums3) << endl; // Expected Output: 1
    cout << "Test Case 4: " << singleNumber(nums4) << endl; // Expected Output: 1

    return 0;
}

/*
Test Cases:
1. Input: nums = {2, 2, 1}
   Expected Output: 1
   Explanation: The single number is 1.

2. Input: nums = {4, 1, 2, 1, 2}
   Expected Output: 4
   Explanation: The single number is 4.

3. Input: nums = {1}
   Expected Output: 1
   Explanation: The single number is 1.

4. Input: nums = {0, 1, 0}
   Expected Output: 1
   Explanation: The single number is 1.
*/