#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find a peak element in the array. A peak element is an element that is greater than its neighbors.

Approach:
1. Check edge cases for the first and last elements.
2. Use binary search to find a peak element in the middle of the array.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int s = 1, e = n - 2;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (nums[m - 1] < nums[m] && nums[m + 1] < nums[m])
            return m;
        else if (nums[m - 1] < nums[m])
            s = m + 1;
        else
            e = m - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    int peakIndex = findPeakElement(nums);

    // Test case explanation:
    // Vector: [1, 2, 3, 1]
    // The peak element is 3, which is at index 2.
    // Expected output: 2

    cout << "The peak element is at index " << peakIndex << endl;

    return 0;
}