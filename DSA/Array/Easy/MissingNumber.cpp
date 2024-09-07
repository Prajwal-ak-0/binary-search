#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Approach 1: Using sum formula to find the missing number
// Idea: Calculate the expected sum of the first n natural numbers and subtract the actual sum of the array elements.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int missingNumberSum(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

// Approach 2: Using a set to find the missing number
// Idea: Insert all elements of the array into a set and then check for the missing number from 0 to n.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the set.
int missingNumberSet(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int i = 0; i <= n; ++i) {
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 0, 1};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    vector<int> nums4 = {0};

    // Using sum formula approach
    cout << "Using Sum Formula Approach:" << endl;
    cout << "Test Case 1: " << missingNumberSum(nums1) << endl; // Expected Output: 2
    cout << "Test Case 2: " << missingNumberSum(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << missingNumberSum(nums3) << endl; // Expected Output: 8
    cout << "Test Case 4: " << missingNumberSum(nums4) << endl; // Expected Output: 1

    // Using set approach
    cout << "Using Set Approach:" << endl;
    cout << "Test Case 1: " << missingNumberSet(nums1) << endl; // Expected Output: 2
    cout << "Test Case 2: " << missingNumberSet(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << missingNumberSet(nums3) << endl; // Expected Output: 8
    cout << "Test Case 4: " << missingNumberSet(nums4) << endl; // Expected Output: 1

    return 0;
}

/*
Test Cases:
1. Input: nums = {3, 0, 1}
   Expected Output: 2
   Explanation: The missing number is 2.

2. Input: nums = {0, 1}
   Expected Output: 2
   Explanation: The missing number is 2.

3. Input: nums = {9,6,4,2,3,5,7,0,1}
   Expected Output: 8
   Explanation: The missing number is 8.

4. Input: nums = {0}
   Expected Output: 1
   Explanation: The missing number is 1.
*/