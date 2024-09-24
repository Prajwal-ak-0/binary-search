#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the starting and ending position of a given target value in a sorted array.

Approach:
1. Use binary search to find the target.
2. Expand to the left and right to find the range.

Time Complexity: O(log n + k) where k is the number of occurrences of the target.
Space Complexity: O(1)
*/

vector<int> searchRange(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    int i = -1, j = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (nums[m] == target) {
            i = m;
            j = m;
            while (i > 0 && nums[i - 1] == target) {
                i--;
            }
            while (j < nums.size() - 1 && nums[j + 1] == target) {
                j++;
            }
            break;
        } else if (nums[m] > target) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    return {i, j};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = searchRange(nums, target);
    
    // Test case explanation:
    // Vector: [5, 7, 7, 8, 8, 10]
    // Target: 8
    // The target 8 is found from index 3 to 4.
    // Expected output: {3, 4}
    
    cout << "The target " << target << " is found from index " << result[0] << " to " << result[1] << endl;
    
    return 0;
}