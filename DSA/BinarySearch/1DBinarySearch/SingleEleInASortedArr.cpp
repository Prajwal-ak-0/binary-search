#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the single element in a sorted array where every other element appears exactly twice.

Approach:
1. Use binary search to find the single element.
2. Adjust pointers based on comparisons with adjacent elements.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int singleNonDuplicate(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;

    while (s < e) {
        int m = s + (e - s) / 2;

        if (m % 2 == 1)
            m--;

        if (nums[m] == nums[m + 1])
            s = m + 2;
        else
            e = m;
    }

    return nums[s];
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int singleElement = singleNonDuplicate(nums);

    // Test case explanation:
    // Vector: [1, 1, 2, 3, 3, 4, 4, 8, 8]
    // The single element in the sorted array is 2.
    // Expected output: 2

    cout << "The single element in the sorted array is " << singleElement << endl;

    return 0;
}