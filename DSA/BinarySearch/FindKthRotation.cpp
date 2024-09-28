#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the index of the smallest element in a rotated sorted array, which indicates the number of rotations.

Approach 1:
1. Use binary search to find the pivot point where the rotation happens.
2. Adjust pointers based on comparisons with the end element.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findKRotation(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    if (arr[left] <= arr[right]) {
        return 0;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }

        if (arr[left] <= arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}

/*
Idea: Find the index of the smallest element in a rotated sorted array, which indicates the number of rotations.

Approach 2:
1. Use binary search to find the minimum element.
2. The index of the minimum element is the number of rotations.

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

    return s;
}

int findKRotationUsingMin(vector<int>& nums) {
    int minIndex = findMin(nums);
    return minIndex;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};

    int k1 = findKRotation(arr);
    int k2 = findKRotationUsingMin(arr);

    // Test case explanation:
    // Vector: [15, 18, 2, 3, 6, 12]
    // The smallest element is 2, which is at index 2.
    // The array is rotated 2 times.
    // Expected output: 2

    cout << "Using first approach, the array is rotated " << k1 << " times." << endl;
    cout << "Using second approach, the array is rotated " << k2 << " times." << endl;

    return 0;
}