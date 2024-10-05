#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the minimum element in a rotated sorted array.

Approach:
1. Use binary search to find the pivot point where the rotation happens.
2. Adjust pointers based on comparisons with the end element.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;

    while (s < e) {
        int m = s + (e - s) / 2;

        if (nums[m] > nums[e]) s = m + 1;
        else e = m;
    }

    return nums[s];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int minElement = findMin(nums);

    // Test case explanation:
    // Vector: [4, 5, 6, 7, 0, 1, 2]
    // The minimum element in the rotated sorted array is 0.
    // Expected output: 0

    cout << "The minimum element in the rotated sorted array is " << minElement << endl;

    return 0;
}