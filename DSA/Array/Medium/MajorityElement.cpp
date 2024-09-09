#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Using a hash map to find the majority element
// Idea: Count the occurrences of each element using a hash map and find the element with the maximum count.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the hash map.
int majorityElementHashMap(const vector<int>& nums) {
    unordered_map<int, int> countMap;
    
    // Count the occurrences of each element
    for (int num : nums) {
        countMap[num]++;
    }
    
    // Find the element with the maximum count
    int majorityElement = 0;
    int maxCount = 0;
    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            majorityElement = pair.first;
        }
    }
    
    return majorityElement;
}

// Approach 2: Using Boyer-Moore Voting Algorithm to find the majority element
// Idea: Maintain a candidate and a count. If the count is 0, update the candidate. If the current element is the candidate, increment the count, otherwise decrement it.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int majorityElementBoyerMoore(const vector<int>& nums) {
    int candidate = 0;
    int count = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    return candidate;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums3 = {1, 1, 1, 1, 2, 2, 2};
    vector<int> nums4 = {1};

    // Using hash map approach
    cout << "Using Hash Map Approach:" << endl;
    cout << "Test Case 1: " << majorityElementHashMap(nums1) << endl; // Expected Output: 3
    cout << "Test Case 2: " << majorityElementHashMap(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << majorityElementHashMap(nums3) << endl; // Expected Output: 1
    cout << "Test Case 4: " << majorityElementHashMap(nums4) << endl; // Expected Output: 1

    // Using Boyer-Moore Voting Algorithm approach
    cout << "Using Boyer-Moore Voting Algorithm Approach:" << endl;
    cout << "Test Case 1: " << majorityElementBoyerMoore(nums1) << endl; // Expected Output: 3
    cout << "Test Case 2: " << majorityElementBoyerMoore(nums2) << endl; // Expected Output: 2
    cout << "Test Case 3: " << majorityElementBoyerMoore(nums3) << endl; // Expected Output: 1
    cout << "Test Case 4: " << majorityElementBoyerMoore(nums4) << endl; // Expected Output: 1

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