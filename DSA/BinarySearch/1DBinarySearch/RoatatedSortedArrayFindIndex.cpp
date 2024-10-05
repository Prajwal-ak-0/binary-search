#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the index of a target value in a rotated sorted array.

Approach:
1. Use binary search with modifications to handle the rotation.
2. Adjust pointers based on comparisons with the target.

Time Complexity: O(log n) in the average case, O(n) in the worst case due to duplicates.
Space Complexity: O(1)
*/

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (nums[m] == target)
            return m;
        if (nums[s] == nums[m] && nums[m] == nums[e]) {
            s++;
            e--;
        } else if (nums[s] <= nums[m]) {
            if (nums[s] <= target && nums[m] >= target)
                e = m - 1;
            else
                s = m + 1;
        } else {
            if (target >= nums[m] && nums[e] >= target)
                s = m + 1;
            else
                e = m - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);

    // Test case explanation:
    // Vector: [4, 5, 6, 7, 0, 1, 2]
    // Target: 0
    // The target 0 is present at index 4.
    // Expected output: 4

    cout << "The target " << target << " is at index " << result << " in the array." << endl;

    return 0;
}