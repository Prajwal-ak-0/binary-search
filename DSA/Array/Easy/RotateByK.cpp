#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Rotate the array by one element k times
// Idea: Rotate the array by one element k times using a helper function.
// Time Complexity: O(n * k), where n is the number of elements in the array and k is the number of rotations.
// Space Complexity: O(1), as no extra space is used.
void solve(vector<int>& nums) {
    int temp = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i > 0; i--) {
        nums[i] = nums[i - 1];
    }
    nums[0] = temp;
}

void rotateByOne(vector<int>& nums, int k) {
    for (int i = 0; i < k; i++) solve(nums);
}

// Approach 2: Rotate the array using reversal
// Idea: Reverse the entire array, then reverse the first k elements, and finally reverse the remaining elements.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
void reverse(vector<int>& nums, int st, int ed) {
    while (st < ed) {
        int temp = nums[st];
        nums[st] = nums[ed];
        nums[ed] = temp;
        st++;
        ed--;
    }
}

void rotateByReversal(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    // Using rotate by one approach
    rotateByOne(nums1, k);
    cout << "Using Rotate by One Approach:" << endl;
    cout << "Array after " << k << " rotations: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Using reversal approach
    rotateByReversal(nums2, k);
    cout << "Using Reversal Approach:" << endl;
    cout << "Array after " << k << " rotations: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3
   Expected Output: Array after 3 rotations: {5, 6, 7, 1, 2, 3, 4}
   Explanation: The array after rotating 3 times is {5, 6, 7, 1, 2, 3, 4}.

2. Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 10
   Expected Output: Array after 10 rotations: {5, 6, 7, 1, 2, 3, 4}
   Explanation: The array after rotating 10 times (equivalent to 3 times) is {5, 6, 7, 1, 2, 3, 4}.
*/