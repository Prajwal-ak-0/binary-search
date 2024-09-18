#include <iostream>
#include <vector>
using namespace std;

// Function to find all elements that appear more than ⌊n/3⌋ times
// Idea: Use the Boyer-Moore Voting Algorithm to find up to two candidates that could be the majority elements.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used except for a few variables.
vector<int> majorityElement(vector<int>& nums) {
    int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;

    // First pass: Find potential candidates
    for (int num : nums) {
        if (cnt1 == 0 && cand2 != num) {
            cnt1 = 1;
            cand1 = num;
        } else if (cnt2 == 0 && cand1 != num) {
            cnt2 = 1;
            cand2 = num;
        } else if (num == cand1)
            cnt1++;
        else if (num == cand2)
            cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Second pass: Verify the candidates
    cnt1 = 0, cnt2 = 0;
    for (int num : nums) {
        if (cand1 == num) cnt1++;
        else if (cand2 == num) cnt2++;
    }

    vector<int> ans;
    if (cnt1 > nums.size() / 3) ans.push_back(cand1);
    if (cnt2 > nums.size() / 3) ans.push_back(cand2);

    return ans;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> nums3 = {1};
    vector<int> nums4 = {1, 2};

    vector<int> result1 = majorityElement(nums1);
    vector<int> result2 = majorityElement(nums2);
    vector<int> result3 = majorityElement(nums3);
    vector<int> result4 = majorityElement(nums4);

    cout << "Test Case 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl; // Expected Output: 3

    cout << "Test Case 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl; // Expected Output: 1 2

    cout << "Test Case 3: ";
    for (int num : result3) cout << num << " ";
    cout << endl; // Expected Output: 1

    cout << "Test Case 4: ";
    for (int num : result4) cout << num << " ";
    cout << endl; // Expected Output: 1 2

    return 0;
}

/*
Test Cases:
1. Input: nums = {3, 2, 3}
   Expected Output: 3
   Explanation: The element 3 appears more than ⌊3/3⌋ = 1 times.

2. Input: nums = {1, 1, 1, 3, 3, 2, 2, 2}
   Expected Output: 1 2
   Explanation: The elements 1 and 2 appear more than ⌊8/3⌋ = 2 times.

3. Input: nums = {1}
   Expected Output: 1
   Explanation: The element 1 appears more than ⌊1/3⌋ = 0 times.

4. Input: nums = {1, 2}
   Expected Output: 1 2
   Explanation: The elements 1 and 2 appear more than ⌊2/3⌋ = 0 times.
*/