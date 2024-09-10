#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the majority element using Boyer-Moore Voting Algorithm
// Idea: Maintain a candidate and a count. If the count is 0, update the candidate. If the current element is the candidate, increment the count, otherwise decrement it.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int majorityElement(vector<int>& nums) {
    int cand = 0, count = 0;

    for (int num : nums) {
        if (count == 0) {
            cand = num;
        }

        if (num == cand)
            count++;
        else
            count--;
    }

    return cand;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums3 = {1, 1, 1, 1, 2, 2, 2};
    vector<int> nums4 = {1};

    cout << "Test Case 1: " << majorityElement(nums1) << endl; // Expected Output: 3
    cout << "Test Case 2: " << majorityElement(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << majorityElement(nums3) << endl; // Expected Output: 1
    cout << "Test Case 4: " << majorityElement(nums4) << endl; // Expected Output: 1

    return 0;
}

/*
Test Cases:
1. Input: nums = {3, 2, 3}
   Expected Output: 3
   Explanation: The majority element is 3.

2. Input: nums = {2, 2, 1, 1, 1, 2, 2}
   Expected Output: 2
   Explanation: The majority element is 2.

3. Input: nums = {1, 1, 1, 1, 2, 2, 2}
   Expected Output: 1
   Explanation: The majority element is 1.

4. Input: nums = {1}
   Expected Output: 1
   Explanation: The majority element is 1.
*/