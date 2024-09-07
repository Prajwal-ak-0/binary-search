#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeroes to the end of the array
// Idea: Use two pointers to keep track of the current element and the position to place the next non-zero element.
// Approach: Iterate through the array with one pointer (j) and use another pointer (i) to place the non-zero elements at the beginning of the array.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;

    while (j < nums.size()) {
        if (nums[j] != 0) {
            swap(nums[i++], nums[j++]);
        } else {
            j++;
        }
    }
}

int main() {
    // Example test cases
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 0, 1};
    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> nums4 = {0, 0, 0, 0, 0};

    moveZeroes(nums1);
    moveZeroes(nums2);
    moveZeroes(nums3);
    moveZeroes(nums4);

    cout << "Test Case 1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Test Case 2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Test Case 3: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Test Case 4: ";
    for (int num : nums4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: nums = {0, 1, 0, 3, 12}
   Expected Output: {1, 3, 12, 0, 0}
   Explanation: The zeroes are moved to the end of the array.

2. Input: nums = {0, 0, 1}
   Expected Output: {1, 0, 0}
   Explanation: The zeroes are moved to the end of the array.

3. Input: nums = {1, 2, 3, 4, 5}
   Expected Output: {1, 2, 3, 4, 5}
   Explanation: There are no zeroes in the array, so the array remains unchanged.

4. Input: nums = {0, 0, 0, 0, 0}
   Expected Output: {0, 0, 0, 0, 0}
   Explanation: All elements are zeroes, so the array remains unchanged.
*/