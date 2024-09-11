#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange the array with alternating positive and negative numbers
// Idea: Use two separate vectors to store positive and negative numbers, then merge them alternately.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the result vector.
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int n : nums) {
        if (n > 0)
            pos.push_back(n);
        else
            neg.push_back(n);
    }

    vector<int> res;
    // Merge positive and negative numbers alternately
    for (int i = 0; i < pos.size(); i++) {
        res.push_back(pos[i]);
        res.push_back(neg[i]);
    }

    return res;
}

// Function to rearrange the array with alternating positive and negative numbers using in-place approach
// Idea: Use two pointers to place positive and negative numbers at the correct positions in the result array.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the result vector.
vector<int> rearrangeArrayInPlace(vector<int>& nums) {
    int n = nums.size(), pI = 0, nI = 1;
    vector<int> res(n);
    
    // Place positive and negative numbers at the correct positions
    for (int nm : nums) {
        if (nm > 0) {
            res[pI] = nm;
            pI += 2;
        } else {
            res[nI] = nm;
            nI += 2;
        }
    }

    return res;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    vector<int> nums2 = {-1, 1};
    vector<int> nums3 = {1, -1, 2, -2, 3, -3};
    vector<int> nums4 = {-1, -2, -3, 1, 2, 3};

    cout << "Using Separate Vectors Approach:" << endl;
    vector<int> res1 = rearrangeArray(nums1);
    for (int num : res1) cout << num << " ";
    cout << endl;

    vector<int> res2 = rearrangeArray(nums2);
    for (int num : res2) cout << num << " ";
    cout << endl;

    vector<int> res3 = rearrangeArray(nums3);
    for (int num : res3) cout << num << " ";
    cout << endl;

    vector<int> res4 = rearrangeArray(nums4);
    for (int num : res4) cout << num << " ";
    cout << endl;

    cout << "Using In-Place Approach:" << endl;
    res1 = rearrangeArrayInPlace(nums1);
    for (int num : res1) cout << num << " ";
    cout << endl;

    res2 = rearrangeArrayInPlace(nums2);
    for (int num : res2) cout << num << " ";
    cout << endl;

    res3 = rearrangeArrayInPlace(nums3);
    for (int num : res3) cout << num << " ";
    cout << endl;

    res4 = rearrangeArrayInPlace(nums4);
    for (int num : res4) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: nums = {3, 1, -2, -5, 2, -4}
   Expected Output: {3, -2, 1, -5, 2, -4}
   Explanation: The array is rearranged with alternating positive and negative numbers.

2. Input: nums = {-1, 1}
   Expected Output: {1, -1}
   Explanation: The array is rearranged with alternating positive and negative numbers.

3. Input: nums = {1, -1, 2, -2, 3, -3}
   Expected Output: {1, -1, 2, -2, 3, -3}
   Explanation: The array is rearranged with alternating positive and negative numbers.

4. Input: nums = {-1, -2, -3, 1, 2, 3}
   Expected Output: {1, -1, 2, -2, 3, -3}
   Explanation: The array is rearranged with alternating positive and negative numbers.
*/