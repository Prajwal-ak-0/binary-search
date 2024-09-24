#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the index where the target should be inserted in a sorted vector.

Approach:
1. Use binary search.
2. Adjust pointers based on comparison with target.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int searchInsert(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1, m, res = nums.size();

    while (s <= e) {
        m = s + (e - s) / 2;

        if (nums[m] == target)
            return m;
        else if (nums[m] < target)
            s = m + 1;
        else {
            res = m;
            e = m - 1;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    
    int index = searchInsert(nums, target);
    
    // Test case explanation:
    // Vector: [1, 3, 5, 6]
    // Target: 5
    // The target 5 is found at index 2.
    // Expected output: 2
    
    cout << "The target " << target << " should be inserted at index " << index << endl;
    
    return 0;
}